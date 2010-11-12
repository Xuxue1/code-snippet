// ImageButton.cpp : implementation file
//

#include "stdafx.h"
#include "ButtonEx.h"
#include "ImageButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageButton

CImageButton::CImageButton() : m_strText(""),
                               m_nXpos(-1),
                               m_nYpos(-1),
                               m_uPos(DT_SINGLELINE | DT_CENTER | DT_VCENTER),
                               m_bLoaded(FALSE),
                               m_clrTextUpDwn(RGB(255,255,255)),
                               m_clrTextDisable(RGB(255,255,255))
{
}

CImageButton::~CImageButton()
{
    m_ImageList.DeleteImageList();
    m_Font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CImageButton, CButton)
	//{{AFX_MSG_MAP(CImageButton)
	ON_WM_ENABLE()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageButton message handlers

void CImageButton::PreSubclassWindow() 
{
	// 改变按钮类型具有自画功能
	ModifyStyle(0, BS_OWNERDRAW | BS_PUSHBUTTON);	
	
	CButton::PreSubclassWindow();
}

void CImageButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	if( lpDrawItemStruct->CtlType != ODT_BUTTON)
		return;
	//To keep the text color 
	COLORREF clrText;
	int nImgCount =0;
	//Keeps the index of the image(based on 0) to be drawn
	int nPosImg=0;

	CDC *pDC = CDC::FromHandle( lpDrawItemStruct->hDC );
	if(!m_bLoaded)
	{
		m_rcBtn = lpDrawItemStruct->rcItem;
	}
	else
	{
		//Gets the number of image in the image list
		nImgCount = m_ImageList.GetImageCount();
		::SetWindowPos(lpDrawItemStruct->hwndItem,NULL,m_rcBtn.left,m_rcBtn.top,m_bitmap.bmWidth,m_bitmap.bmHeight,SWP_NOMOVE);
	}

	pDC->DrawFrameControl( &m_rcBtn ,DFC_BUTTON , DFCS_BUTTONPUSH|DFCS_PUSHED);

	if(ODS_DISABLED & lpDrawItemStruct->itemState)
	{
		if( m_bLoaded )
		{
			if(3== nImgCount)
				nPosImg = 2;
			else
				nPosImg =0;
		} 
		clrText = m_clrTextDisable;
	}
	else if(ODS_SELECTED & lpDrawItemStruct->itemState)
	{
		if( m_bLoaded )
		{
			if(2 <= nImgCount )
				nPosImg = 1;
			else
				nPosImg =0;
		}
		clrText = m_clrTextUpDwn;
	}
	else 
	{
		if( m_bLoaded )
		{
			nPosImg =0;
		}
		clrText = m_clrTextUpDwn;
	}
	if( m_bLoaded )
	{
		//将图形链表里某幅图形画在相应的设备上
		m_ImageList.DrawIndirect( 
	                           pDC , 
	                           nPosImg , 
	                           CPoint( m_rcBtn.left,m_rcBtn.top ), 
	                           CSize( m_bitmap.bmWidth , m_bitmap.bmHeight ), 
	                           CPoint( 0 , 0 ) , 
	                           ILD_NORMAL 
	                          );
	}
	
	if(!m_strText.IsEmpty())
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor( clrText);
	  
		HFONT hOldFont=NULL;
		//Sets the font
		if(m_Font.GetSafeHandle() != NULL)
		{
			hOldFont =(HFONT) pDC->SelectObject(m_Font.GetSafeHandle());
		}
		if(m_nYpos!=-1 && m_nXpos!=-1)
		{
			pDC->TextOut(m_nXpos,m_nYpos,m_strText);
		}
		else
		{
			pDC->DrawText( m_strText, m_rcBtn , m_uPos);
		}
		//Reset the old font
		if(hOldFont != NULL)
		{
			pDC->SelectObject(hOldFont);
		}
	}	
}

void CImageButton::OnEnable(BOOL bEnable) 
{
	CButton::OnEnable(bEnable);
	
	// 重画按钮
	Invalidate(TRUE);	
}

void CImageButton::OnSetFocus(CWnd* pOldWnd) 
{
	CButton::OnSetFocus(pOldWnd);
	
	// 重画按钮
	Invalidate(TRUE);	
}

void CImageButton::SetButtonImg(UINT uImageIDU,UINT uImgIDD, UINT uImgIDX  )
{
	CBitmap bitmapImage;
	if( m_bLoaded )
	{
		m_ImageList.DeleteImageList();
		m_bLoaded = FALSE;
	}
	//Loading Bitmap
	if( bitmapImage.LoadBitmap( uImageIDU ) ) 
	{
		bitmapImage.GetObject( sizeof( m_bitmap ) , &m_bitmap );
		m_rcBtn.top =0;m_rcBtn.left =0;
		m_rcBtn.right = m_bitmap.bmWidth; m_rcBtn.bottom =m_bitmap.bmHeight;

		if( m_ImageList.Create( m_bitmap.bmWidth , m_bitmap.bmHeight , ILC_COLORDDB,  1 , 2 ) ) 
		{
			m_ImageList.Add( &bitmapImage ,&bitmapImage);
		    if(0 !=uImgIDD)
		    {
				bitmapImage.DeleteObject();
				bitmapImage.LoadBitmap( uImgIDD );
				m_ImageList.Add( &bitmapImage ,&bitmapImage);
			    if(0 !=uImgIDX)
			    {
					bitmapImage.DeleteObject();
					bitmapImage.LoadBitmap( uImgIDX );
					m_ImageList.Add( &bitmapImage ,&bitmapImage);		      
			    }
			}
		    bitmapImage.DeleteObject();
		    m_bLoaded = TRUE;
		}
	}
}

void CImageButton::SetButtonText(const CString &strCaption)
{
	m_strText = strCaption;
}

//Function used for setting the position of the Text in the button according X y position
void CImageButton::SetTextPosition(int nXPos , int nYPos)
{
	m_nXpos = nXPos;
	m_nYpos = nYPos;
}

//Function used for setting the position of the Text in the button according to the center, left etc
void CImageButton::SetTextPosition(UINT uPos )
{
	m_uPos = uPos;
}
void CImageButton::SetTextColor(const COLORREF &clrUpDwn,const COLORREF &clrDisabled)
{
    m_clrTextUpDwn    = clrUpDwn;
    m_clrTextDisable = clrDisabled;
}

void CImageButton::SetFont(CString srtFntName_i, int nSize_i)
{
	LOGFONT lfCtrl = {0};
	lfCtrl.lfOrientation	= 0 ;
	lfCtrl.lfEscapement		= 0 ;

	lfCtrl.lfHeight			= nSize_i;
		
	lfCtrl.lfItalic  = FALSE;
	lfCtrl.lfUnderline = FALSE;
	lfCtrl.lfStrikeOut = FALSE;

	lfCtrl.lfCharSet		= DEFAULT_CHARSET;
	lfCtrl.lfQuality		= DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision	= OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily	= DEFAULT_PITCH;
	_tcscpy(lfCtrl.lfFaceName, srtFntName_i);
	
	//Normal Font
	lfCtrl.lfWeight			= FW_NORMAL;	
	m_Font.CreateFontIndirect( &lfCtrl);
}

