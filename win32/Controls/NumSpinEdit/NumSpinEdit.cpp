// NumSpinEdit.cpp : implementation file
//

#include "stdafx.h"
#include "editex.h"
#include "NumSpinEdit.h"
#include "NumEdit.h"
#include "SpinCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumSpinEdit
const short SPIN_T = 0;
const short SPIN_R = 3;
const short SPIN_B = 3;
const short SPIN_W = 15;

CNumSpinEdit::CNumSpinEdit (UINT nID)
{
	m_nID = nID;
	
	m_pSpinCtrl = new CSpinCtrl();
	m_pNumEdit = new CNumEdit();
	m_clrText = RGB(0,0,0);

}


CNumSpinEdit::~CNumSpinEdit ()
{
	delete m_pSpinCtrl;
	delete m_pNumEdit;
}

BEGIN_MESSAGE_MAP(CNumSpinEdit, CWnd)
	//{{AFX_MSG_MAP(CNumSpinEdit)
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	ON_WM_KEYDOWN()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CNumSpinEdit message handlers

BOOL CNumSpinEdit::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if ( pMsg->message == WM_KEYDOWN  )
	{
		if (pMsg->wParam == VK_PRIOR  || pMsg->wParam == VK_NEXT ) 
		{
			OnKeyDown(pMsg->wParam , LOWORD(pMsg->lParam), HIWORD(pMsg->lParam));
			return TRUE;
		}
	}
	return FALSE;
}

int CNumSpinEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	CWnd::OnCreate(lpCreateStruct);
	int cx = lpCreateStruct->cx;
	int cy = lpCreateStruct->cy;
	int x = lpCreateStruct->x;
	int y = lpCreateStruct->y;
	CRect rect;
		CWnd* pParent = CWnd::FromHandle(lpCreateStruct->hwndParent);
	if( m_nID > 0 )
	{
		CWnd* pCtrlWnd = pParent->GetDlgItem(m_nID);
		pCtrlWnd->GetWindowRect(&rect);
		pParent->ScreenToClient(&rect);
		x = rect.left;
		y = rect.top ;
		cx = rect.Width();
		cy = rect.Height();
		pCtrlWnd->ShowWindow(SW_HIDE);
	}
	
	int v = m_pNumEdit->Create(WS_CHILD|WS_CLIPSIBLINGS|WS_VISIBLE|ES_AUTOHSCROLL|ES_RIGHT,CRect(0,0,0,0),this,1);
	m_pNumEdit->ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	
	m_pSpinCtrl->Create(WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS|UDS_ARROWKEYS,CRect(0,0,0,0),this,2);
	m_pSpinCtrl->SetBuddy(m_pNumEdit);

	this->MoveWindow(rect);
	CFont font;
	font.CreatePointFont(120,"Times New Roman");
	m_pNumEdit->SetFont(&font,false);
	
	return 0;
}

HBRUSH CNumSpinEdit::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (pWnd == m_pNumEdit)
		pDC->SetTextColor(m_clrText);
	
	return hbr;
}

void CNumSpinEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch ( nChar) 
	{
	case VK_PRIOR :	 
				m_pSpinCtrl->Change(10);
				break;
	case VK_NEXT :	
				m_pSpinCtrl->Change(-10);
				break;
	default :
		CWnd::OnKeyDown(nChar,nRepCnt,nFlags);
	}
}

void CNumSpinEdit::OnSetFocus(CWnd* pOldWnd) 
{
	m_pNumEdit->SetFocus();
}

void CNumSpinEdit::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	if ( cx < 60 )
	{
		m_pNumEdit->MoveWindow(0,0,cx,cy);
		m_pSpinCtrl->MoveWindow(cx-SPIN_W,0,0,cy);
	}
	else 
	{
		m_pNumEdit->MoveWindow(0,0,cx-SPIN_W,cy);
		m_pSpinCtrl->MoveWindow(cx-SPIN_W,0,SPIN_W,cy);
	}

}

CSpinCtrl* CNumSpinEdit::GetSpin ()
{
	return m_pSpinCtrl;
}

CNumEdit* CNumSpinEdit::GetEdit ()
{
	return m_pNumEdit;
}

void CNumSpinEdit::SetDigits (int no)
{
	ASSERT(m_pNumEdit);
	m_pNumEdit->SetDigits(no);
}

void CNumSpinEdit::SetRange (float fMin, float fMax, bool bCircle)
{
	ASSERT(m_pNumEdit);
	m_pNumEdit->SetRange(fMin,fMax);
	m_pNumEdit->SetCircle(bCircle);
	m_pSpinCtrl->SetRange((int)fMin,(int)fMax);
}

void CNumSpinEdit::SetStepSize (float dx)
{

	ASSERT(m_pSpinCtrl);
	m_pSpinCtrl->SetDelta(dx);

}

void CNumSpinEdit::SetFont (CFont* pFont, BOOL bRedraw)
{
	m_pNumEdit->SetFont(pFont,bRedraw);
}

void CNumSpinEdit::SetTextColor (COLORREF clrText)
{
	m_clrText = clrText;
}

float CNumSpinEdit::GetValue () const
{
	ASSERT(m_pNumEdit);
	return m_pNumEdit->GetValue();
}

void CNumSpinEdit::SetValue (float val)
{
	ASSERT(m_pNumEdit);
	m_pNumEdit->SetValue(val);
}
