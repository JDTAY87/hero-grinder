#include "hgscript.h"

enum scriptobjs
{
    obj_msg1, obj_menu1
};

enum msgactions
{
    msg_setpos, msg_setmsg
};

enum menuactions
{
    menu_setpos, menu_setopt
};

int gamescript[] =
{
    obj_msg1, msg_setmsg, 0, 0, 1,
    obj_msg1, msg_setpos, 26, 14, 1,
    obj_menu1, menu_setopt, 0, 0, 1,
    obj_menu1, menu_setopt, 1, 1, 1,
    obj_menu1, menu_setopt, 2, 2, 1,
    obj_menu1, menu_setpos, 27, 18, 0
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
