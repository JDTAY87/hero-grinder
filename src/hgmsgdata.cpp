#include "hgmsgdata.h"

const char* hgMsgData::data[] =
{
    "Hero Grinder"
};

hgMsgData::hgMsgData()
{
    return;
}

const char* hgMsgData::getdata( int line )
{
    return data[ line ];
}

hgMsgData::~hgMsgData()
{
    return;
}
