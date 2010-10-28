#include "DevChannel.h"
class CDevice
{
public:
    CDevice(IDevUserLogin *usrLogIn, int type);
    OpenChannel();
    CloseChannel();
    AddChannel();
    RevomeChannel();
private:
    int m_nType;
    std::vector<unsigned int> m_uChannelId;
    IDevUserLogin *m_DevUserLogin;
};
