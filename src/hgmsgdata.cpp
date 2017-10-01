#include "hgmsgdata.h"

const char* hgMsgData::data[] =
{
    " Hero Grinder", "  Coming soon.", "  By JDTAY87 ",
    " Grinder Fields",
    " POW went up % to %.", " INT went up % to %.", " ACC went up % to %.",
    " SPD went up % to %.", " DEF went up % to %.", " VIT went up % to %.",
    " The hero rests this week."
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
