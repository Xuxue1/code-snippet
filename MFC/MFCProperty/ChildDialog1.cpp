// ChildDialog1.cpp : implementation file
//

#include "stdafx.h"
#include "MFC.h"
#include "ChildDialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildDialog1 property page

IMPLEMENT_DYNCREATE(CChildDialog1, CPropertyPage)

CChildDialog1::CChildDialog1() : CPropertyPage(CChildDialog1::IDD)
{
	//{{AFX_DATA_INIT(CChildDialog1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CChildDialog1::~CChildDialog1()
{
}

void CChildDialog1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChildDialog1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChildDialog1, CPropertyPage)
	//{{AFX_MSG_MAP(CChildDialog1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildDialog1 message handlers
