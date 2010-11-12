#if !defined(AFX_SECUREEDIT_H__7D8FE371_A94A_4A4C_8BB1_C053FA6652BD__INCLUDED_)
#define AFX_SECUREEDIT_H__7D8FE371_A94A_4A4C_8BB1_C053FA6652BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SecureEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSecureEdit window
#define SECURE_CHAR _T('*')

class CSecureEdit : public CEdit
{
// Construction
public:
	CSecureEdit();

// Attributes
public:

// Operations
public:
	void SetWindowText( LPCTSTR lpszString );
	void GetWindowText( CString& rString ) const;
	int  GetWindowText( LPTSTR lpszStringBuf, int nMaxCount ) const;
	void GetRealText( CString& rString ) const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSecureEdit)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSecureEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSecureEdit)
	afx_msg void OnUpdate();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	CString m_strRealText;

	int m_nOldLen;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECUREEDIT_H__7D8FE371_A94A_4A4C_8BB1_C053FA6652BD__INCLUDED_)
