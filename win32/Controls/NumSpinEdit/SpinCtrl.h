#if !defined(AFX_SPINCTRL_H__0FA44567_74AA_4DE1_8ADB_C0910E20CCB1__INCLUDED_)
#define AFX_SPINCTRL_H__0FA44567_74AA_4DE1_8ADB_C0910E20CCB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpinCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpinCtrl window

class CSpinCtrl : public CSpinButtonCtrl
{
// Construction
public:
	CSpinCtrl();

// Attributes
public:

// Operations
public:
	// 用steps*delta修改控件的值
	void Change (int steps);
	// 向上和向下改变的数量
	void SetDelta (float x);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpinCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSpinCtrl)
	afx_msg void OnDeltapos(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	float m_fDelta;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINCTRL_H__0FA44567_74AA_4DE1_8ADB_C0910E20CCB1__INCLUDED_)
