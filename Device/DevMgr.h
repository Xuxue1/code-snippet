#include "Device.h"
class CDevMgr
{
    AddDevice();
    RemoveDevice();
    /// ��ȡͨ����ָ��
    IDevChannel* GetChannel(const unsigned int iDvrIdx, const unsigned int iChannelIdx) ;
    /// ��ȡͨ����Ԥ��ģ��Ĳ���
    IDevPreview* GetPreview(const unsigned int iDvrIdx, const unsigned int iChannelIdx);
    /// ��ȡͨ������̨����ģ��Ĳ���
    IDevCtlPtz*  GetCtlPtz(const unsigned int iDvrIdx, const unsigned int iChannelIdx);
    /// ��ȡͨ���и澯ģ��Ĳ���
    IDevAlarm*   GetAlarm(const unsigned int iDvrIdx, const unsigned int iChannelIdx);
private:
    std::deque<CDevice*>  m_QDevice;
};
