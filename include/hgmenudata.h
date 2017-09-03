#ifndef HGMENUDATA_H
#define HGMENUDATA_H


class hgMenuData
{
    public:
        hgMenuData();
        const char* getdata( int line );
        ~hgMenuData();

    protected:

    private:
        static const char* data[];
};

#endif // HGMENUDATA_H
