#include "hgmenu.h"

hgMenu::hgMenu( hgMenuData* menudata )
{
    data = menudata;
    for ( int z = 0; z < 10; z++ ) { options[z] = ""; }
    return;
}

void hgMenu::setoption( int option, int line )
{
    options[ option ] = data->getdata( line );
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

void hgMenu::render( SDL_Renderer* renderer )
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
    return;
}

void hgMenu::execute( int funct, int arg1, int arg2 )
{
    void (hgMenu::*functs[])(int,int) = { &setpos, &setoption };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgMenu::~hgMenu()
{
    return;
}
