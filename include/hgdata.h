#ifndef HGDATA_H
#define HGDATA_H
#include <SDL2/SDL.h>
#include "hgobject.h"

class hgData : public hgObject
{
    public:
        hgData();
        int getmenu();
        bool quitselected();
        void changemenu( int menu, int nada );
        void selectquit( int nil, int nada );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgData();

    protected:

    private:
        int currentmenu;
        bool quit;
};

#endif // HGDATA_H