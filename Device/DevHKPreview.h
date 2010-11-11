#include "DevPreview.h"
#include "includeHK/HCNetSDK.h"

typedef void(CALLBACK *fDrawFun)(LONG  lRealHandle, HDC  hDc, DWORD dwUser);

class CDevHKPreview
    : public IDevPreview
{
public:
    CDevHKPreview();
    virtual bool SetPlayWnd(HWND hWnd);
    virtual HWND GetPlayWnd();
    virtual bool StartRealPlay();
    virtual bool StopRealPlay();
    virtual bool CaptureFrame(char *sPicFileName, int picType);
    virtual bool StartRecording();
    virtual bool StopRecording();
    virtual bool GetVideoEffect(DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
    virtual bool SetVideoEffect(DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
    virtual bool RegisterDrawFun(void *cbDrawFun, DWORD dwUser);
    virtual bool RegisterRealDataFun(void *cbRealDataFun);
    virtual bool ThrowBFrame();
    virtual bool MakeKeyFrame();
    virtual bool OpenSound();
    virtual bool CloseSound();
    virtual bool SetAudioMode(DWORD dwMode);
    virtual bool SetVolume(int nVolume);
private:
    bool IsPlaying();
    bool IsRecording();
    HWND  m_hWND;
    LONG  m_lRealHandle;
    DWORD m_dwUser;
    bool  m_bIsPlaying;
    bool  m_bIsRecording;
    DWORD m_dwBrightValue;
    DWORD m_dwContrastValue;
    DWORD m_dwSaturationValue;
    DWORD m_dwHueValue;
    DWORD m_nVolume;
    fDrawFun m_cbDrawFun;
    fRealDataCallBack_V30 m_cbRealDataFun;
};