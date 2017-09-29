#include "hgscript.h"


int hgScript::titlemenu[] =
{
    obj_msg1, msg_setlines, 1, 0, 1,
    obj_msg1, msg_setmsg, 0, 0, 1,
    obj_msg1, msg_setpos, 25, 13, 1,
    obj_msg1, msg_setsize, 14, 1, 1,
    obj_msg1, msg_showmsg, 0, 0, 1,
    obj_menu1, menu_loadmenu, 0, 3, 1,
    obj_menu1, menu_setpos, 27, 17, 1,
    obj_menu1, menu_setsize, 10, 3, 1,
    obj_menu1, menu_showmenu, 0, 0, 0,
    obj_msg1, msg_setmsg, 0, 3, 1,
    obj_msg1, msg_setpos, 24, 3, 1,
    obj_msg1, msg_setsize, 16, 1, 1,
    obj_menu1, menu_setpos, 3, 3, 1,
    obj_menu1, menu_setsize, 8, 6, 1,
    obj_menu1, menu_loadmenu, 3, 6, 1,
    obj_gamedate, date_showdate, 0, 0, 1,
    obj_herospr, spr_setpos, 280, 140, 1,
    obj_herospr, spr_loadsprite, 0, 0, 1,
    obj_herospr, spr_showsprite, 0, 0, 1,
    obj_data, data_changescript, 1, 0, 0,
    obj_msg1, msg_setmsg, 0, 2, 0,
    obj_data, data_selectquit, 0, 0, 0
};

int hgScript::fieldsmenu[] =
{
    obj_menu2, menu_loadmenu, 10, 7, 1,
    obj_menu2, menu_setpos, 28, 14, 1,
    obj_menu2, menu_setsize, 8, 7, 1,
    obj_menu2, menu_showmenu, 0, 0, 1,
    obj_data, data_changemenu, 1, 0, 1,
    obj_data, data_changescript, 2, 0, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_herostats, stat_showstats, 0, 0, 1,
    obj_menu2, menu_loadmenu, 9, 1, 1,
    obj_menu2, menu_setpos, 28, 26, 1,
    obj_menu2, menu_setsize, 8, 1, 1,
    obj_menu2, menu_showmenu, 0, 0, 1,
    obj_data, data_changemenu, 1, 0, 0,
    obj_data, data_selectquit, 0, 0, 0,
    obj_herostats, stat_hidestats, 0, 0, 1,
    obj_menu2, menu_hidemenu, 0, 0, 1,
    obj_data, data_changemenu, 0, 0, 0
};

int hgScript::trainmenu[] =
{
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_msg1, msg_setmsg, 0, 1, 0,
    obj_menu2, menu_hidemenu, 0, 0, 1,
    obj_data, data_changemenu, 0, 0, 1,
    obj_data, data_changescript, 1, 0, 0
};

int* hgScript::scripts[] = { &hgScript::titlemenu[0], &hgScript::fieldsmenu[0], &hgScript::trainmenu[0] };

hgScript::hgScript()
{
    return;
}

int hgScript::getscript( int scriptno, int location )
{
    return *(scripts[ scriptno ] + location);
}

hgScript::~hgScript()
{
    return;
}
