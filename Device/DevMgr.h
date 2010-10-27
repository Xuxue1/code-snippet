#include "Device.h"
class CDevMgr
{
    AddDevice();
    RemoveDevice();
    /// 获取通道的指针
    IDevChannel* GetChannel(const unsigned int iDvrIdx, const unsigned int iChannelIdx) ;
    /// 获取通道中预览模块的操作
    IDevPreview* GetPreview(const unsigned int iDvrIdx, const unsigned int iChannelIdx);
    /// 获取通道中云台控制模块的操作
    IDevCtlPtz*  GetCtlPtz(const unsigned int iDvrIdx, const unsigned int iChannelIdx);
    /// 获取通道中告警模块的操作
    IDevAlarm*   GetAlarm(const unsigned int iDvrIdx, const unsigned int iChannelIdx);
private:
    std::deque<CDevice*>  m_QDevice;
};
