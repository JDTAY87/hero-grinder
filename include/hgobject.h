#ifndef HGOBJECT_H
#define HGOBJECT_H
#include "hgsdl2.h"
#include "hgtexture.h"

class hgObject
{
    public:
        virtual void execute( int funct, int arg1, int arg2 ) = 0;
        virtual void render( SDL_Renderer* renderer ) = 0;
        void settexture( int number, hgTexture* texture );

    protected:
        static hgTexture* textures[];
        static int pushpull[10];

    private:
};

#endif // HGOBJECT_H
