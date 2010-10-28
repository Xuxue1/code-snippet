#include "Device.h"
#include "DevPreview.h"
#include "DevCtlPtz.h"
#include "DevAlarm.h"
class CDeviceFactory
{
    CDevice* CreateDevice(const unsigned int iDevIdx);
};

class CDevMgr
{
public:
    CDevMgr();
    ~CDevMgr();
    BOOL AddDevice(CDevice*);
    void RemoveDevice(CDevice*);
    CDevice* GetDevice(const unsigned int iDevIdx);
    /// 获取通道中预览模块的操作
    IDevPreview* GetPreview(const unsigned int iDevIdx, const unsigned int iChannelIdx);
    /// 获取通道中云台控制模块的操作
    IDevCtlPtz*  GetCtlPtz(const unsigned int iDevIdx, const unsigned int iChannelIdx);
    /// 获取通道中告警模块的操作
    IDevAlarm*   GetAlarm(const unsigned int iDevIdx, const unsigned int iChannelIdx);
private:
    std::deque<CDevice*>  m_QDevice;
};
