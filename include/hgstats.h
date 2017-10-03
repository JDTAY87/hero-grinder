#ifndef HGSTATS_H
#define HGSTATS_H
#include "hgobject.h"


class hgStats : public hgObject
{
    public:
        hgStats();
        void showstats( int nil, int nada );
        void hidestats( int nil, int nada );
        void trainstat( int stattotrain, int nada );
        void push( int inttopush, int location );
        void render( SDL_Renderer* renderer );
        void execute( int funct, int arg1, int arg2 );
        ~hgStats();

    protected:

    private:
        int stats[6];
        static const char* statnames[];
        int currentfont;
        bool shown;
        int statgain;
};

#endif // HGSTATS_H
