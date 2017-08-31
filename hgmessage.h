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
        void render( SDL_Renderer* renderer, int x, int y );
        ~hgMessage();

    protected:

    private:
        const char* message;
        SDL_Texture* font;
};

#endif // HGMESSAGE_H
