#include <stdio.h>
#include <string>
#include "hgsdl2.h"
#include "hgtexture.h"
#include "hgobject.h"
#include "hgmsgdata.h"
#include "hgmenudata.h"
#include "hgmessage.h"
#include "hgmenu.h"
#include "hgscript.h"
#include "hgdata.h"

hgSDL2 SDL2;
hgTexture jfont2;
hgData data;
hgMsgData msgdata;
hgMenuData menudata;
hgMessage msg1( &msgdata );
hgMenu menu1( &menudata );
hgMenu menu2( &menudata );
hgObject* renderobjects[] = { &msg1, &menu1, &menu2 };
hgObject* scriptobjects[] = { &data, &msg1, &menu1, &menu2 };
hgMenu* menus[] = { &menu1, &menu2 };
hgScript script;

bool hgInit();
void hgMainLoop();
void hgDoScript( int location );
void hgUpdateScreen();

bool hgInit()
{
    bool success = true;
    if ( !SDL2.init() ) { success = false; }
    else if ( !jfont2.loadtexture( SDL2.getrenderer(), "jfont2.png" ) ) { success = false; }
    else
    {
        msg1.setfont( jfont2.gettexture() );
        menu1.setfont( jfont2.gettexture() );
        menu2.setfont( jfont2.gettexture() );
    }
    return success;
}

void hgMainLoop()
{
    SDL_Event event;
    bool quit = false;
    bool fullscreen = false;
    bool paused = false;
    bool scripttime = true;
    int scriptloc = (0);
    while ( !quit )
    {
        while ( SDL_PollEvent(&event) )
        {
            if ( event.type == SDL_QUIT ) { quit = true; }
            else if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F11 )
            {
                fullscreen = !fullscreen;
                SDL_SetWindowFullscreen( SDL2.getwindow(), SDL_WINDOW_FULLSCREEN_DESKTOP*fullscreen );
            }
            else if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p ) { paused = !paused; }
            else if ( event.window.event == SDL_WINDOWEVENT_MINIMIZED ) { paused = true; }
            else if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP )
            {
                menus[data.getmenu()]->setcursorpos( -1 );
            }
            else if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN )
            {
                menus[data.getmenu()]->setcursorpos( 1 );
            }
            else if ( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_x )
            {
                scriptloc = menus[data.getmenu()]->getselection()*5;
                scripttime = true;
            }
        }
        if ( scripttime == true ) { hgDoScript( scriptloc ); scripttime = false; }
        if ( data.quitselected() == true ) { quit = true; }
        if ( !paused ) { hgUpdateScreen(); } else { SDL_Delay( 1 ); }
    }
    return;
}

void hgDoScript( int location )
{
    int continuescript = 1;
    int scriptloc = location;
    while ( continuescript != 0 )
    {
        int object = script.getscript( scriptloc );
        int action = script.getscript( scriptloc+1 );
        int arg1 = script.getscript( scriptloc+2 );
        int arg2 = script.getscript( scriptloc+3 );
        scriptobjects[object]->execute( action, arg1, arg2 );
        continuescript = script.getscript( scriptloc+4 );
        scriptloc += 5;
    }
    return;
}

void hgUpdateScreen()
{
    SDL_Renderer* renderer = SDL2.getrenderer();
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
    for ( int z = 0; z < 3; z++ ) { renderobjects[z]->render( renderer ); }
    SDL_RenderPresent( renderer );
    return;
}

int main( int argc, char* argv[] )
{
    if ( !hgInit() ) { printf( "Initialization failed." ); }
    else { hgMainLoop(); }
    return 0;
}
