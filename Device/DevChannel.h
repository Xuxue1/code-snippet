class CDevChannel
{
pubilc:
    CDevChannel(int nChannelIdx, CDevice *device);
    ~CDevChannel();
    CDevice *GetDevice() { return m_Device; }
    int GetChannelIdx() { return m_nChannelIdx; }
    virtual IDevPreview *GetPreview(HWND);
    virtual IDevCtlPtz  *GetCtlPtz();
    virtual IDevAlarm   *GetAlarm();
protected:
    virtual BOOL CreatePreview();
    virtual BOOL CreateCtlPtz();
    virtual BOOL CreateAlarm();
    int         m_nChannelIdx;
    CDevice     *m_Device;
    IDevPreview *m_Preview;
    IDevCtlPtz  *m_CtlPtz;
    IDevAlarm   *m_Alarm;
};
