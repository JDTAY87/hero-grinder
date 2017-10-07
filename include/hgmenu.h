#ifndef HGMENU_H
#define HGMENU_H
#include "hgobject.h"


class hgMenu : public hgObject
{
    public:
        hgMenu();
        void loadmenu( int location, int lines );
        void setpos( int x, int y );
        void setsize( int x, int y );
        void showmenu( int nil, int nada );
        void hidemenu( int nil, int nada );
        void setcursorpos( int change );
        int getselection();
        int gethilight();
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgMenu();

    protected:

    private:
        static int menudata[];
        static int hilightdata[];
        static const char* data[];
        int currentfont;
        bool shown;
        int noofoptions;
        int scriptptrs[10];
        int hilightptrs[10];
        const char* options[10];
        int cursorpos;
        int posx;
        int posy;
        SDL_Rect box;
};

#endif // HGMENU_H
