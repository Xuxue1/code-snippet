// IconComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "ComboBoxEx.h"
#include "IconComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIconComboBox

CIconComboBox::CIconComboBox()
{
	m_sizeIcon.cx = ::GetSystemMetrics(SM_CXICON); 
	m_sizeIcon.cy = ::GetSystemMetrics(SM_CXICON); 
}

CIconComboBox::~CIconComboBox()
{
}


BEGIN_MESSAGE_MAP(CIconComboBox, CComboBox)
	//{{AFX_MSG_MAP(CIconComboBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIconComboBox message handlers
void CIconComboBox::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	SetItemHeight(-1, 34);

	CComboBox::PreSubclassWindow();
}

void CIconComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMIS)
{ 
	lpMIS->itemHeight = (m_sizeIcon.cy + 2);
}

void CIconComboBox::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
    CDC* pDC = CDC::FromHandle(lpDIS->hDC);

	if (!IsWindowEnabled())
	{
        CBrush brDisabled(RGB(192,192,192)); // light gray
		CBrush* pOldBrush = pDC->SelectObject(&brDisabled);
		CPen penDisabled(PS_SOLID, 1, RGB(192,192,192));
        CPen* pOldPen = pDC->SelectObject(&penDisabled);
        DrawIcon(lpDIS, FALSE);
		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldPen);
		return;
	}

	// Selected
	if ((lpDIS->itemState & ODS_SELECTED) 
		&& (lpDIS->itemAction & (ODA_SELECT | ODA_DRAWENTIRE))) 
	{
		CBrush brHighlight(::GetSysColor(COLOR_HIGHLIGHT)); 
		CBrush* pOldBrush = pDC->SelectObject(&brHighlight);
		CPen penHighlight(PS_SOLID, 1, ::GetSysColor(COLOR_HIGHLIGHT));
		CPen* pOldPen = pDC->SelectObject(&penHighlight);
		pDC->Rectangle(&lpDIS->rcItem);
		pDC->SetBkColor(::GetSysColor(COLOR_HIGHLIGHT));
       	pDC->SetTextColor(::GetSysColor(COLOR_HIGHLIGHTTEXT));
		DrawIcon(lpDIS, TRUE);
		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldPen);
	}

	// De-Selected
	if (!(lpDIS->itemState & ODS_SELECTED) 
		&& (lpDIS->itemAction & (ODA_SELECT | ODA_DRAWENTIRE))) 
	{
		CBrush brWindow(::GetSysColor(COLOR_WINDOW)); 
		CBrush* pOldBrush = pDC->SelectObject(&brWindow);
		CPen penHighlight(PS_SOLID, 1, ::GetSysColor(COLOR_WINDOW));
		CPen* pOldPen = pDC->SelectObject(&penHighlight);
		pDC->Rectangle(&lpDIS->rcItem);
		pDC->SetBkColor(::GetSysColor(COLOR_WINDOW));
       	pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
		DrawIcon(lpDIS, FALSE);
		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldPen);
	}

    // Focus
    if (lpDIS->itemAction & ODA_FOCUS) 
	{ 
        pDC->DrawFocusRect(&lpDIS->rcItem);
    }
}

int CIconComboBox::AddString(LPCTSTR lpszString)
{
	ASSERT(FALSE); // cannot add strings 
	return CB_ERR;
}

int CIconComboBox::InsertString(int nIndex, LPCTSTR lpszString)
{
	ASSERT(FALSE); // cannot insert strings
	return CB_ERR;
}

int CIconComboBox::DeleteString(int nIndex)
{
	ASSERT(FALSE); // cannot delete strings
	return CB_ERR;
}

int CIconComboBox::AddIcon(LPCTSTR lpszIconFile)
{
	HICON hIcon = ::ExtractIcon(AfxGetInstanceHandle(), lpszIconFile, 0);

	if (hIcon == (HICON)1 || hIcon == NULL)
		return CB_ERR;

	int nIndex = CComboBox::AddString(lpszIconFile);

	if (nIndex != CB_ERR && nIndex != CB_ERRSPACE)
		SetItemData(nIndex, (DWORD)hIcon);
	
	return nIndex;
}

int CIconComboBox::InsertIcon(int nIndex, LPCTSTR lpszIconFile)
{
	HICON hIcon = ::ExtractIcon(AfxGetInstanceHandle(), lpszIconFile, 0);

	if (hIcon == (HICON)1 || hIcon == NULL)
		return CB_ERR;

	nIndex = CComboBox::InsertString(nIndex, lpszIconFile);

	if (nIndex != CB_ERR && nIndex != CB_ERRSPACE)
		SetItemData(nIndex, (DWORD)hIcon);
	
	return nIndex;
}

int CIconComboBox::SelectIcon(LPCTSTR lpszIconFile)
{
	int nIndex = CComboBox::FindStringExact(-1, lpszIconFile);
	
	if (nIndex == CB_ERR && CComboBox::GetCount() > 0)
		nIndex = 0; // select the first icon if not found

	return CComboBox::SetCurSel(nIndex);
}

int CIconComboBox::SelectIcon(int nIndex)
{
	return CComboBox::SetCurSel(nIndex);
}

int CIconComboBox::DeleteIcon(LPCTSTR lpszIconFile)
{
	int nIndex = CComboBox::FindStringExact(-1, lpszIconFile);

	return CComboBox::DeleteString(nIndex);
}

int CIconComboBox::DeleteIcon(int nIndex)
{
	return CComboBox::DeleteString(nIndex);
}

void CIconComboBox::DrawIcon(LPDRAWITEMSTRUCT lpDIS, BOOL bSelected)
{
	if (GetCurSel() == CB_ERR || GetCount() == 0) // 没有选择项或没有项可选
		return; 
    
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);

	HICON hIcon = (HICON)lpDIS->itemData;
	ASSERT(hIcon != NULL);

	int x = lpDIS->rcItem.left + ((lpDIS->rcItem.right - lpDIS->rcItem.left) / 2) - (m_sizeIcon.cx / 2);
	int y = lpDIS->rcItem.top + ((lpDIS->rcItem.bottom - lpDIS->rcItem.top) / 2) - (m_sizeIcon.cy / 2);
	
	pDC->DrawIcon(x, y, hIcon);
}               


