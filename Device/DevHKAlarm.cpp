#include "DevHKAlarm.h"

CDevHKAlarm::CDevHKAlarm(LONG lUserID, string sLocalIP, WORD wLocalPort)
{
    m_lUserID      = lUserID;
    m_lAlarmHandle = -1;
    m_sLocalIP     = sLocalIP;
    m_wLocalPort   = wLocalPort;
    m_pUserData    = NULL;
    m_cbAlarm      = NULL;
}

CDevHKAlarm::~CDevHKAlarm()
{
    m_lUserID      = -1;
    m_lAlarmHandle = -1;
}

bool CDevHKAlarm::StartService()
{
    if (m_lUserID != -1)
    {
        m_lAlarmHandle = NET_DVR_SetupAlarmChan_V30(m_lUserID);
    }
    
    if (m_lAlarmHandle == -1)
    {
        return false;
    }
    return true;
}

bool CDevHKAlarm::StopService()
{
    if (m_lAlarmHandle != -1)
    {
        NET_DVR_CloseAlarmChan_V30(m_lAlarmHandle);
    }
    return true;
}

bool CDevHKAlarm::StartListen()
{
    if (m_pUserData != NULL)
    {
        m_lListenHadle =  NET_DVR_StartListen_V30((char *)m_sLocalIP.c_str(), m_wLocalPort, m_cbAlarm, m_pUserData);
    }
    return NET_DVR_StartListen((char *)m_sLocalIP.c_str(), m_wLocalPort);
}

bool CDevHKAlarm::StopListen()
{
    if (m_lListenHadle != -1)
    {
        NET_DVR_StopListen_V30(m_lListenHadle);
    }
    else
    {
        NET_DVR_StopListen();
    }
    return true;
}