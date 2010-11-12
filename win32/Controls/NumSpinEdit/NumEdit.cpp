// NumEdit.cpp : implementation file
//

#include "stdafx.h"
#include "editex.h"
#include "NumEdit.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumEdit

CNumEdit::CNumEdit()
{
	m_nDigits = 0;
	m_Brush.CreateStockObject(NULL_BRUSH);
}

CNumEdit::~CNumEdit()
{
}


BEGIN_MESSAGE_MAP(CNumEdit, CEdit)
	//{{AFX_MSG_MAP(CNumEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumEdit message handlers
void CNumEdit::OnChar (UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// 只处理数字，'+'，'-'，'.'和回退键的输入，其余全部忽略
	if(isdigit (nChar) && CheckInput(nChar) )
		CEdit::OnChar(nChar,nRepCnt,nFlags);
	else
	{
		CString txt;
		GetWindowText(txt);
		switch (nChar) 
		{
		case '+' : // set to absolute value
			{
				float x = (float) atof(txt);
				if (x >0)
					break; // only break if we already >0, else do "case -"
			}
		case '-' : // 设置负数
			{
				if( txt != "" )
				{
					float x = (float) atof(txt);
					x = -x;
					SetValue(x);
				}
				else
					CEdit::OnChar(nChar,nRepCnt,nFlags);
				break;
			}
		case '.' :	 
				if ( txt.Find('.') == -1 && CheckInput(nChar))
					CEdit::OnChar(nChar, nRepCnt, nFlags);
				break; 
		case VK_BACK:
			CEdit::OnChar(nChar, nRepCnt, nFlags);
			break;
		}
	}
}

void CNumEdit::SetDigits (int nDigits)
{
	m_nDigits = nDigits;
}

int CNumEdit::GetDigits ()
{
	return m_nDigits;
}

void CNumEdit::SetCircle (BOOL bCircle)
{
	m_bCircle = bCircle;
}

void CNumEdit::SetRange (float fMin, float fMax)
{

	m_fMax = fMax;
	m_fMin = fMin;

}

void CNumEdit::GetRange (float& fMin, float& fMax)
{

	fMax = m_fMax;
	fMin = m_fMin;

}

float CNumEdit::GetValue ()
{
	CString txt;
	GetWindowText(txt);
	return (float) atof(txt);
}

void CNumEdit::SetValue (float x)
{
	CString tmp;
	CString fmt;
	fmt.Format("%%0.%df",m_nDigits);
	tmp.Format (fmt,(x+(0.5/pow( 10, m_nDigits+1) ) ) );
	SetWindowText (tmp);
}

bool CNumEdit::CheckInput (UINT nChar)
{
	// checks no digit or dots before a minus sign
	// and no more than m_digits after '.'

	int pos = CharFromPos(GetCaretPos()); 
	CString txt;
	GetWindowText(txt);
	int len = txt.GetLength();
	//////// no digits or dot before a minus sign
	int sign = txt.Find('-');
	if ( sign == 0 && pos == 0 && txt.GetLength() > 1 )
		return false;
	//// no dot before m_digit from end of string
	int dot = txt.ReverseFind('.');
	if ( dot == -1 ) 
	{
		// no dot - 
		return true;
	}
	// 限制'.'后的位数 
	if ( len - pos < dot) 
	{
		// no insert if 
		// there is more than m_digits digits after zero.
		if ( pos -dot > m_nDigits )
			return false;
		// the insert will cause the same
		if ( len - dot> m_nDigits) 
			return false;
	}

	if ( isdigit(nChar)) 
	{
		int pos = CharFromPos(GetCaretPos()); 
		CString txt;
		GetWindowText(txt);
		CString input(nChar);
		txt.Insert(pos,input);
		float value = (float )atof(txt);
		if ( value > m_fMax || value < m_fMin )
			return false;
	}

	return true;
}


