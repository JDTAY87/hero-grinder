#include "hgsprite.h"

hgSprite::hgSprite( hgSprData* sprdata )
{
    data = sprdata;
    curframe = (0);
    shown = false;
    return;
}

void hgSprite::settextture( SDL_Texture* texture )
{
    spritetexture = texture;
    return;
}

void hgSprite::loadsprite( int sprite, int nada )
{
    spritebox.w = data->getprops( sprite, 0 );
    spritebox.h = data->getprops( sprite, 1 );
    framesx = data->getprops( sprite, 2 );
    framesy = data->getprops( sprite, 3 );
    return;
}

void hgSprite::setpos( int x, int y )
{
    spritebox.x = x;
    spritebox.y = y;
    return;
}

void hgSprite::showsprite( int nil, int nada )
{
    shown = true;
    return;
}

void hgSprite::hidesprite( int nil, int nada )
{
    shown = false;
    return;
}

void hgSprite::render( SDL_Renderer* renderer )
{
    if ( shown == true )
    {
        SDL_Rect srcrect;
        srcrect.w = spritebox.w;
        srcrect.h = spritebox.h;
        srcrect.x = curframe%framesx*spritebox.w;
        srcrect.y = curframe/framesy*spritebox.h;
        SDL_RenderCopy( renderer, spritetexture, &srcrect, &spritebox );
    }
    return;
}

void hgSprite::execute( int funct, int arg1, int arg2 )
{
    void (hgSprite::*functs[])(int,int) =
    {
        &hgSprite::loadsprite, &hgSprite::setpos, &hgSprite::showsprite, &hgSprite::hidesprite
    };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgSprite::~hgSprite()
{
    return;
}
