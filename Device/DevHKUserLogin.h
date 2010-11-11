#include "DevUserLogin.h"
#include "includeHK/HCNetSDK.h"
class CDevHKUserLogin:
    public IDevUserLogin
{
public:
    CDevHKUserLogin(CDevInfo *devInfo);
    virtual ~CDevHKUserLogin(void);
    virtual int         Login(void);
    virtual int         Logout(void);
    virtual bool        HasLogedin(void);
    virtual void        GetLoginId();
    virtual bool        IsLoginIdValid(void);
    virtual char*       GetSerialNumber(void);
    virtual int         GetAlarmInportNum(void);
    virtual int         GetAlarmOutportNum(void);
    virtual int         GetDiskNum(void);
    virtual int         GetDvrType(void);
    virtual int         GetChannelNum(void);
    virtual int         GetStartChannelNum(void);
private:
    CDevInfo *m_devInfo;
    LONG     m_lUserID;
    NET_DVR_DEVICEINFO_V30 m_netDevceInfo;
};