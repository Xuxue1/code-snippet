// ChildDialog2.cpp : implementation file
//

#include "stdafx.h"
#include "MFC.h"
#include "ChildDialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildDialog2 property page

IMPLEMENT_DYNCREATE(CChildDialog2, CPropertyPage)

CChildDialog2::CChildDialog2() : CPropertyPage(CChildDialog2::IDD)
{
	//{{AFX_DATA_INIT(CChildDialog2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CChildDialog2::~CChildDialog2()
{
}

void CChildDialog2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChildDialog2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChildDialog2, CPropertyPage)
	//{{AFX_MSG_MAP(CChildDialog2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildDialog2 message handlers
