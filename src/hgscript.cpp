#include "hgscript.h"


int hgScript::gamescript[] =
{
    obj_msg1, msg_setlines, 1, 0, 1,
    obj_msg1, msg_setmsg, 0, 0, 1,
    obj_msg1, msg_setpos, 26, 13, 1,
    obj_msg1, msg_setsize, 12, 1, 1,
    obj_msg1, msg_showmsg, 0, 0, 1,
    obj_menu1, menu_loadmenu, 0, 3, 1,
    obj_menu1, menu_setpos, 27, 17, 1,
    obj_menu1, menu_setsize, 10, 3, 1,
    obj_menu1, menu_showmenu, 0, 0, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 2, 0,
    obj_data, data_selectquit, 0, 0, 0
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
