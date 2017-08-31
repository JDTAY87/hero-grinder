#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "hgsdl2.h"
#include "hgtexture.h"
#include "hgmessage.h"

hgSDL2 SDL2;
hgTexture jfont2;
hgMessage title;

bool hgInit();
void hgMainLoop();
void hgUpdateScreen();

bool hgInit()
{
    bool success = true;
    if ( !SDL2.init() ) { success = false; }
    else if ( !jfont2.loadtexture( SDL2.getrenderer(), "jfont2.png" ) ) { success = false; }
    else { title.setmessage( "Hero Grinder" ); title.setfont( jfont2.gettexture() ); }
    return success;
}

void hgMainLoop()
{
    SDL_Event event;
    bool quit = false;
    while ( !quit )
    {
        while ( SDL_PollEvent(&event) )
        {
            if ( event.type == SDL_QUIT ) { quit = true; }
        }
        hgUpdateScreen();
    }
    return;
}

void hgUpdateScreen()
{
    SDL_Renderer* renderer = SDL2.getrenderer();
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
    title.render( renderer, 26, 17 );
    SDL_RenderPresent( renderer );
    return;
}

int main( int argc, char* argv[] )
{
    if ( !hgInit() ) { printf( "Initialization failed." ); }
    else { hgMainLoop(); }
    return 0;
}
