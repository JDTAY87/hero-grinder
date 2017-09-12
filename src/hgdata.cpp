#include "hgdata.h"

hgData::hgData()
{
    quit = false;
    currentmenu = (0);
    currentscript = (0);
}

int hgData::getmenu()
{
    return currentmenu;
}

int hgData::getscript()
{
    return currentscript;
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

void hgData::changescript( int script, int nada )
{
    currentscript = script;
}

void hgData::selectquit( int nil, int nada )
{
    quit = true;
    return;
}

void hgData::render( SDL_Renderer* renderer )
{
    return;
}

void hgData::execute( int funct, int arg1, int arg2 )
{
    void (hgData::*functs[])(int,int) = { &hgData::changemenu, &hgData::changescript, &hgData::selectquit };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgData::~hgData()
{
    //dtor
}
