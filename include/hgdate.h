#ifndef HGDATE_H
#define HGDATE_H
#include "hgobject.h"


class hgDate : public hgObject
{
    public:
        hgDate();
        void setfont( SDL_Texture* texture );
        void showdate( int nil, int nada );
        void hidedate( int nil, int nada );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgDate();

    protected:

    private:
        int month;
        int week;
        static const char* months[];
        SDL_Texture* font;
        bool shown;
};

#endif // HGDATE_H
