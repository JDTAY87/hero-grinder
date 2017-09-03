#include "hgmsgdata.h"

const char* msgdata1[] =
{
    "Hero Grinder"
};

hgMsgData::hgMsgData()
{
    return;
}

const char* hgMsgData::getdata( int line )
{
    return msgdata1[ line ];
}

hgMsgData::~hgMsgData()
{
    return;
}
