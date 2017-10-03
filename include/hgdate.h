#ifndef HGDATE_H
#define HGDATE_H
#include "hgobject.h"


class hgDate : public hgObject
{
    public:
        hgDate();
        void showdate( int nil, int nada );
        void hidedate( int nil, int nada );
        void movedate( int monthstoadd, int weekstoadd );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgDate();

    protected:

    private:
        int month;
        int week;
        static const char* months[];
        int currentfont;
        bool shown;
};

#endif // HGDATE_H
