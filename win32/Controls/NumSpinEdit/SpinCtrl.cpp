// SpinCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "EditEx.h"
#include "SpinCtrl.h"
#include "numedit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpinCtrl

CSpinCtrl::CSpinCtrl()
{
	m_fDelta = 1;
}

CSpinCtrl::~CSpinCtrl()
{
}


BEGIN_MESSAGE_MAP(CSpinCtrl, CSpinButtonCtrl)
	//{{AFX_MSG_MAP(CSpinCtrl)
	ON_NOTIFY_REFLECT(UDN_DELTAPOS, OnDeltapos)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpinCtrl message handlers

void CSpinCtrl::OnDeltapos(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	DWORD bWrap = (GetStyle() & UDS_WRAP);
	if ((pNMUpDown->iPos <= pNMUpDown->iDelta) ||
		(pNMUpDown->iPos >= 1000 - pNMUpDown->iDelta)) 
		pNMUpDown->iPos = 500;
	Change(pNMUpDown->iDelta);	

	*pResult = 0;
}

void CSpinCtrl::Change (int steps)
{
	CWnd* b = GetBuddy();
	CNumEdit* edit = dynamic_cast<CNumEdit*>(b);
	ASSERT(edit); // cast falied

	float fDelta = steps*m_fDelta;
	float f = edit->GetValue();
	// This messy bit of code gets around a floating point resolution problem.
	// For example, if your step is -1 and m_fDelta is .1, you would end up
	// with -1.49xxx e-9 and it would never set the control to zero. The old
	// 0 != 0 problem.
	if( f == -fDelta )
		f = 0;
	else
		f += fDelta;
	
	edit->SetValue(f);
}

void CSpinCtrl::SetDelta (float x)
{
	m_fDelta = x;
}

