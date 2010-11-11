#include <string>
#include <Windows.h>
#include "DevAlarm.h"
#include "includeHK/HCNetSDK.h"
using namespace std;

class CDevHKAlarm
{
public:
    CDevHKAlarm(LONG lUserID, string sLocalIP, WORD wLocalPort);
    virtual ~CDevHKAlarm();
    virtual bool StartService();
    virtual bool StopService();
    virtual bool StartListen();
    virtual bool StopListen();
    virtual void RegisterAlarmCallback(void* alarmCallBack, void* userParams);
private:
    LONG m_lUserID;
    LONG m_lAlarmHandle;
    LONG m_lListenHadle;
    string m_sLocalIP;
    WORD m_wLocalPort;
    MSGCallBack m_cbAlarm;
    void *m_pUserData;
};

