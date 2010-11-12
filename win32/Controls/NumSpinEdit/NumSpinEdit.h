#if !defined(AFX_NUMSPINEDIT_H__C7D8474B_8BC3_40F3_9D9E_E5A68D02F858__INCLUDED_)
#define AFX_NUMSPINEDIT_H__C7D8474B_8BC3_40F3_9D9E_E5A68D02F858__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NumSpinEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumSpinEdit window
class CNumEdit;
class CSpinCtrl;

class CNumSpinEdit : public CWnd
{
// Construction
public:
	CNumSpinEdit(UINT nID = 0);

// Attributes
public:

// Operations
public:
	//������ť�ؼ�
	CSpinCtrl* GetSpin ();
	//�������ֱ༭�ؼ�
	CNumEdit* GetEdit ();

	//	������ť����
	void SetStepSize (float dx);
	//	���ÿؼ�����
	void SetFont (CFont* pFont, BOOL bRedraw = TRUE);
	// ����������ɫ
	void SetTextColor (COLORREF);

	//	����С������λ��
	void SetDigits (int no);

	//	�������ֵ����Сֵ���Լ���ť�Ƿ�ѭ���仯
	void SetRange (float fMin, float fMax, bool bCircle);

	// ����/��ñ༭���ֵ
	void SetValue (float val);
	float GetValue() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumSpinEdit)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNumSpinEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNumSpinEdit)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CNumEdit* m_pNumEdit;
	CSpinCtrl* m_pSpinCtrl;
    COLORREF m_clrText;

	UINT m_nID;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMSPINEDIT_H__C7D8474B_8BC3_40F3_9D9E_E5A68D02F858__INCLUDED_)
