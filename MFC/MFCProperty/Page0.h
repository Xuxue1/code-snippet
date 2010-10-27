#if !defined(AFX_PAGE0_H__26045C2C_2F41_4FDA_BD97_D3148D1D51AC__INCLUDED_)
#define AFX_PAGE0_H__26045C2C_2F41_4FDA_BD97_D3148D1D51AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page0.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage0 dialog

class CPage0 : public CDialog
{
// Construction
public:
	CPage0(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage0)
	enum { IDD = IDD_DIALOG0 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage0)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage0)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE0_H__26045C2C_2F41_4FDA_BD97_D3148D1D51AC__INCLUDED_)
