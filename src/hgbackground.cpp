#include "hgbackground.h"

hgBackground::hgBackground()
{
    currentbg = 0;
    return;
}

void hgBackground::settexture( int number, SDL_Texture* texture )
{
    background[number] = texture;
    return;
}

void hgBackground::setbg( int number, int nada )
{
    currentbg = number;
    return;
}

void hgBackground::render( SDL_Renderer* renderer )
{
    SDL_RenderCopy( renderer, background[currentbg], NULL, NULL );
    return;
}

void hgBackground::execute( int funct, int arg1, int arg2 )
{
    void (hgBackground::*functs[])(int,int) = { &hgBackground::setbg };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgBackground::~hgBackground()
{
    return;
}
