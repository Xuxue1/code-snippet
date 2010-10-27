#include <iostream>

class IDevUserLogin
{

public:
    IDevUserLogin();
    virtual ~IDevUserLogin(void);
public:
    /// µÇÂ½×¢²á
    virtual int         Login( void) = 0;
    virtual int         Logout( void ) = 0;
    virtual void        GetLoginId() = 0;
    bool                IsLoginIdValid(void) = 0;
    virtual const char* GetSerialNumber(void) = 0;
    virtual int         GetAlarmInportNum(void) = 0;
    virtual int         GetAlarmOutportNum(void) = 0;
    virtual int         GetDiskNum(void) = 0;
    virtual int         GetDvrType(void) = 0;
    virtual int         GetChannelNum(void) = 0;
    virtual int         StartChannelNum(void) = 0;
};
