#ifndef HGSCRIPT_H
#define HGSCRIPT_H


class hgScript
{
    public:
        hgScript();
        int getscript( int location );
        ~hgScript();

    protected:

    private:
        enum scriptobjs{obj_data, obj_msg1, obj_msg2, obj_menu1, obj_menu2};
        enum dataactions{data_changemenu, data_selectquit};
        enum msgactions{msg_setpos, msg_setlines, msg_setmsg, msg_showmsg, msg_hidemsg, msg_setsize};
        enum menuactions{menu_setpos, menu_loadmenu, menu_showmenu, menu_hidemenu, menu_setsize};
        static int gamescript[];
};

#endif // HGSCRIPT_H
