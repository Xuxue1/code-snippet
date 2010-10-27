class CDevice
{
public:
    OpenChannel();
    CloseChannel();
    AddChannel();
    RevomeChannel();
private:
    int m_nType;
    std::vector<unsigned int> m_uChannelId;
};
