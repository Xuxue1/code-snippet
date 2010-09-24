#include "stdafx.h"
#include "D3DDisplay.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define D3D_ARGB32              1
#define D3D_YUV422              2

#define IMAGE_WIDTH             352
#define IMAGE_HEIGHT            288

#define YUVPLANE IMAGE_WIDTH*IMAGE_HEIGHT*3/2
#define RGBPLANE IMAGE_WIDTH*IMAGE_HEIGHT*4

struct CUSTOMVERTEX
{     
	float x,y,z,rhw;	//顶点坐标 
    DWORD color;		//顶点颜色 
	float tu,tv;		//纹理坐标 
}; 

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)


CD3DDisplay::CD3DDisplay()
{
	m_pd3dDevice = NULL;
	m_pD3D = NULL;
    m_p2Dfont = NULL;

	m_pTexturesvideo = NULL;
	m_pVBvideo = NULL;

	m_pTexturesbmp = NULL;
	m_pVBbmp = NULL;

	m_hWnd = NULL;
	m_Format = (D3DFORMAT)0;
}

CD3DDisplay::~CD3DDisplay()
{
	ClearD3D();	
}

HRESULT CD3DDisplay::InitD3D(HWND hWnd)
{
    D3DPRESENT_PARAMETERS d3dpp;
	
	if(hWnd == NULL)
		return -1;
	m_hWnd = hWnd;
	
	m_Format = D3DFMT_A8R8G8B8;

    if(NULL == (m_pD3D = Direct3DCreate9( D3D_SDK_VERSION )))
        return -1;
	
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.BackBufferWidth = IMAGE_WIDTH;
    d3dpp.BackBufferHeight = IMAGE_HEIGHT;
	
    if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
		&d3dpp, &m_pd3dDevice ) ) )
        return -1;
    
	// Texture coordinates outside the range [0.0, 1.0] are set 
	// to the texture color at 0.0 or 1.0, respectively.
	m_pd3dDevice->SetSamplerState( 0, D3DSAMP_ADDRESSU,  D3DTADDRESS_CLAMP );
	m_pd3dDevice->SetSamplerState( 0, D3DSAMP_ADDRESSV,  D3DTADDRESS_CLAMP );
	
	// Set linear filtering quality
	m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
	m_pd3dDevice->SetSamplerState( 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );
	
	// set maximum ambient light
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENT,RGB(255,255,255));
	
	// Turn off culling
	m_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
	
	// Turn on the zbuffer
	m_pd3dDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	
	// Turn off lights
	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING,FALSE);
	
	// Enable dithering
	m_pd3dDevice->SetRenderState(D3DRS_DITHERENABLE, TRUE);
	
	// disable stencil
	m_pd3dDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
	
	// manage blending
	m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	
	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	
	m_pd3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	
	m_pd3dDevice->SetRenderState(D3DRS_ALPHAREF, 0x10);
	
	m_pd3dDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	
	// Modulate diffuse color of the vertex with texture color (50% and 50%)
	// then when we set color of lower vertices of the flag to background color,
	// it blends with texture and gives coloring of the lower part of the flag
	// correspondent to the background
	m_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_MODULATE );
	m_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
	m_pd3dDevice->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
	
	// turn off alpha operation
	m_pd3dDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP,   D3DTOP_DISABLE );
    
    return 0;
}

void CD3DDisplay::ClearD3D()
{
	if(m_pd3dDevice != NULL)
		m_pd3dDevice->Release();
	if(m_pD3D != NULL)
		m_pD3D->Release(); 
	if(m_p2Dfont != NULL)
		m_p2Dfont->Release(); 

	if(m_pVBvideo != NULL)
		m_pVBvideo->Release();
	if(m_pTexturesvideo != NULL)
		m_pTexturesvideo->Release();

	if(m_pVBbmp != NULL)
		m_pVBbmp->Release(); 
	if(m_pTexturesbmp != NULL)
		m_pTexturesbmp->Release(); 

	m_hWnd = NULL;
	m_Format = (D3DFORMAT)0;
}

HRESULT CD3DDisplay::CreateTexture()
{
    HRESULT hr = 0;
    D3DSURFACE_DESC ddsd;
	
	hr = m_pd3dDevice->CreateTexture( IMAGE_WIDTH, IMAGE_HEIGHT, 1, 0, m_Format, 
		D3DPOOL_MANAGED, &m_pTexturesvideo, NULL);
	if( FAILED(hr))
	{
		return -1;
	}
	
	hr = m_pTexturesvideo->GetLevelDesc( 0, &ddsd );
	if(FAILED(hr))
		return -1;
	
	if ((ddsd.Format != D3DFMT_A8R8G8B8) && (ddsd.Format != D3DFMT_YUY2)) 
		return -1;

    return 0;
}

HRESULT CD3DDisplay::InitGeometry()
{
    HRESULT hr = 0;
    CUSTOMVERTEX* pVertices = NULL;
    RECT rect;
	
	//创建视频矩形
	rect.top = 0;			
	rect.left = 0;
	rect.right = IMAGE_WIDTH;
	rect.bottom = IMAGE_HEIGHT;
	
	CUSTOMVERTEX vertices[4] =  
	{
		{ (float)rect.left, (float)rect.top, 
			0.0f, 1.0f,	D3DCOLOR_XRGB(255,255,255), 0.0f, 0.0f }, 
		{ (float)rect.right, (float)rect.top, 
		0.0f, 1.0f, D3DCOLOR_XRGB(255,255,255), 1.0f, 0.0f }, 
		{ (float)rect.left, (float)rect.bottom, 
		0.0f, 1.0f, D3DCOLOR_XRGB(255,255,255), 0.0f, 1.0f }, 
		{ (float)rect.right, (float)rect.bottom, 
		0.0f, 1.0f, D3DCOLOR_XRGB(255,255,255), 1.0f, 1.0f }
	};
	
	m_pd3dDevice->CreateVertexBuffer(sizeof(vertices), 
		0, 
		D3DFVF_CUSTOMVERTEX, 
		D3DPOOL_DEFAULT, 
		&m_pVBvideo, NULL ); 
	
	m_pVBvideo->Lock( 0, sizeof(vertices), (void**)&pVertices, 0 ); 
	
	memcpy( pVertices, vertices, sizeof(vertices)); 
	m_pVBvideo->Unlock(); 	

    return hr;
}

HRESULT CD3DDisplay::RenderSample(BYTE *pSampleBuffer)
{
    HRESULT hr = 0;
	
    BYTE * pTextureBuffer = NULL;
	
    D3DLOCKED_RECT d3dlr;
    LONG  lTexturePitch;     
	
	hr = m_pTexturesvideo->LockRect( 0, &d3dlr, 0, 0 );
	if( FAILED(hr))
	{
		return -1;
	}
	
	lTexturePitch = d3dlr.Pitch;
	pTextureBuffer = static_cast<byte *>(d3dlr.pBits);

	for(int i = 0; i < IMAGE_HEIGHT; i++ ) 
	{
		BYTE *pBmpBufferOld = pSampleBuffer;
		BYTE *pTxtBufferOld = pTextureBuffer;   
		
		for (int j = 0; j < IMAGE_WIDTH; j++) 
		{
			pTextureBuffer[0] = pSampleBuffer[0];
			pTextureBuffer[1] = pSampleBuffer[1];
			pTextureBuffer[2] = pSampleBuffer[2];
			pTextureBuffer[3] = 0xFF;
			
			pTextureBuffer += 4;
			pSampleBuffer  += 3;
		}
		
		pSampleBuffer  = pBmpBufferOld + IMAGE_WIDTH *3;
		pTextureBuffer = pTxtBufferOld + lTexturePitch;
	}

	hr = m_pTexturesvideo->UnlockRect(0);
	if( FAILED(hr))
	{
		return -1;
	}
	
    return 0;
}

HRESULT CD3DDisplay::RenderTOSrceen()
{
    HRESULT hr = 0;

	hr = m_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0 );
	if( FAILED(hr))
	{
		return -1;
	}

	hr = m_pd3dDevice->BeginScene();
	if( FAILED(hr))
	{
		return -1;
	}
	
	//显示视频
	hr = m_pd3dDevice->SetTexture( 0, m_pTexturesvideo );
	m_pd3dDevice->SetStreamSource( 0, m_pVBvideo, 0, sizeof(CUSTOMVERTEX)); 
	hr = m_pd3dDevice->SetVertexShader( NULL );
	m_pd3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX ); 
	m_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2 ); 
	m_pd3dDevice->SetTexture( 0, NULL ); 

	m_pd3dDevice->EndScene();
	
	m_pd3dDevice->Present( NULL, NULL, NULL, NULL );
	
	return hr;
}

int CD3DDisplay::GetFormt()
{
    return D3D_ARGB32;	
}
