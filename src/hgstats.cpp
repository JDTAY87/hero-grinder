#include "hgstats.h"

const char* hgStats::statnames[] =
{
    " POW ", " INT ", " ACC ", " SPD ", " DEF ", " VIT "
};

hgStats::hgStats()
{
    for ( int z = 0; z < 6; z++ ) { stats[z] = 100; }
    shown = false;
    return;
}

void hgStats::setfont( SDL_Texture* texture )
{
    font = texture;
    return;
}

void hgStats::showstats( int nil, int nada )
{
    shown = true;
    return;
}

void hgStats::hidestats( int nil, int nada )
{
    shown = false;
    return;
}

void hgStats::trainstat( int stattotrain, int nada )
{
    statgain = 4;
    stats[stattotrain] += statgain;
    if ( stats[stattotrain] > 999 ) { stats[stattotrain] = 999; }
    return;
}

void hgStats::push( int inttopush, int location )
{
    int* vars[] = { &stats[0], &stats[1], &stats[2], &stats[3], &stats[4], &stats[5], &statgain };
    pushpull[location] = *vars[inttopush];
    return;
}

void hgStats::render( SDL_Renderer* renderer )
{
    if ( shown == true )
    {
        SDL_Rect box;
        box.w = 104;
        box.h = 128;
        box.x = 268;
        box.y = 118;
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
        for ( int z1 = 0; z1 < 6; z1++ )
        {
            dstrect.y = 120+(z1*20);
            for ( int z2 = 0; statnames[z1][z2] != 0; z2++ )
            {
                srcrect.x = (statnames[z1][z2]%16)*10;
                srcrect.y = (statnames[z1][z2]/16-2)*20;
                dstrect.x = 270+(z2*10);
                SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
            }
            srcrect.y = 20;
            srcrect.x = (stats[z1]%10)*10;
            dstrect.x = 350;
            SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
            srcrect.x = (stats[z1]%100)-(stats[z1]%10);
            dstrect.x = 340;
            SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
            srcrect.x = (stats[z1]-(stats[z1]%100))/10;
            dstrect.x = 330;
            SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
        }
    }
    return;
}

void hgStats::execute( int funct, int arg1, int arg2 )
{
    void (hgStats::*functs[])(int,int) =
    {
        &hgStats::push, &hgStats::showstats, &hgStats::hidestats, &hgStats::trainstat
    };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgStats::~hgStats()
{
    return;
}
