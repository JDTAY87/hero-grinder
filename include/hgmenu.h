#ifndef HGMENU_H
#define HGMENU_H
#include "SDL.h"
#include "hgobject.h"
#include "hgmenudata.h"


class hgMenu : public hgObject
{
    public:
        hgMenu( hgMenuData* menudata );
        void setoption( int option, int line );
        void setfont( SDL_Texture* texture );
        void setpos( int x, int y );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgMenu();

    protected:

    private:
        hgMenuData* data;
        const char* options[10];
        SDL_Texture* font;
        int posx;
        int posy;
};

#endif // HGMENU_H
