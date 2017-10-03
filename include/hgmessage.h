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
        void setpos( int x, int y );
        void setsize( int x, int y );
        void showmessage( int nil, int nada );
        void hidemessage( int nil, int nada );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgMessage();

    protected:

    private:
        static hgMsgData* data;
        int currentfont;
        bool shown;
        int nooflines;
        const char* message[10];
        int posx;
        int posy;
        SDL_Rect box;
};

#endif // HGMESSAGE_H
