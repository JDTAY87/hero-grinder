#ifndef HGMENU_H
#define HGMENU_H
#include "hgobject.h"
#include "hgmenudata.h"


class hgMenu : public hgObject
{
    public:
        hgMenu( hgMenuData* menudata );
        void loadmenu( int location, int lines );
        void setfont( SDL_Texture* texture );
        void setpos( int x, int y );
        void setsize( int x, int y );
        void showmenu( int nil, int nada );
        void hidemenu( int nil, int nada );
        void setcursorpos( int change );
        int getselection();
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgMenu();

    protected:

    private:
        hgMenuData* data;
        bool shown;
        int noofoptions;
        int scriptptrs[10];
        const char* options[10];
        SDL_Texture* font;
        int cursorpos;
        int posx;
        int posy;
        SDL_Rect box;
};

#endif // HGMENU_H
