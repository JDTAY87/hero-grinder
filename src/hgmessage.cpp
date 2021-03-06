#include "hgmessage.h"

const char* hgMessage::data[] =
{
    " Hero Grinder", "  Coming soon.", "  By JDTAY87 ",
    " Grinder Fields",
    " POW went up % to %.", " INT went up % to %.", " ACC went up % to %.",
    " SPD went up % to %.", " DEF went up % to %.", " VIT went up % to %.",
    " The hero rests this week.",
    "  Grinder City",
    " Increase your hero's stats through training.",
    " Recover your hero's energy and relieve hero stress.",
    " Visit various facilities in Grinder City.",
    " Check for quests and other events.",
    " View your hero's status, stats, and skills.",
    " Quit the game. (Option to save coming soon.)"
};

hgMessage::hgMessage()
{
    currentfont = 0;
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
    message[msgline] = data[line];
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
        SDL_SetRenderDrawColor( renderer, 204, 153, 51, 255 );
        SDL_RenderFillRect( renderer, &box );
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
        SDL_RenderDrawRect( renderer, &box );
        SDL_Rect box2;
        box2.x = box.x+1;
        box2.y = box.y+1;
        box2.w = box.w-2;
        box2.h = box.h-2;
        SDL_RenderDrawRect( renderer, &box2 );
        SDL_Rect srcrect;
        srcrect.h = 20;
        srcrect.w = 10;
        SDL_Rect dstrect;
        dstrect.h = 20;
        dstrect.w = 10;
        dstrect.x = posx*10;
        dstrect.y = posy*10;
        int pullcount = 0;
        for ( int z1 = 0; z1 < nooflines; z1++ )
        {
            for ( int z2 = 0; message[z1][z2] != 0; z2++ )
            {
                if ( message[z1][z2] != 37 )
                {
                    srcrect.x = (message[z1][z2]%16)*10;
                    srcrect.y = (message[z1][z2]/16-2)*20;
                    SDL_RenderCopy( renderer, textures[currentfont], &srcrect, &dstrect );
                    dstrect.x += 10;
                }
                else
                {
                    int sizeofpull = 0;
                    int compareint = 1;
                    int pull = pushpull[pullcount];
                    while ( pull >= compareint )
                    {
                        sizeofpull++;
                        compareint *= 10;
                    }
                    dstrect.x += sizeofpull*10;
                    srcrect.y = 20;
                    for ( int z = sizeofpull; z != 0; z-- )
                    {
                        dstrect.x -= 10;
                        srcrect.x = (pull%10)*10;
                        SDL_RenderCopy( renderer, textures[currentfont], &srcrect, &dstrect );
                        pull /= 10;
                    }
                    dstrect.x += sizeofpull*10;
                    pullcount++;
                }
            }
            dstrect.y += 20;
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
