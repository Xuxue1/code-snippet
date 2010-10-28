class CDevChannel
{
pubilc:
    CDevChannel(int nChannel, CDevice *device);
    ~CDevChannel();
    CDevice *GetDevice();
    virtual IDevPreview *GetPreview(HWND);
    virtual IDevCtlPtz  *GetCtlPtz();
    virtual IDevAlarm   *GetAlarm();
private:
    BOOL CreatePreview();
    int m_nChannel;
    CDevice     *m_Device;
    IDevPreview *m_Preview;
    IDevCtlPtz  *m_CtlPtz;
    IDevAlarm   *m_Alarm;
};
