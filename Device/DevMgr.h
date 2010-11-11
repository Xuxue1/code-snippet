#ifndef _DEVMGR_H_
#define _DEVMGR_H_

#include <list>
class CDevice;
class IDevPreview;
class IDevCtlPtz;
class IDevAlarm;
class IDevUserLogin;
class CDevChannel;

class CDeviceFactory
{
public:
    static CDevice* CreateDevice(int type, const unsigned int iDevIdx, IDevUserLogin *usrLogin);
    static void DestroyDevice(CDevice *device);
};

class CDevMgr
{
public:
    CDevMgr();
    ~CDevMgr();
    bool AddDevice(CDevice *device);
    bool RemoveDevice(CDevice *device);
    bool RemoveDevice(const unsigned int iDevIdx);
    CDevice *GetDevice(const unsigned int iDevIdx);
    CDevChannel *GetDevChannel(const unsigned int iDevIdx, const unsigned int iChannelIdx);
    /// 获取通道中预览模块的操作
    IDevPreview *GetPreview(const unsigned int iDevIdx, const unsigned int iChannelIdx);
    /// 获取通道中云台控制模块的操作
    IDevCtlPtz *GetCtlPtz(const unsigned int iDevIdx, const unsigned int iChannelIdx);
    /// 获取通道中告警模块的操作
    IDevAlarm  *GetAlarm(const unsigned int iDevIdx, const unsigned int iChannelIdx);
private:
    std::list<CDevice *>  m_listDevice;
};

#endif 