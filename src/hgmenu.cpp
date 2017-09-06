#include "hgmenu.h"

hgMenu::hgMenu( hgMenuData* menudata )
{
    shown = false;
    data = menudata;
    noofoptions = 0;
    cursorpos = 0;
    for ( int z = 0; z < 10; z++ )
    {
        scriptptrs[z] = 0;
        options[z] = "";
    }
    return;
}

void hgMenu::loadmenu( int location, int lines )
{
    noofoptions = lines;
    for ( int z = 0; z < lines; z++ )
    {
        scriptptrs[z] = data->getptr( location+z );
        options[z] = data->getdata( location+z );
    }
    return;
}

void hgMenu::setfont( SDL_Texture* texture )
{
    font = texture;
    return;
}

void hgMenu::setpos( int x, int y )
{
    posx = x;
    posy = y;
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

void hgMenu::render( SDL_Renderer* renderer )
{
    if ( shown == true )
    {
        SDL_Rect srcrect;
        srcrect.h = 20;
        srcrect.w = 10;
        SDL_Rect dstrect;
        dstrect.h = 20;
        dstrect.w = 10;
        for ( int z1 = 0; z1 < 10; z1++ )
        {
            for ( int z2 = 0; options[z1][z2] != 0; z2++ )
            {
                if ( options[z1][z2] > 31 )
                {
                    srcrect.x = (options[z1][z2]%16)*10;
                    srcrect.y = (options[z1][z2]/16-2)*20;
                    dstrect.x = posx*10+(z2*10);
                    dstrect.y = posy*10+(z1*20);
                    SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
                }
            }
        }
        srcrect.x = 140;
        srcrect.y = 20;
        dstrect.x = posx*10;
        dstrect.y = posy*10+(cursorpos*20);
        SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
    }
    return;
}

void hgMenu::execute( int funct, int arg1, int arg2 )
{
    void (hgMenu::*functs[])(int,int) = { &hgMenu::setpos, &hgMenu::loadmenu, &hgMenu::showmenu, &hgMenu::hidemenu };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgMenu::~hgMenu()
{
    return;
}
