#include "hgmenudata.h"

const char* menudata1[] =
{
    " New Game", " Credits ", " Exit    "
};

hgMenuData::hgMenuData()
{
    return;
}

const char* hgMenuData::getdata( int line )
{
    return menudata1[ line ];
}

hgMenuData::~hgMenuData()
{
    return;
}
