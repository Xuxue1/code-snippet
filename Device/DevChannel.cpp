#include "Device.h"
#include "DevChannel.h"
#include "DevPreview.h"
#include "DevAlarm.h"
#include "DevCtlPtz.h"
CDevChannel::CDevChannel(int nChannelIdx, CDevice *device)
{
    m_nChannelIdx = nChannelIdx;
    m_Device      = device;
    m_Preview     = NULL;
    m_CtlPtz      = NULL;
    m_Alarm       = NULL;
}

CDevChannel::~CDevChannel()
{
    if (m_Preview != NULL)
    {

    }
}