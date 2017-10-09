#include <stdio.h>
#include <string>
#include "hgsdl2.h"
#include "hgtexture.h"
#include "hgobject.h"
#include "hgmessage.h"
#include "hgmenu.h"
#include "hgscript.h"
#include "hgdata.h"
#include "hgbackground.h"
#include "hgsprite.h"
#include "hgstats.h"
#include "hgdate.h"

class hgGame
{
public:
    bool hgInit();
    void hgMainLoop();
private:
    void hgDoScript( int scriptno, int location );
    void hgUpdateScreen();
    hgSDL2 SDL2;
    hgTexture jfont2;
    hgTexture hgbg01;
    hgTexture hgbg02;
    hgTexture hgcowboy;
    hgData maindata;
    hgBackground background;
    hgSprite herospr;
    hgMessage msg1;
    hgMessage msg2;
    hgMenu menu1;
    hgMenu menu2;
    hgDate gamedate;
    hgStats herostats;
    hgScript script;
};

bool hgGame::hgInit()
{
    bool success = true;
    if ( !SDL2.init() ) { success = false; }
    else if ( !jfont2.loadtexture( SDL2.getrenderer(), "jfont2.png" ) ) { success = false; }
    else if ( !hgbg01.loadtexture( SDL2.getrenderer(), "hgbg01.png" ) ) { success = false; }
    else if ( !hgbg02.loadtexture( SDL2.getrenderer(), "hgbg02.png" ) ) { success = false; }
    else if ( !hgcowboy.loadtexture( SDL2.getrenderer(), "hgcowboy.png" ) ) { success = false; }
    else
    {
        background.settexture( 0, jfont2.gettexture() );
        background.settexture( 1, hgbg01.gettexture() );
        background.settexture( 2, hgbg02.gettexture() );
        background.settexture( 3, hgcowboy.gettexture() );
    }
    return success;
}

void hgGame::hgMainLoop()
{
    hgMenu* menus[] = { &menu1, &menu2 };
    SDL_Event event;
    bool quit = false;
    bool fullscreen = false;
    bool paused = false;
    bool scripttime = true;
    bool hilighttime = true;
    int scriptloc = 5;
    while ( !quit )
    {
        while ( SDL_PollEvent(&event) )
        {
            if ( event.type == SDL_QUIT ) { quit = true; }
            else if ( event.window.event == SDL_WINDOWEVENT_MINIMIZED ) { paused = true; }
            else if ( event.type == SDL_KEYDOWN )
            {
                switch ( event.key.keysym.sym )
                {
                case SDLK_F11:
                    fullscreen = !fullscreen;
                    SDL_SetWindowFullscreen( SDL2.getwindow(), SDL_WINDOW_FULLSCREEN_DESKTOP*fullscreen );
                    break;
                case SDLK_p:
                    paused = !paused;
                    break;
                case SDLK_UP:
                    menus[maindata.getmenu()]->setcursorpos( -1 );
                    hilighttime = true;
                    break;
                case SDLK_DOWN:
                    menus[maindata.getmenu()]->setcursorpos( 1 );
                    hilighttime = true;
                    break;
                case SDLK_x:
                case SDLK_END:
                    scriptloc = menus[maindata.getmenu()]->getselection()*5;
                    scripttime = true;
                    hilighttime = true;
                    break;
                }
            }
            else if ( event.type == SDL_CONTROLLERBUTTONDOWN )
            {
                switch ( event.cbutton.button )
                {
                case SDL_CONTROLLER_BUTTON_START:
                    paused = !paused;
                    break;
                case SDL_CONTROLLER_BUTTON_DPAD_UP:
                    menus[maindata.getmenu()]->setcursorpos( -1 );
                    hilighttime = true;
                    break;
                case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                    menus[maindata.getmenu()]->setcursorpos( 1 );
                    hilighttime = true;
                    break;
                case SDL_CONTROLLER_BUTTON_A:
                    scriptloc = menus[maindata.getmenu()]->getselection()*5;
                    scripttime = true;
                    hilighttime = true;
                    break;
                }
            }
        }
        if ( scripttime == true ) { hgDoScript( maindata.getscript(), scriptloc ); scripttime = false; }
        if ( hilighttime == true )
        {
            scriptloc = menus[maindata.getmenu()]->gethilight()*5;
            hgDoScript( maindata.getscript(), scriptloc );
            hilighttime = false;
        }
        if ( maindata.quitselected() == true ) { quit = true; }
        if ( !paused ) { hgUpdateScreen(); } else { SDL_Delay( 1 ); }
    }
    return;
}

void hgGame::hgDoScript( int scriptno, int location )
{
    hgObject* scriptobjects[] = { &maindata, &background, &herospr, &msg1, &msg2, &menu1, &menu2, &gamedate, &herostats };
    int continuescript = 1;
    int scriptnumber = scriptno;
    int scriptloc = location;
    while ( continuescript != 0 )
    {
        int object = script.getscript( scriptnumber, scriptloc );
        int action = script.getscript( scriptnumber, scriptloc+1 );
        int arg1 = script.getscript( scriptnumber, scriptloc+2 );
        int arg2 = script.getscript( scriptnumber, scriptloc+3 );
        scriptobjects[object]->execute( action, arg1, arg2 );
        continuescript = script.getscript( scriptnumber, scriptloc+4 );
        if ( scriptnumber != maindata.getscript() ) { scriptnumber = maindata.getscript(); }
        else { scriptloc += 5; }
    }
    return;
}

void hgGame::hgUpdateScreen()
{
    hgObject* renderobjects[] = { &background, &herospr, &msg1, &msg2, &menu1, &menu2, &gamedate, &herostats };
    SDL_Renderer* renderer = SDL2.getrenderer();
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
    for ( int z = 0; z < 8; z++ ) { renderobjects[z]->render( renderer ); }
    SDL_RenderPresent( renderer );
    return;
}

int main( int argc, char* argv[] )
{
    hgGame herogrinder;
    if ( !herogrinder.hgInit() ) { printf( "Initialization failed." ); }
    else { herogrinder.hgMainLoop(); }
    return 0;
}
