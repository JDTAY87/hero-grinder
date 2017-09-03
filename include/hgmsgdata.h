#ifndef HGMSGDATA_H
#define HGMSGDATA_H


class hgMsgData
{
    public:
        hgMsgData();
        const char* getdata( int line );
        ~hgMsgData();

    protected:

    private:
        static const char* data[];
};

#endif // HGMSGDATA_H
