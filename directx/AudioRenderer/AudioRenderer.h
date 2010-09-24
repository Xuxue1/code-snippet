#ifndef _AUDIO_RENDERER_H_
#define _AUDIO_RENDERER_H_

#include <dsound.h>
typedef unsigned int (*MediaAudioCallback)(void *lpData, void *buffer, unsigned int size);

class CAudioRender
{

public:
    CAudioRender();
    ~CAudioRender();
    LPDIRECTSOUND       lpDirectSound;
    LPDIRECTSOUNDBUFFER lpBuffer;
    WAVEFORMATEX       *ourFormat;

    DWORD               dwBufferSize;
    DWORD               dwNextWriteOffset;
    DWORD               dwProgress;
    DWORD               dwLastPlayPos;

    unsigned long       dwPlayed;

    HANDLE              audioThread;
    UINT                uTimerID;
    LONG                lInTimer;
    DWORD               id;

    MediaAudioCallback  callback;
    void               *lpData;
    int                 paused;


    HRESULT     Open(HWND hwnd, WAVEFORMATEX *inFormat);

    HRESULT     SetCallback(void *lpData, MediaAudioCallback callback);
    HRESULT     SetVolume(unsigned int volume);

    unsigned long GetAudioTime();
    HRESULT     Bufferize();

    HRESULT     Start();
    HRESULT     Pause();
    HRESULT     Stop();

    HRESULT     Close();
};

#endif