#include "DevMgr.h"
#include "Device.h"
#include "DevChannel.h"
#include "DevPreview.h"
#include "DevAlarm.h"
#include "DevUserLogin.h"

CDevice *CDeviceFactory::CreateDevice(int type, const unsigned int iDevIdx, IDevUserLogin *usrLogin)
{
    if (usrLogin == NULL)
    {
        return NULL;
    }
    if (usrLogin->HasLogedin() == false)
    {
        usrLogin->Login();            
    }
    CDevice *dev = NULL;
    switch (type)
    {
   
    }    
    return dev;  
}

void CDeviceFactory::DestroyDevice(CDevice *device)
{
    if (device != NULL)
    {
        delete device;
    }
    return;
}

CDevMgr::CDevMgr()
{
    m_listDevice.clear();
}

CDevMgr::~CDevMgr()
{
    m_listDevice.clear();
}


bool CDevMgr::AddDevice(CDevice *device)
{
    if (device != NULL)
    {
        m_listDevice.push_back(device);
        return true;
    }
    return false;
}

bool CDevMgr::RemoveDevice(CDevice *device)
{
    for (std::list<CDevice *>::iterator it = m_listDevice.begin(); it != m_listDevice.end(); ++it)
    {
        if (*it == device)
        {
            m_listDevice.erase(it);
            return true;
        }
    }
    return false;
}

bool CDevMgr::RemoveDevice(const unsigned int iDevIdx)
{
    for (std::list<CDevice *>::iterator it = m_listDevice.begin(); it != m_listDevice.end(); ++it)
    {
        if ((*it)->GetDevIdx() == iDevIdx)
        {
            m_listDevice.erase(it);
            return true;
        }
    }
    return false;
}

CDevice *CDevMgr::GetDevice(const unsigned int iDevIdx)
{
    for (std::list<CDevice *>::iterator it = m_listDevice.begin(); it != m_listDevice.end(); ++it)
    {
        if ((*it)->GetDevIdx() == iDevIdx)
        {
            return *it;
        }
    }
    return NULL;
}

CDevChannel *CDevMgr::GetDevChannel(const unsigned int iDevIdx, const unsigned int iChannelIdx)
{
    CDevice * device = GetDevice(iDevIdx);
    if (device == NULL)
    {
        return NULL;
    }
    return device->GetDevChannel(iChannelIdx);
}

IDevPreview *CDevMgr::GetPreview(const unsigned int iDevIdx, const unsigned int iChannelIdx)
{
    CDevice * device = GetDevice(iDevIdx);
    if (device == NULL)
    {
        return NULL;
    }

}


IDevCtlPtz *CDevMgr::GetCtlPtz(const unsigned int iDevIdx, const unsigned int iChannelIdx)
{
    CDevice * device = GetDevice(iDevIdx);
    if (device == NULL)
    {
        return NULL;
    }
}

IDevAlarm  *CDevMgr::GetAlarm(const unsigned int iDevIdx, const unsigned int iChannelIdx)
{
    CDevice * device = GetDevice(iDevIdx);
    if (device == NULL)
    {
        return NULL;
    }
}