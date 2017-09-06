#ifndef HGOBJECT_H
#define HGOBJECT_H
#include "hgsdl2.h"

class hgObject
{
    public:
        virtual void execute( int funct, int arg1, int arg2 ) = 0;
        virtual void render( SDL_Renderer* renderer ) = 0;

    protected:

    private:
};

#endif // HGOBJECT_H
