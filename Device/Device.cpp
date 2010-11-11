#include "Device.h"
#include "DevChannel.h"
#include "DevConfig.h"

CDevice::CDevice(int type, const unsigned int iDevIdx, IDevUserLogin *usrLogin)
{
    m_nDevIdx = iDevIdx;
    m_nType   = type;
    m_DevUserLogin = usrLogin;
}

CDevice::~CDevice()
{
    if (m_DevConfig != NULL)
    {
        delete m_DevConfig;
        m_DevConfig = NULL;
    }
    if (m_DevUserLogin != NULL)
    {
        delete m_DevUserLogin;
        m_DevUserLogin = NULL;
    }
    
}

CDevChannel *CDevice::GetDevChannel(const unsigned int channelIdx)
{
    std::map<unsigned int, CDevChannel *>::iterator i = m_mapChannels.find(channelIdx);
    if (i != m_mapChannels.end())
    {
        return (*i).second;
    }
    return NULL;
}