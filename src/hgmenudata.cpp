#include "hgmenudata.h"

int hgMenuData::menuptrs[] =
{
    4, 5, 6
};

const char* hgMenuData::data[] =
{
    " New Game", " Credits ", " Exit    "
};

hgMenuData::hgMenuData()
{
    return;
}

int hgMenuData::getptr( int line )
{
    return menuptrs[ line ];
}

const char* hgMenuData::getdata( int line )
{
    return data[ line ];
}

hgMenuData::~hgMenuData()
{
    return;
}