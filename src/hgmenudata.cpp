#include "hgmenudata.h"

int hgMenuData::menuptrs[] =
{
    9, 20, 21,
    0, 6, 16, 23, 24, 30,
    35, 31,
    0, 13, 26, 39, 52, 65, 78,
    81,
    0, 7, 8
};

const char* hgMenuData::data[] =
{
    " New Game", " Credits", " Exit",
    " Train", " Rest", " City", " Events", " Status", " Exit",
    " Return", " Return",
    "  POW", "  INT", "  ACC", "  SPD", "  DEF", "  VIT", "  Back",
    " Return",
    " Fields", " Portal", " Exit"
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
