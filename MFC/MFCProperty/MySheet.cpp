// MySheet.cpp : implementation file
//

#include "stdafx.h"
#include "MFC.h"
#include "MySheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySheet

IMPLEMENT_DYNAMIC(CMySheet, CPropertySheet)

CMySheet::CMySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CMySheet::CMySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CMySheet::~CMySheet()
{
}


BEGIN_MESSAGE_MAP(CMySheet, CPropertySheet)
	//{{AFX_MSG_MAP(CMySheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySheet message handlers

BOOL CMySheet::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	//ȡ������ҳ�Ĵ�С
	CRect rectWnd;
	GetWindowRect(rectWnd);
	
	//�����Ի���Ŀ��
	SetWindowPos(NULL, 0, 0, rectWnd.Width() + 100, rectWnd.Height(), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	CRect rectButton(rectWnd.Width() + 25, 25, rectWnd.Width()+75, 75);
	
	//�ó��򴴽�һ����ť
	m_button.Create("Button", BS_PUSHBUTTON, CRect(rectWnd.Width(), 25,	rectWnd.Width()+75, 50), this, 1);
	
	//��ʾ�����ť
	m_button.ShowWindow( SW_SHOW );
	
	CenterWindow();
	
	return bResult;
}
