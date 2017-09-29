#ifndef HGSCRIPT_H
#define HGSCRIPT_H


class hgScript
{
    public:
        hgScript();
        int getscript( int scriptno, int location );
        ~hgScript();

    protected:

    private:
        enum scriptobjs{obj_data, obj_herospr, obj_msg1, obj_msg2, obj_menu1, obj_menu2, obj_gamedate, obj_herostats};
        enum dataactions{data_changemenu, data_changescript, data_selectquit};
        enum spractions{spr_loadsprite, spr_setpos, spr_showsprite, spr_hidesprite};
        enum msgactions{msg_setpos, msg_setlines, msg_setmsg, msg_showmsg, msg_hidemsg, msg_setsize};
        enum menuactions{menu_setpos, menu_loadmenu, menu_showmenu, menu_hidemenu, menu_setsize};
        enum statactions{stat_showstats, stat_hidestats, stat_trainstat};
        enum dateactions{date_showdate, date_hidedate};
        static int titlemenu[];
        static int fieldsmenu[];
        static int trainmenu[];
        static int* scripts[];
};

#endif // HGSCRIPT_H
