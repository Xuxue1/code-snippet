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
	ModifyStyle(ES_PASSWORD, 0); //ȡ����������
	
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
	CEdit::GetWindowText(strText); // ��ô��ڵ��ı�(Windows�Ѿ������ˣ����༭�����ʾ��û����)

	DWORD dwPos = GetSel() & 0xFFFF; // ������ڵ�λ��
	BOOL bHasChanged = FALSE;
	int nLen = strText.GetLength();
	int i;
	int nDiff = nLen - m_nOldLen; // �µĺ��ϵ��ı����ȵĲ��
	int nIndex = 0; // ��������ַ�λ��
	BOOL bChinese = FALSE;

	for(i = 0; i < nLen; i++)
	{
		UCHAR c = strText.GetAt(i);
		if(c != SECURE_CHAR) // �ϵ��ַ�Ӧ�ö���*
		{
			bHasChanged = TRUE; // ���µ��ַ������ñ仯��־
			nIndex = i;
			if( c > 160 )   // ���֣�ռ2���ַ�
			{
				bChinese = TRUE;
			}
			break;
		}
	}
	if(bHasChanged == FALSE) // �ı����������ˣ�û���µı仯������
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
			int nNum = (bChinese == TRUE) ? 2 : 1; // ���ַ�������
			strTemp = m_strRealText.Left(nIndex) ; // ���ַ���ߵ����ַ�����
			strTemp += strText.Mid(nIndex, nNum);  // �������ַ�
			// ȥ�����ַ������ܱ����ǵ��Ĳ��֣������ַ����ұ�ʣ�µ��ַ��Ӻ���
			strTemp += m_strRealText.Right(nLen - nIndex - nNum); 

			m_strRealText = strTemp; // �������Լ��ı�����
		}
		else if( nDiff == 0 )
		{
			// �����ַ��滻��ͬλ�õ����ַ�
			m_strRealText.SetAt(nIndex, strText.GetAt(nIndex));
			if( bChinese )	
				m_strRealText.SetAt(nIndex+1, strText.GetAt(nIndex+1));
		}
		else if( nDiff > 0 )
		{
			CString strTemp;
			int nNum = (bChinese == TRUE) ? 2 : 1; // ���ַ�������
			strTemp = m_strRealText.Left(nIndex) ; // ���ַ���ߵ����ַ�����
			strTemp += strText.Mid(nIndex, nNum);  // �������ַ�
			// ȥ�����ַ������ܱ����ǵ��Ĳ��֣������ַ����ұ�ʣ�µ��ַ��Ӻ���
			strTemp += m_strRealText.Right(nLen - nIndex - nNum); 

			m_strRealText = strTemp; // �������Լ��ı�����
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

