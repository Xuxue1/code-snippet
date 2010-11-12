#if !defined(AFX_NUMEDIT_H__75864AF3_72DD_4AAF_B8D6_A6EE60FD5D77__INCLUDED_)
#define AFX_NUMEDIT_H__75864AF3_72DD_4AAF_B8D6_A6EE60FD5D77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NumEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumEdit window

class CNumEdit : public CEdit
{
// Construction
public:
	CNumEdit();

// Attributes
public:

// Operations
public:
    //	����/���С������λ��
	void SetDigits (int noOfDigitsAfterZero);
    int GetDigits ();

    //	��ñ༭���ֵ
    virtual float GetValue ();
    //	���ñ༭���ֵ�������ֵ����Ч��
    virtual void SetValue (float x);

    // ���������������Сֵ
	void SetRange (float min, float max);
    // ��������������Сֵ
	void GetRange (float& min, float& max);

	//	����ʹ����ť�Ƿ���ѭ�������͵ݼ�ֵ
	void SetCircle(BOOL bCircle);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNumEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNumEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected:
	//	��������С������λ���Ƿ����Ҫ��
    virtual bool CheckInput (UINT nChar);

    int m_nDigits; // С�����λ��
	BOOL m_bCircle;
    float m_fMax;
    float m_fMin;

	CBrush m_Brush;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMEDIT_H__75864AF3_72DD_4AAF_B8D6_A6EE60FD5D77__INCLUDED_)
