#include "hgmenudata.h"

int hgMenuData::menuptrs[] =
{
    9, 19, 20,
    0, 1, 2, 3, 4, 10,
    11
};

const char* hgMenuData::data[] =
{
    " New Game", " Credits ", " Exit    ",
    " Train ", " Rest  ", " Events", " City  ", " Status", " Exit  ",
    " Return"
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
