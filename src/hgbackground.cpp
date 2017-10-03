#include "hgbackground.h"

hgBackground::hgBackground()
{
    currentbg = 1;
    return;
}

void hgBackground::setbg( int number, int nada )
{
    currentbg = number;
    return;
}

void hgBackground::render( SDL_Renderer* renderer )
{
    SDL_RenderCopy( renderer, textures[currentbg]->gettexture(), NULL, NULL );
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
