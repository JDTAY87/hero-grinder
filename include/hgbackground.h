#ifndef HGBACKGROUND_H
#define HGBACKGROUND_H
#include "hgobject.h"

class hgBackground : public hgObject
{
    public:
        hgBackground();
        void settexture( int number, SDL_Texture* texture );
        void setbg( int number, int nada );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgBackground();

    protected:

    private:
        SDL_Texture* background[2];
        int currentbg;
};

#endif // HGBACKGROUND_H
