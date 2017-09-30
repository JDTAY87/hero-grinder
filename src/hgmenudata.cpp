#include "hgmenudata.h"

int hgMenuData::menuptrs[] =
{
    9, 20, 21,
    0, 6, 7, 8, 9, 15,
    16,
    0, 13, 26, 39, 52, 65, 78,
    81
};

const char* hgMenuData::data[] =
{
    " New Game", " Credits ", " Exit    ",
    " Train ", " Rest  ", " Events", " City  ", " Status", " Exit  ",
    " Return",
    "  POW", "  INT", "  ACC", "  SPD", "  DEF", "  VIT", "  Back",
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
