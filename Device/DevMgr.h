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
    /// ��ȡͨ����Ԥ��ģ��Ĳ���
    IDevPreview* GetPreview(const unsigned int iDevIdx, const unsigned int iChannelIdx);
    /// ��ȡͨ������̨����ģ��Ĳ���
    IDevCtlPtz*  GetCtlPtz(const unsigned int iDevIdx, const unsigned int iChannelIdx);
    /// ��ȡͨ���и澯ģ��Ĳ���
    IDevAlarm*   GetAlarm(const unsigned int iDevIdx, const unsigned int iChannelIdx);
private:
    std::deque<CDevice*>  m_QDevice;
};
