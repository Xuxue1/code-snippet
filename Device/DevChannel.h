#ifndef _DEVCHANNEL_H
#define _DEVCHANNEL_H
#include <string.h>
#include <Windows.h>
class CDevice;
class IDevPreview;
class IDevCtlPtz;
class IDevAlarm;

using namespace std;

class CDevChannel
{
public:
    CDevChannel(int nChannelIdx, CDevice *device);
    ~CDevChannel();
    CDevice *GetDevice() { return m_Device; }
    int GetChannelIdx() const { return m_nChannelIdx; }
    void SetChannelName(string channelName) { m_strChannelName = channelName; }
    StartDVRRecord();
    IDevPreview *GetPreview(HWND wnd);
    virtual IDevCtlPtz  *GetCtlPtz();
    virtual IDevAlarm   *GetAlarm();
protected:
    virtual bool CreatePreview();
    virtual bool CreateCtlPtz();
    virtual bool CreateAlarm();
    string      m_strChannelName;
    int         m_nChannelIdx;
    CDevice     *m_Device;
    IDevPreview *m_Preview;
    IDevCtlPtz  *m_CtlPtz;
    IDevAlarm   *m_Alarm;
};

CDevChannel::CreatePreview()
{
    if (m_Device == NULL)
    {
        return;
    }
    m_Device->GetDevType();
        
}

#endif