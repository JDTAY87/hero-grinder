#ifndef HGMENU_H
#define HGMENU_H
#include "SDL.h"
#include "hgobject.h"
#include "hgmenudata.h"


class hgMenu : public hgObject
{
    public:
        hgMenu( hgMenuData* menudata );
        void loadmenu( int location, int lines );
        void setfont( SDL_Texture* texture );
        void setpos( int x, int y );
        void setcursorpos( int change );
        int getselection();
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgMenu();

    protected:

    private:
        hgMenuData* data;
        int noofoptions;
        int scriptptrs[10];
        const char* options[10];
        SDL_Texture* font;
        int cursorpos;
        int posx;
        int posy;
};

#endif // HGMENU_H
