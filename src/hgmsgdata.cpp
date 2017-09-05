#include "hgmsgdata.h"

const char* hgMsgData::data[] =
{
    "Hero Grinder", "Coming soon.", " By JDTAY87 "
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
