#ifndef HGMESSAGE_H
#define HGMESSAGE_H
#include <stdio.h>
#include <string>
#include "hgobject.h"
#include "hgmsgdata.h"

class hgMessage : public hgObject
{
    public:
        hgMessage();
        void setdata( hgMsgData* msgdata );
        void setlines( int lines, int nada );
        void setmessage( int msgline, int line );
        void setfont( SDL_Texture* texture );
        void setpos( int x, int y );
        void setsize( int x, int y );
        void showmessage( int nil, int nada );
        void hidemessage( int nil, int nada );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgMessage();

    protected:

    private:
        hgMsgData* data;
        bool shown;
        int nooflines;
        const char* message[10];
        SDL_Texture* font;
        int posx;
        int posy;
        SDL_Rect box;
};

#endif // HGMESSAGE_H
