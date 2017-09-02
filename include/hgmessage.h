#ifndef HGMESSAGE_H
#define HGMESSAGE_H
#include <stdio.h>
#include <string>
#include "SDL.h"

class hgMessage
{
    public:
        hgMessage();
        void setmessage( const char* text );
        void setfont( SDL_Texture* texture );
        void setpos( int x, int y );
        void render( SDL_Renderer* renderer );
        ~hgMessage();

    protected:

    private:
        const char* message;
        SDL_Texture* font;
        int posx;
        int posy;
};

#endif // HGMESSAGE_H
