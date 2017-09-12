#ifndef HGSPRDATA_H
#define HGSPRDATA_H


class hgSprData
{
    public:
        hgSprData();
        int getprops( int sprite, int prop );
        ~hgSprData();

    protected:

    private:
        static int sprprops[];
};

#endif // HGSPRDATA_H
