class CDevice
{
public:
    BOOL CreatChannel();
private:
    int m_nType;
    std::vector<unsigned int> m_uChannelId;
};
