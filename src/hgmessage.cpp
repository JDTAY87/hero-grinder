#include "hgmessage.h"

hgMessage::hgMessage()
{
    return;
}

void hgMessage::setmessage( const char* text )
{
    message = text;
    return;
}

void hgMessage::setfont( SDL_Texture* texture )
{
    font = texture;
    return;
}

void hgMessage::render( SDL_Renderer* renderer, int x, int y )
{
    SDL_Rect srcrect;
    srcrect.h = 20;
    srcrect.w = 10;
    SDL_Rect dstrect;
    dstrect.h = 20;
    dstrect.w = 10;
    for ( int z = 0; message[z] != 0; z++ )
    {
        if ( message[z] > 32 )
        {
            srcrect.x = (message[z]%16)*10;
            srcrect.y = (message[z]/16-2)*20;
            dstrect.x = x*10+(z*10);
            dstrect.y = y*10;
            SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
        }
    }
    return;
}

hgMessage::~hgMessage()
{
    message = NULL;
    font = NULL;
    return;
}
