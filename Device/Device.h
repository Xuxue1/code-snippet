#include "DevChannel.h"
class CDevice
{
public:
    CDevice(int type, const unsigned int iDevIdx, IDevUserLogin *usrLogin);
    OpenChannel(unsigned int uChannelID);
    CloseChannel(unsigned int uChannelID);
    AddChannel();
    RevomeChannel();
    int GetDevIdx() { return m_nDevIdx; }
    int GetDevType  { return m_nType; }
    IDevUserLogin *GetDevUserLogin() { return m_DevUserLogin; }
    CDevConfig    *GetDevConfig(){ m_DevConfig; }
private:
    int m_nType;
    int m_nDevIdx;
    std::vector<unsigned int> m_uChannelIdxs;
    std::deque<CDevChannel *> m_QChannels;
    CDevConfig    *m_DevConfig;
    IDevUserLogin *m_DevUserLogin;
};
