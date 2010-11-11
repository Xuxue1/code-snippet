#ifndef _DEVINFO_H_
#define _DEVINFO_H_
#include <string>
using namespace std;
class CDevInfo
{
public:
    CDevInfo(string devAddr, string userName, string password, string multiIPAddr, 
             string dnsAddr, string manufacture, string devName, 
             int port, int channel, int serialNum, int addrType, int deviceType);
    void SetUserName(string userName);
    void SetPassword(string password);
    const char *GetIPAddr() { return m_strDevAddr.c_str(); }
    const char *GetUserName() { return m_strUserName.c_str(); }
    char *GetPassWord();
    char *GetMultIPAddr(); 
    int  GetPort();
private:
    string m_strDevAddr;///
    string m_strUserName;
    string m_strPassword;
    string m_strMultIPAddr;
    string m_strDNSAddr;
    string m_strManufacture;
    string m_strDevName;
    int    m_iPort; 
    int    m_iChannel;     
    int    m_iSerialNum;
    int    m_iAddrType;
    int    m_iDeviceType;
};

#endif