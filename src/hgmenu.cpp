#include "hgmenu.h"

int hgMenu::menudata[] =
{
    10, 21, 22,
    1, 7, 17, 25, 26, 32,
    37, 33,
    1, 14, 27, 40, 53, 66, 79,
    82,
    1, 8, 9
};

int hgMenu::hilightdata[] =
{
    0, 0, 0,
    40, 45, 50, 55, 60, 65,
    0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0,
    0, 0, 0
};

const char* hgMenu::data[] =
{
    " New Game", " Credits", " Exit",
    " Train", " Rest", " City", " Events", " Status", " Exit",
    " Return", " Return",
    "  POW", "  INT", "  ACC", "  SPD", "  DEF", "  VIT", "  Back",
    " Return",
    " Fields", " Portal", " Exit"
};

hgMenu::hgMenu()
{
    currentfont = 0;
    shown = false;
    noofoptions = 0;
    cursorpos = 0;
    for ( int z = 0; z < 10; z++ )
    {
        scriptptrs[z] = 0;
        hilightptrs[z] = 0;
        options[z] = "";
    }
    return;
}

void hgMenu::loadmenu( int location, int lines )
{
    noofoptions = lines;
    for ( int z = 0; z < lines; z++ )
    {
        scriptptrs[z] = menudata[location+z];
        hilightptrs[z] = hilightdata[location+z];
        options[z] = data[location+z];
    }
    return;
}

void hgMenu::setpos( int x, int y )
{
    posx = x;
    posy = y;
    box.x = x*10-2;
    box.y = y*10-2;
    return;
}

void hgMenu::setsize( int x, int y )
{
    box.w = x*10+4;
    box.h = y*20+8;
    return;
}

void hgMenu::showmenu( int nil, int nada )
{
    shown = true;
    return;
}

void hgMenu::hidemenu( int nil, int nada )
{
    shown = false;
    cursorpos = 0;
    return;
}

void hgMenu::setcursorpos( int change )
{
    cursorpos += change;
    if ( cursorpos < 0 ) { cursorpos = noofoptions-1; }
    else if ( cursorpos > noofoptions-1 ) { cursorpos = 0; }
    return;
}

int hgMenu::getselection()
{
    return scriptptrs[ cursorpos ];
}

int hgMenu::gethilight()
{
    return hilightptrs[ cursorpos ];
}

void hgMenu::render( SDL_Renderer* renderer )
{
    if ( shown == true )
    {
        SDL_SetRenderDrawColor( renderer, 204, 153, 51, 255 );
        SDL_RenderFillRect( renderer, &box );
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
        SDL_RenderDrawRect( renderer, &box );
        SDL_Rect box2;
        box2.x = box.x+1;
        box2.y = box.y+1;
        box2.w = box.w-2;
        box2.h = box.h-2;
        SDL_RenderDrawRect( renderer, &box2 );
        SDL_Rect srcrect;
        srcrect.h = 20;
        srcrect.w = 10;
        SDL_Rect dstrect;
        dstrect.h = 20;
        dstrect.w = 10;
        for ( int z1 = 0; z1 < noofoptions; z1++ )
        {
            for ( int z2 = 0; options[z1][z2] != 0; z2++ )
            {
                if ( options[z1][z2] > 31 )
                {
                    srcrect.x = (options[z1][z2]%16)*10;
                    srcrect.y = (options[z1][z2]/16-2)*20;
                    dstrect.x = posx*10+(z2*10);
                    dstrect.y = posy*10+(z1*20);
                    SDL_RenderCopy( renderer, textures[currentfont], &srcrect, &dstrect );
                }
            }
        }
        srcrect.x = 140;
        srcrect.y = 20;
        dstrect.x = posx*10;
        dstrect.y = posy*10+(cursorpos*20);
        SDL_RenderCopy( renderer, textures[currentfont], &srcrect, &dstrect );
    }
    return;
}

void hgMenu::execute( int funct, int arg1, int arg2 )
{
    void (hgMenu::*functs[])(int,int) =
    {
        &hgMenu::setpos, &hgMenu::loadmenu, &hgMenu::showmenu, &hgMenu::hidemenu, &hgMenu::setsize
    };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgMenu::~hgMenu()
{
    return;
}
