#include "hgdate.h"

const char* hgDate::months[] =
{
    " ", "Jan Wk ", "Feb Wk ", "Mar Wk ", "Apr Wk ", "May Wk ", "Jun Wk ",
    "Jul Wk ", "Aug Wk ", "Sep Wk ", "Oct Wk ", "Nov Wk ", "Dec Wk "
};

hgDate::hgDate()
{
    month = 1;
    week = 1;
    shown = false;
    return;
}

void hgDate::setfont( SDL_Texture* texture )
{
    font = texture;
    return;
}

void hgDate::showdate( int nil, int nada )
{
    shown = true;
    return;
}

void hgDate::hidedate( int nil, int nada )
{
    shown = false;
    return;
}

void hgDate::movedate( int monthstoadd, int weekstoadd )
{
    week += weekstoadd;
    if ( week > 4 ) { week = (week-1)%4+1; month++; }
    month += monthstoadd;
    if ( month > 12 ) { month = (month-1)%12+1; }
    return;
}

void hgDate::render( SDL_Renderer* renderer )
{
    if ( shown == true )
    {
        SDL_Rect box;
        box.w = 104;
        box.h = 28;
        box.x = 508;
        box.y = 28;
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
        dstrect.y = 30;
        for ( int z = 0; months[month][z] != 0; z++ )
        {
            srcrect.x = (months[month][z]%16)*10;
            srcrect.y = (months[month][z]/16-2)*20;
            dstrect.x = 520+z*10;
            SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
        }
        dstrect.x = 590;
        srcrect.y = 20;
        srcrect.x = week*10;
        SDL_RenderCopy( renderer, font, &srcrect, &dstrect );
    }
    return;
}

void hgDate::execute( int funct, int arg1, int arg2 )
{
    void (hgDate::*functs[])(int,int) =
    {
        &hgDate::showdate, &hgDate::hidedate, &hgDate::movedate
    };
    (this->*functs[funct])( arg1, arg2 );
    return;
}

hgDate::~hgDate()
{
    //dtor
}
