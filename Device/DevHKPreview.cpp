#include "DevHKPreview.h"

CDevHKPreview::CDevHKPreview()
{
    m_lRealHandle       = -1;
    m_hWND              = NULL;
    m_dwBrightValue     = 128;
    m_dwContrastValue   = 128;
    m_dwSaturationValue = 128;
    m_dwHueValue        = 128;
}

CDevHKPreview::~CDevHKPreview()
{

}

bool CDevHKPreview::SetPlayWnd(HWND hWnd)
{
    if (hWnd == NULL)
    {
        return false;
    }

    m_hWND = hWnd;
    return true;
}

bool CDevHKPreview::StartRealPlay()
{

    NET_DVR_CLIENTINFO ;
    NET_DVR_RealPlay_V30();
}

bool CDevHKPreview::StopRealPlay()
{
    if (IsPlaying())
    {
        NET_DVR_StopRealPlay(m_lRealHandle);
        m_lRealHandle = -1;
    }
    return true;
}

bool CDevHKPreview::CaptureFrame(char *sPicFileName)
{
    NET_DVR_CapturePicture(m_lRealHandle, sPicFileName);
}

bool CDevHKPreview::RegisterDrawFun()
{

}

bool CDevHKPreview::IsPlaying()
{
    return m_bIsPlaying;
}

bool CDevHKPreview::IsRecording()
{
    return m_bIsRecording;
}

bool CDevHKPreview::GetVideoEffect(DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue)
{
    NET_DVR_ClientGetVideoEffect(m_lRealHandle, pBrightValue, pContrastValue, pSaturationValue, pHueValue);
    return true;
}

bool CDevHKPreview::SetVideoEffect(DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue)
{
    NET_DVR_ClientSetVideoEffect(m_dwBrightValue, m_dwContrastValue, m_dwSaturationValue, m_dwHueValue);
    return true;
}

bool CDevHKPreview::OpenSound()
{
    return true;
}

bool CDevHKPreview::CloseSound()
{
    return true;
}

bool CDevHKPreview::SetAudioMode(DWORD dwMode)
{
    return true;
}

bool CDevHKPreview::SetVolume(int nVolume)
{

    return true;
}

bool CDevHKPreview::StartRecording()
{

}