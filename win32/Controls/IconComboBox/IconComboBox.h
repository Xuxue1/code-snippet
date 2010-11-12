#if !defined(AFX_ICONCOMBOBOX_H__63610477_E7E7_44DB_B6E7_B4B6C8DB090C__INCLUDED_)
#define AFX_ICONCOMBOBOX_H__63610477_E7E7_44DB_B6E7_B4B6C8DB090C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IconComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIconComboBox window

class CIconComboBox : public CComboBox
{
// Construction
public:
	CIconComboBox();

// Attributes
public:

// Operations
public:
	virtual int AddIcon(LPCTSTR lpszIconFile);
	virtual int InsertIcon(int nIndex, LPCTSTR lpszIconFile);
	virtual int SelectIcon(LPCTSTR lpszIconFile);
	virtual int SelectIcon(int nIndex);
	virtual int DeleteIcon(LPCTSTR lpszIconFile);
	virtual int DeleteIcon(int nIndex);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconComboBox)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIconComboBox();

	// Generated message map functions
protected:
// Overrides
	virtual int AddString(LPCTSTR lpszString);
	virtual int InsertString(int nIndex, LPCTSTR lpszString);
	virtual int DeleteString(int nIndex);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMIS);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);

	//{{AFX_MSG(CIconComboBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected:
	virtual void DrawIcon(LPDRAWITEMSTRUCT lpDIS, BOOL bSelected);

	CSize m_sizeIcon;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONCOMBOBOX_H__63610477_E7E7_44DB_B6E7_B4B6C8DB090C__INCLUDED_)
