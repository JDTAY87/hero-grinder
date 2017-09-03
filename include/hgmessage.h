#ifndef HGMESSAGE_H
#define HGMESSAGE_H
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "hgobject.h"
#include "hgmsgdata.h"

class hgMessage : public hgObject
{
    public:
        hgMessage( hgMsgData* msgdata );
        void setmessage( int msgline, int line );
        void setfont( SDL_Texture* texture );
        void setpos( int x, int y );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgMessage();

    protected:

    private:
        hgMsgData* data;
        const char* message;
        SDL_Texture* font;
        int posx;
        int posy;
};

#endif // HGMESSAGE_H
