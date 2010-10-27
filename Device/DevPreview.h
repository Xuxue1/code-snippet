class IDevPreview
{
public:
    void SetPlayWnd(HWND) = 0;
    HWND GetPlayWnd() = 0;
    BOOL StartRealPlay() = 0;
    BOOL StopRealPlay()  = 0;
    BOOL CaptureFrame() = 0;
    BOOL StartRecording() = 0;
    BOOL StopRecording() = 0;
};
