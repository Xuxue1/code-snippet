// MFCDlg.h : header file
//

#if !defined(AFX_MFCDLG_H__E7649D95_FDE1_4A00_B89B_9691BEC214F8__INCLUDED_)
#define AFX_MFCDLG_H__E7649D95_FDE1_4A00_B89B_9691BEC214F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg dialog

#include "Page0.h"
#include "Page1.h"
#include "Page2.h"

class CMFCDlg : public CDialog
{
// Construction
public:
	CMFCDlg(CWnd* pParent = NULL);	// standard constructor
	CPage0 page0;
	CPage1 page1;
	CPage2 page2;

// Dialog Data
	//{{AFX_DATA(CMFCDlg)
	enum { IDD = IDD_MFC_DIALOG };
	CTabCtrl	m_tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDLG_H__E7649D95_FDE1_4A00_B89B_9691BEC214F8__INCLUDED_)
