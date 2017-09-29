#include "hgmenudata.h"

int hgMenuData::menuptrs[] =
{
    9, 20, 21,
    0, 6, 7, 8, 9, 15,
    16,
    0, 1, 2, 3, 4, 5, 6
};

const char* hgMenuData::data[] =
{
    " New Game", " Credits ", " Exit    ",
    " Train ", " Rest  ", " Events", " City  ", " Status", " Exit  ",
    " Return",
    "  POW", "  INT", "  ACC", "  SPD", "  DEF", "  VIT", "  Back"
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
