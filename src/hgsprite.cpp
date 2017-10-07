#include "hgsprite.h"

int hgSprite::sprprops[] =
{
    80, 80, 2, 1
};

hgSprite::hgSprite()
{
    cursprite = 3;
    curframe = (0);
    shown = false;
    return;
}

void hgSprite::loadsprite( int sprite, int nada )
{
    spritebox.w = sprprops[sprite*4];
    spritebox.h = sprprops[sprite*4+1];
    framesx = sprprops[sprite*4+2];
    framesy = sprprops[sprite*4+3];
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
        SDL_RenderCopy( renderer, textures[cursprite], &srcrect, &spritebox );
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
