#include "hgscript.h"


int hgScript::gamescript[] =
{
    obj_msg1, msg_setmsg, 0, 0, 1,
    obj_msg1, msg_setpos, 26, 14, 1,
    obj_menu1, menu_loadmenu, 0, 3, 1,
    obj_menu1, menu_setpos, 27, 18, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 2, 0,
    obj_msg1, msg_setmsg, 0, 3, 0
};

hgScript::hgScript()
{
    return;
}

int hgScript::getscript( int location )
{
    return gamescript[ location ];
}

hgScript::~hgScript()
{
    return;
}