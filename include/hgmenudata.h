#ifndef HGMENUDATA_H
#define HGMENUDATA_H


class hgMenuData
{
    public:
        hgMenuData();
        int getptr( int line );
        const char* getdata( int line );
        ~hgMenuData();

    protected:

    private:
        static int menuptrs[];
        static const char* data[];
};

#endif // HGMENUDATA_H
