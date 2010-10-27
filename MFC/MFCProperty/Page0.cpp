// Page0.cpp : implementation file
//

#include "stdafx.h"
#include "MFC.h"
#include "Page0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage0 dialog


CPage0::CPage0(CWnd* pParent /*=NULL*/)
	: CDialog(CPage0::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage0)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage0::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage0)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage0, CDialog)
	//{{AFX_MSG_MAP(CPage0)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage0 message handlers
