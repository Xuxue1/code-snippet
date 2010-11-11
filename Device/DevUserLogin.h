#ifndef _DEVUSERLOGIN_H_
#define _DEVUSERLOGIN_H_

class CDevInfo;

class IDevUserLogin
{
public:
    virtual ~IDevUserLogin(void);
public:
    virtual int         Login(void) = 0;
    virtual int         Logout(void) = 0;
    virtual bool        HasLogedin(void) = 0;
    virtual void        GetLoginId() = 0;
    virtual bool        IsLoginIdValid(void) = 0;
    virtual char*       GetSerialNumber(void) = 0;
    virtual int         GetAlarmInportNum(void) = 0;
    virtual int         GetAlarmOutportNum(void) = 0;
    virtual int         GetDiskNum(void) = 0;
    virtual int         GetDvrType(void) = 0;
    virtual int         GetChannelNum(void) = 0;
    virtual int         GetStartChannelNum(void) = 0;
    virtual int         Reboot() = 0;
    virtual int         ShutDown() = 0;
    virtual int         Upgrade(char *sFileName) = 0;
    virtual int         GetUpgradeProgress() = 0;
    virtual int         GetUpgradeState() = 0;
};


#endif
