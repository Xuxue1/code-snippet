#if !defined(_D3DDISPLAY_H_)
#define _D3DDISPLAY_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <d3dx9.h>

class CD3DDisplay  
{
public:
	int GetFormt();
	HRESULT RenderSample(BYTE* pSampleBuffer);
	HRESULT RenderTOSrceen();
	HRESULT InitGeometry();
	HRESULT CreateTexture();
	HRESULT InitD3D(HWND hWnd);
	void ClearD3D();
	CD3DDisplay();
	virtual ~CD3DDisplay();
private:
	LPDIRECT3D9             m_pD3D; 
    LPDIRECT3DDEVICE9       m_pd3dDevice; 
    LPDIRECT3DTEXTURE9      m_pTexturesvideo; 
	LPDIRECT3DVERTEXBUFFER9 m_pVBvideo;		//��Ƶ���εĶ��㻺�����ӿ�ָ�� 
	LPDIRECT3DTEXTURE9      m_pTexturesbmp;
	LPDIRECT3DVERTEXBUFFER9 m_pVBbmp;       //λͼ���εĶ��㻺�����ӿ�ָ��

	HWND m_hWnd;
	D3DFORMAT m_Format;
	LPD3DXFONT m_p2Dfont;
};

#endif //
