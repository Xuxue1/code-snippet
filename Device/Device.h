#include "DevChannel.h"
class CDevice
{
public:
    CDevice(IDevUserLogin *usrLogIn, int type);
    OpenChannel(unsigned int uChannelID);
    CloseChannel(unsigned int uChannelID);
    AddChannel();
    RevomeChannel();
private:
    int m_nType;
    std::vector<unsigned int> m_uChannelId;
    std::deque<CDevChannel *> m_QChannels;
    CDevConfig    *m_DevConfig;
    IDevUserLogin *m_DevUserLogin;
};
