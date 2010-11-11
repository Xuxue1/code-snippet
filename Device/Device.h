#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <map>
class IDevUserLogin;
class CDevConfig;
class CDevChannel;
class CDevice
{
public:
    CDevice(int type, const unsigned int iDevIdx, IDevUserLogin *usrLogin);
    virtual ~CDevice();
    CDevChannel *GetDevChannel(const unsigned int channelIdx);
    int GetDevIdx() const  { return m_nDevIdx; }
    int GetDevType() const { return m_nType; }
    IDevUserLogin *GetDevUserLogin() { return m_DevUserLogin; }
    CDevConfig    *GetDevConfig()    { return m_DevConfig; }
private:
    int m_nType;
    int m_nDevIdx;
    std::map<unsigned int, CDevChannel *> m_mapChannels;
    CDevConfig    *m_DevConfig;
    IDevUserLogin *m_DevUserLogin;
};

#endif

