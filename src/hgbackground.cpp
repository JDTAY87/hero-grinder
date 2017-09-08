#include "hgbackground.h"

hgBackground::hgBackground()
{
    return;
}

void hgBackground::settexture( SDL_Texture* texture )
{
    background = texture;
    return;
}

void hgBackground::render( SDL_Renderer* renderer )
{
    SDL_RenderCopy( renderer, background, NULL, NULL );
    return;
}

void hgBackground::execute( int funct, int arg1, int arg2 )
{
    return;
}

hgBackground::~hgBackground()
{
    return;
}
