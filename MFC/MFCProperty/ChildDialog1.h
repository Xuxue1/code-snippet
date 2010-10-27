#if !defined(AFX_CHILDDIALOG1_H__B4105A0F_A748_4E6A_B2A7_9EA548EFF762__INCLUDED_)
#define AFX_CHILDDIALOG1_H__B4105A0F_A748_4E6A_B2A7_9EA548EFF762__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChildDialog1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChildDialog1 dialog

class CChildDialog1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CChildDialog1)

// Construction
public:
	CChildDialog1();
	~CChildDialog1();

// Dialog Data
	//{{AFX_DATA(CChildDialog1)
	enum { IDD = IDD_CHILDDIALOG1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CChildDialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CChildDialog1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDDIALOG1_H__B4105A0F_A748_4E6A_B2A7_9EA548EFF762__INCLUDED_)
