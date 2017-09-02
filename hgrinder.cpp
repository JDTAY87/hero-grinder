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
    else
    {
        title.setmessage( "Hero Grinder" );
        title.setfont( jfont2.gettexture() );
        title.setpos( 26, 17 );
    }
    return success;
}

void hgMainLoop()
{
    SDL_Event event;
    bool quit = false;
    bool fullscreen = false;
    bool paused = false;
    while ( !quit )
    {
        while ( SDL_PollEvent(&event) )
        {
            if ( event.type == SDL_QUIT ) { quit = true; }
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F11 )
            {
                fullscreen = !fullscreen;
                SDL_SetWindowFullscreen( SDL2.getwindow(), SDL_WINDOW_FULLSCREEN_DESKTOP*fullscreen );
            }
            if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p ) { paused = !paused; }
            if ( event.window.event == SDL_WINDOWEVENT_MINIMIZED ) { paused = true; }
        }
        if ( !paused ) { hgUpdateScreen(); } else { SDL_Delay( 1 ); }
    }
    return;
}

void hgUpdateScreen()
{
    SDL_Renderer* renderer = SDL2.getrenderer();
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
    title.render( renderer );
    SDL_RenderPresent( renderer );
    return;
}

int main( int argc, char* argv[] )
{
    if ( !hgInit() ) { printf( "Initialization failed." ); }
    else { hgMainLoop(); }
    return 0;
}
