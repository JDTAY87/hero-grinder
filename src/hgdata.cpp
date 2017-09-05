#include "hgdata.h"

hgData::hgData()
{
    quit = false;
    currentmenu = 0;
}

int hgData::getmenu()
{
    return currentmenu;
}

bool hgData::quitselected()
{
    return quit;
}

void hgData::changemenu( int menu, int nada )
{
    currentmenu = menu;
    return;
}

void hgData::selectquit( int nil, int nada )
{
    quit = true;
}

void hgData::render( SDL_Renderer* renderer )
{
    return;
}

void hgData::execute( int funct, int arg1, int arg2 )
{
    void (hgData::*functs[])(int,int) = { &changemenu, &selectquit };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgData::~hgData()
{
    //dtor
}
