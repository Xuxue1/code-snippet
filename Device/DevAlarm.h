#ifndef _DEVALARM_H_
#define _DEVALARM_H_

class IDevAlarm
{ 
public:
    virtual ~IDevAlarm() = 0;
    virtual bool StartService() = 0;
    virtual bool StopService() = 0;
    virtual bool StartListen() = 0;
    virtual bool StopListen() = 0;
    virtual void RegisterAlarmCallback(void* alarmCallBack, void* userParams) = 0;
};


#endif