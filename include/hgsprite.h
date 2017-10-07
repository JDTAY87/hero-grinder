#ifndef HGSPRITE_H
#define HGSPRITE_H
#include "hgobject.h"


class hgSprite : public hgObject
{
    public:
        hgSprite();
        void loadsprite( int sprite, int nada );
        void setpos( int x, int y );
        void showsprite( int nil, int nada );
        void hidesprite( int nil, int nada );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgSprite();

    protected:

    private:
        static int sprprops[];
        int cursprite;
        bool shown;
        SDL_Rect spritebox;
        int framesx;
        int framesy;
        int curframe;
};

#endif // HGSPRITE_H
