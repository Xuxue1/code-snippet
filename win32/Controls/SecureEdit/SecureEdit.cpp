// SecureEdit.cpp : implementation file
//

#include "stdafx.h"
#include "EditEx.h"
#include "SecureEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSecureEdit

CSecureEdit::CSecureEdit()
{
	m_strRealText = "";
	m_nOldLen = 0;
}

CSecureEdit::~CSecureEdit()
{
}


BEGIN_MESSAGE_MAP(CSecureEdit, CEdit)
	//{{AFX_MSG_MAP(CSecureEdit)
	ON_CONTROL_REFLECT(EN_UPDATE, OnUpdate)
	ON_WM_CONTEXTMENU()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSecureEdit message handlers
void CSecureEdit::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	ModifyStyle(ES_PASSWORD, 0); //取消密码类型
	
	CEdit::PreSubclassWindow();
}

void CSecureEdit::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	
}

void CSecureEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar == 22   &&   nRepCnt==1   &&   (!(nFlags&0x400)))   // CTRL + V
	{
		return;
	}
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}

void CSecureEdit::OnUpdate() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEdit::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	CString strText;
	CEdit::GetWindowText(strText); // 获得窗口的文本(Windows已经更新了，但编辑框的显示还没更新)

	DWORD dwPos = GetSel() & 0xFFFF; // 光标现在的位置
	BOOL bHasChanged = FALSE;
	int nLen = strText.GetLength();
	int i;
	int nDiff = nLen - m_nOldLen; // 新的和老的文本长度的差别
	int nIndex = 0; // 新输入的字符位置
	BOOL bChinese = FALSE;

	for(i = 0; i < nLen; i++)
	{
		UCHAR c = strText.GetAt(i);
		if(c != SECURE_CHAR) // 老的字符应该都是*
		{
			bHasChanged = TRUE; // 有新的字符，设置变化标志
			nIndex = i;
			if( c > 160 )   // 汉字，占2个字符
			{
				bChinese = TRUE;
			}
			break;
		}
	}
	if(bHasChanged == FALSE) // 文本都是密码了，没有新的变化，返回
		return; 

	if( m_nOldLen == 0 )
	{
		m_strRealText = strText;
	}
	else
	{
		if( nDiff < 0 )
		{
			CString strTemp;
			int nNum = (bChinese == TRUE) ? 2 : 1; // 新字符的数量
			strTemp = m_strRealText.Left(nIndex) ; // 新字符左边的老字符保留
			strTemp += strText.Mid(nIndex, nNum);  // 插入新字符
			// 去掉老字符串可能被覆盖掉的部分，把老字符串右边剩下的字符加后面
			strTemp += m_strRealText.Right(nLen - nIndex - nNum); 

			m_strRealText = strTemp; // 保存在自己的变量里
		}
		else if( nDiff == 0 )
		{
			// 用新字符替换相同位置的老字符
			m_strRealText.SetAt(nIndex, strText.GetAt(nIndex));
			if( bChinese )	
				m_strRealText.SetAt(nIndex+1, strText.GetAt(nIndex+1));
		}
		else if( nDiff > 0 )
		{
			CString strTemp;
			int nNum = (bChinese == TRUE) ? 2 : 1; // 新字符的数量
			strTemp = m_strRealText.Left(nIndex) ; // 新字符左边的老字符保留
			strTemp += strText.Mid(nIndex, nNum);  // 插入新字符
			// 去掉老字符串可能被覆盖掉的部分，把老字符串右边剩下的字符加后面
			strTemp += m_strRealText.Right(nLen - nIndex - nNum); 

			m_strRealText = strTemp; // 保存在自己的变量里
		}
	}

	strText.Empty();
	for(i = 0; i < nLen; i++) 
		strText += SECURE_CHAR;
	m_nOldLen = nLen;
	
	CEdit::SetWindowText(strText);
	SetSel(dwPos, dwPos, FALSE); // Just to not confuse the user ;-)
}

void CSecureEdit::SetWindowText(LPCTSTR lpszString)
{
	CString strText;

	if(lpszString == NULL) return;

	m_strRealText = lpszString;

	int nLen = strlen(lpszString);
	strText.Empty(); // Build password-char string with correct length
	for(int i = 0; i < nLen; i++) 
		strText += SECURE_CHAR;

	m_nOldLen = nLen;

	CEdit::SetWindowText(strText);
}

void CSecureEdit::GetRealText( CString& rString ) const
{
	rString = m_strRealText;
}

void CSecureEdit::GetWindowText( CString& rString ) const
{
	rString = "*";
}

int CSecureEdit::GetWindowText( LPTSTR lpszStringBuf, int nMaxCount ) const
{
	int nCount = 1;
	strncpy(lpszStringBuf, "*", nCount);
	return nCount;
}

