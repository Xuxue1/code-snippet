#ifndef _DEVPREVIEW_H_
#define _DEVPREVIEW_H_
#include <Windows.h>
class IDevPreview
{
public:
    virtual bool SetPlayWnd(HWND) = 0;
    virtual HWND GetPlayWnd() = 0;
    virtual bool StartRealPlay() = 0;
    virtual bool StopRealPlay()  = 0;
    virtual bool CaptureFrame(char *sPicFileName) = 0;
    virtual bool StartRecording() = 0;
    virtual bool StopRecording() = 0;
    virtual bool GetVideoEffect(DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue) = 0;
    virtual bool SetVideoEffect(DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue) = 0;
    virtual bool RegisterDrawFun(void *cbDrawFun, DWORD dwUser) = 0;
    virtual bool OpenSound() = 0;
    virtual bool CloseSound() = 0;
    virtual bool SetAudioMode(DWORD dwMode) = 0;
    virtual bool SetVolume(int  nVolume) = 0;
};


#endif