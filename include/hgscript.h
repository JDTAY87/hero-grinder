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
        enum scriptobjs{obj_msg1, obj_menu1};
        enum msgactions{msg_setpos, msg_setmsg};
        enum menuactions{menu_setpos, menu_loadmenu};
        static int gamescript[];
};

#endif // HGSCRIPT_H
