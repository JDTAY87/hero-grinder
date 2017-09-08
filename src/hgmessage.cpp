#include "hgmessage.h"

hgMessage::hgMessage( hgMsgData* msgdata )
{
    data = msgdata;
    shown = false;
    nooflines = 0;
    for ( int z = 0; z < 10; z++ )
    {
        message[z] = "";
    }
    return;
}

void hgMessage::setlines( int lines, int nada )
{
    nooflines = lines;
    return;
}

void hgMessage::setmessage( int msgline, int line )
{
    message[msgline] = data->getdata( line );
    return;
}

void hgMessage::setfont( SDL_Texture* texture )
{
    font = texture;
    return;
}

void hgMessage::setpos( int x, int y )
{
    posx = x;
    posy = y;
    box.x = x*10-2;
    box.y = y*10-2;
    return;
}

void hgMessage::setsize( int x, int y )
{
    box.w = x*10+4;
    box.h = y*20+8;
    return;
}

void hgMessage::showmessage( int nil, int nada )
{
    shown = true;
    return;
}

void hgMessage::hidemessage( int nil, int nada )
{
    shown = false;
    return;
}

void hgMessage::render( SDL_Renderer* renderer )
{
    if ( shown == true )
    {
        SDL_RenderFillRect( renderer, &box );
        SDL_SetRenderDrawColor( renderer, 51, 51, 51, 255 );
        SDL_RenderDrawRect( renderer, &box );
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
        SDL_Rect srcrect;
        srcrect.h = 20;
        srcrect.w = 10;
        SDL_Rect dstrect;
        dstrect.h = 20;
        dstrect.w = 10;
        for ( int z1 = 0; z1 < nooflines; z1++ )
        {
            for ( int z2 = 0; message[z1][z2] != 0; z2++ )
            {
                if ( message[z1][z2] > 31 )
                {
                    srcrect.x = (message[z1][z2]%16)*10;
                    srcrect.y = (message[z1][z2]/16-2)*20;
                    dstrect.x = posx*10+(z2*10);
                    dstrect.y = posy*10+(z1*10);
                    SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
                }
            }
        }
    }
    return;
}

void hgMessage::execute( int funct, int arg1, int arg2 )
{
    void (hgMessage::*functs[])(int,int) =
    {
        &hgMessage::setpos, &hgMessage::setlines, &hgMessage::setmessage, &hgMessage::showmessage,
        &hgMessage::hidemessage, &hgMessage::setsize
    };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgMessage::~hgMessage()
{
    return;
}
