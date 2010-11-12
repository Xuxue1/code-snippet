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
    //	设置/获得小数点后的位数
	void SetDigits (int noOfDigitsAfterZero);
    int GetDigits ();

    //	获得编辑框的值
    virtual float GetValue ();
    //	设置编辑框的值，并检查值的有效性
    virtual void SetValue (float x);

    // 设置输入的最大和最小值
	void SetRange (float min, float max);
    // 获得输入的最大和最小值
	void GetRange (float& min, float& max);

	//	设置使用旋钮是否能循环递增和递减值
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
	//	检查输入的小数点后的位数是否符合要求
    virtual bool CheckInput (UINT nChar);

    int m_nDigits; // 小数点后位数
	BOOL m_bCircle;
    float m_fMax;
    float m_fMin;

	CBrush m_Brush;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMEDIT_H__75864AF3_72DD_4AAF_B8D6_A6EE60FD5D77__INCLUDED_)
