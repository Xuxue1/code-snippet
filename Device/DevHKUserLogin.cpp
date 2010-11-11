#include <Windows.h>
#include "DevInfo.h"
#include "DevHKUserLogin.h"
#include "includeHK\HCNetSDK.h"


CDevHKUserLogin::CDevHKUserLogin(CDevInfo *devInfo)
{
    m_devInfo = devInfo;
    m_lUserID = -1;
    ZeroMemory(&m_netDevceInfo, sizeof(m_netDevceInfo));
}

CDevHKUserLogin::~CDevHKUserLogin()
{
    Logout();
    if (m_devInfo != NULL)
    {
        delete m_devInfo;
    }   
}

int CDevHKUserLogin::Login()
{
    if (m_devInfo == NULL)
    {
        return -1;
    }

    m_lUserID = NET_DVR_Login_V30((char *)(m_devInfo->GetIPAddr()), m_devInfo->GetPort(), (char *)(m_devInfo->GetUserName()), m_devInfo->GetPassWord(), &m_netDevceInfo);
    return m_lUserID;
}

int CDevHKUserLogin::Logout()
{
    if (HasLogedin())
    {
        NET_DVR_Logout_V30(m_lUserID);
        m_lUserID = -1;
    }
    return 0;
}

bool CDevHKUserLogin::HasLogedin()
{
    return (m_lUserID != -1);
}

int CDevHKUserLogin::GetAlarmInportNum()
{
    if (m_lUserID == -1)
    {
        return -1;
    }
    return m_netDevceInfo.byAlarmInPortNum;
}

char* CDevHKUserLogin::GetSerialNumber()
{
    if (m_lUserID == -1)
    {
        return NULL;
    }
    return (char *)m_netDevceInfo.sSerialNumber;
}

int CDevHKUserLogin::GetDiskNum(void)
{
    if (m_lUserID == -1)
    {
        return -1;
    }
    return m_netDevceInfo.byDiskNum;
}

int CDevHKUserLogin::GetAlarmOutportNum(void)
{
    if (m_lUserID == -1)
    {
        return -1;
    }
    return m_netDevceInfo.byAlarmOutPortNum;
}


int CDevHKUserLogin::GetDvrType(void)
{
    if (m_lUserID == -1)
    {
        return -1;
    }
    return m_netDevceInfo.byDVRType;
}

int CDevHKUserLogin::GetChannelNum(void)
{
    if (m_lUserID == -1)
    {
        return -1;
    }
    return m_netDevceInfo.byChanNum;
}

int CDevHKUserLogin::GetStartChannelNum(void)
{
    if (m_lUserID == -1)
    {
        return -1;
    }
    return m_netDevceInfo.byStartChan;
}