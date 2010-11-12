#if !defined(AFX_IMAGEBUTTON_H__BE5069FB_F96F_4E7B_B432_34F32CA53F15__INCLUDED_)
#define AFX_IMAGEBUTTON_H__BE5069FB_F96F_4E7B_B432_34F32CA53F15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImageButton window

class CImageButton : public CButton
{
// Construction
public:
	CImageButton();

public:
	void SetTextPosition(UINT uiPos );
	void SetTextPosition(int nXPos ,int nYPos);
	void SetTextColor(const COLORREF& clrUpDwn, const COLORREF& clrDisabled );
	void SetButtonText(const CString& strCaption);
	void SetButtonImg(UINT uiImageIDU,UINT uiImgIDD =0,UINT uiImgIDX = 0);
	void SetFont(CString srtFntName_i, int nSize_i);

    // Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImageButton)
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected:
   //Keep the size details of the bitmap loaded
   BITMAP      m_bitmap;
   //Keeps image list which keeps the images to be drawn for up/down and disabled states
   //of the button
   CImageList  m_ImageList;
   //Keeps the status of the image load
   BOOL        m_bLoaded;
   //Keeps the text to be shown in the button
   CString     m_strText;
   //Keeps the resized rect of the button
   CRect       m_rcBtn;
   //按钮正常和按下时文字的颜色
   COLORREF    m_clrTextUpDwn;
   //按钮无效时文字的颜色
   COLORREF    m_clrTextDisable;
   //文字开始的X位置
   int         m_nXpos ;
   //文字开始的Y位置
   int         m_nYpos;
   //Keeps the position of the Text like 
   UINT        m_uPos;
   CFont       m_Font;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEBUTTON_H__BE5069FB_F96F_4E7B_B432_34F32CA53F15__INCLUDED_)
