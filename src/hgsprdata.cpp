#include "hgsprdata.h"

int hgSprData::sprprops[] =
{
    80, 80, 2, 1
};

hgSprData::hgSprData()
{
    return;
}

int hgSprData::getprops( int sprite, int prop )
{
    return sprprops[sprite*4+prop];
}

hgSprData::~hgSprData()
{
    return;
}
