#if !defined(AFX_CHILDDIALOG2_H__281E91C0_AC60_43EB_AC83_2756BC7BA0BB__INCLUDED_)
#define AFX_CHILDDIALOG2_H__281E91C0_AC60_43EB_AC83_2756BC7BA0BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChildDialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChildDialog2 dialog

class CChildDialog2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CChildDialog2)

// Construction
public:
	CChildDialog2();
	~CChildDialog2();

// Dialog Data
	//{{AFX_DATA(CChildDialog2)
	enum { IDD = IDD_CHILDDIALOG2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CChildDialog2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CChildDialog2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDDIALOG2_H__281E91C0_AC60_43EB_AC83_2756BC7BA0BB__INCLUDED_)
