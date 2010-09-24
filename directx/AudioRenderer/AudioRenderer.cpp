#include "AudioRenderer.h"
#define PERIOD 30

CAudioRender::CAudioRender()
{
	this->lpDirectSound = NULL;
	this->lpBuffer      = NULL;
}

CAudioRender::~CAudioRender()
{
}


media_type_t  CAudioRender::GetType()
{
	return MEDIA_TYPE_AUDIO_RENDERER;
}

char         *CAudioRender::GetName()
{
	return "DirectSound Audio Renderer";
}


	
HRESULT     CAudioRender::Connect(MediaItem *item)
{
	return HRESULT_ERROR;
}

HRESULT     CAudioRender::ReleaseConnections()
{
	return HRESULT_ERROR;
}

DWORD         CAudioRender::GetCaps()
{
	return 0;
}

HRESULT     CAudioRender::Configure(HINSTANCE hInstance, HWND hwnd)
{
	return HRESULT_ERROR;
}


HRESULT     CAudioRender::Open(HWND hwnd, WAVEFORMATEX *inFormat)
{
	if(hwnd && inFormat) {

		this->ourFormat = inFormat;

		HRESULT hr;
			
		if(DirectSoundCreate(NULL, &this->lpDirectSound, NULL) == DS_OK) {



			hr = lpDirectSound->SetCooperativeLevel(hwnd, DSSCL_NORMAL);

			if(hr != DS_OK) {

				this->lpDirectSound->Release();
				this->lpDirectSound = NULL;

				return HRESULT_ERROR;
			}

	

			DSBUFFERDESC  dsbdesc;
			WAVEFORMATEX  wf;
			
			memset(&dsbdesc, 0, sizeof(DSBUFFERDESC));
			dsbdesc.dwSize = sizeof(DSBUFFERDESC);
    
			ZeroMemory(&wf, sizeof(WAVEFORMATEX));
			memcpy(&wf, this->ourFormat, sizeof(WAVEFORMATEX));

			dsbdesc.lpwfxFormat = (LPWAVEFORMATEX) &wf;
    
			dsbdesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_GLOBALFOCUS;			
			dsbdesc.dwBufferBytes = 2 * this->ourFormat->nAvgBytesPerSec;

			hr = lpDirectSound->CreateSoundBuffer(&dsbdesc, &lpBuffer, NULL);

			if(hr != DS_OK) {

				this->lpDirectSound->Release();
				this->lpDirectSound = NULL;

				return HRESULT_ERROR;
			}
		

			this->dwBufferSize = 2 * this->ourFormat->nAvgBytesPerSec;
			this->lInTimer = FALSE;
		
			return HRESULT_OK;
		}
	}

	return HRESULT_ERROR;
}




HRESULT     CAudioRender::SetCallback(void *lpData, MediaAudioCallback callback)
{
	this->lpData   = lpData;
	this->callback = callback;

	return HRESULT_OK;
}

HRESULT     CAudioRender::SetVolume(unsigned int volume)
{
	if(this->lpBuffer) {

		double vol;

		vol = - ( 70*pow(10, (100.0 - (double) volume)*2.0/100.0) );

		if(this->lpBuffer != NULL)
			this->lpBuffer->SetVolume((int) vol);
	}

	return HRESULT_ERROR;
}

unsigned long CAudioRender::GetAudioTime()
{
	return (unsigned long) (( ((double) this->dwPlayed * (1000/(this->ourFormat->wBitsPerSample*this->ourFormat->nChannels/8)))) / (this->ourFormat->nSamplesPerSec));
}


void CALLBACK AudioTimeFunc(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
	CAudioRender *audioRenderer = (CAudioRender *) dwUser;
	
	if (InterlockedExchange(&audioRenderer->lInTimer, TRUE)) return;

	if(audioRenderer->callback) {
		
			void *buffer1, *buffer2;
			DWORD bytes1 = 0, bytes2 = 0;
			DWORD dwPlay, dwWrite, dwSize;

			audioRenderer->lpBuffer->GetCurrentPosition(&dwPlay, &dwWrite);

			if(audioRenderer->dwLastPlayPos == dwPlay) {
			
				InterlockedExchange(&audioRenderer->lInTimer, FALSE);
				return;
			}

			if(audioRenderer->dwLastPlayPos <= dwPlay) {

				dwSize = dwPlay - audioRenderer->dwLastPlayPos;

				audioRenderer->lpBuffer->Lock(audioRenderer->dwLastPlayPos,
											  dwSize,
											  &buffer1, &bytes1, 
											  &buffer2, &bytes2, 0);

				if(buffer1) {

					bytes1 = audioRenderer->callback(audioRenderer->lpData, buffer1, bytes1);
				}

				audioRenderer->lpBuffer->Unlock(buffer1, bytes1, buffer2, bytes2);

				audioRenderer->dwLastPlayPos += bytes1;
				audioRenderer->dwPlayed += bytes1;
			}
			else {

				DWORD bytes1_ori;

				dwSize = (audioRenderer->dwBufferSize - audioRenderer->dwLastPlayPos) + dwPlay;

				audioRenderer->lpBuffer->Lock(audioRenderer->dwLastPlayPos,
											  dwSize,
											  &buffer1, &bytes1, 
											  &buffer2, &bytes2, 0);

				bytes1_ori = bytes1;

				if(bytes1) {

					bytes1 = audioRenderer->callback(audioRenderer->lpData, buffer1, bytes1);
				}

				if(bytes2) {

					bytes2 = audioRenderer->callback(audioRenderer->lpData, buffer2, bytes2);
				}

				audioRenderer->lpBuffer->Unlock(buffer1, bytes1, buffer2, bytes2);

				audioRenderer->dwPlayed += bytes1 + bytes2;

				if(bytes1_ori == bytes1)
					audioRenderer->dwLastPlayPos = bytes2;
				else 
					audioRenderer->dwLastPlayPos += bytes1;
			}
			
			InterlockedExchange(&audioRenderer->lInTimer, FALSE);
			return;
	}
}



HRESULT     CAudioRender::Bufferize()
{
	if(this->lpBuffer) {

		void *buffer1, *buffer2;
		DWORD bytes1, bytes2, length;


		this->lpBuffer->SetCurrentPosition(0);

		this->lpBuffer->Lock(0, this->dwBufferSize,
							    &buffer1, &bytes1, &buffer2, &bytes2, 0);


		length = this->callback(this->lpData, buffer1, this->dwBufferSize);

		this->lpBuffer->Unlock(buffer1, bytes1, buffer2, bytes2);

		this->dwNextWriteOffset = this->dwProgress = this->dwPlayed = this->dwLastPlayPos = 0;
	}

	return HRESULT_OK;
}

HRESULT     CAudioRender::Start()
{
	if(this->lpBuffer) {

		void *buffer1, *buffer2;
		DWORD bytes1, bytes2, length;



		this->lpBuffer->SetCurrentPosition(0);

		this->lpBuffer->Lock(0, this->dwBufferSize,
							    &buffer1, &bytes1, &buffer2, &bytes2, 0);



		length = this->callback(this->lpData, buffer1, this->dwBufferSize);

		this->lpBuffer->Unlock(buffer1, length, buffer2, bytes2);

		this->dwProgress = this->dwPlayed = this->dwLastPlayPos = 0;



		this->paused = 0;
		
		if(this->lpBuffer->Play(0, 0, DSBPLAY_LOOPING) != DS_OK) {

			return HRESULT_ERROR;
		}
	
		if( timeBeginPeriod( PERIOD ) != 0 ) {
			
			return HRESULT_ERROR;
		}
        else {
			
			this->uTimerID = timeSetEvent( PERIOD, 5, AudioTimeFunc, (DWORD)(LPVOID)this, TIME_PERIODIC );
		}

		return HRESULT_OK;
	}

	return HRESULT_ERROR;
}

HRESULT  CAudioRender::Pause()
{
	if(this->paused) {

		this->paused = 0;
		this->lpBuffer->Play(0, 0, DSBPLAY_LOOPING);
		
		this->uTimerID = timeSetEvent( PERIOD, 5, AudioTimeFunc, (DWORD)(LPVOID)this, TIME_PERIODIC );
		
	}
	else {

		if(this->uTimerID) {

			timeKillEvent(this->uTimerID); 
 		}

		this->paused = 1;
		this->lpBuffer->Stop();
	}

	return S_OK;
}

HRESULT  CAudioRender::Stop()
{
	if(this->uTimerID) {

		timeKillEvent(this->uTimerID); 
 	}

	if(this->lpBuffer) {
		this->lpBuffer->Stop();
		timeEndPeriod(PERIOD); 
	}
	
	return S_OK;
}

HRESULT     CAudioRender::Close()
{
	this->Stop();

	if(this->lpDirectSound) {

		if(this->lpBuffer)
			this->lpBuffer->Release();

		this->lpBuffer = NULL;

		this->lpDirectSound->Release();

		this->lpDirectSound = NULL;
	}

	return S_OK;
}