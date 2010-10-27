// MFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC.h"
#include "MFCDlg.h"
#include "ChildDialog1.h"
#include "ChildDialog2.h"
#include "MySheet.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg dialog

CMFCDlg::CMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCDlg)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg message handlers

BOOL CMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//初始化m_tab控件 
	m_tab.InsertItem(0," 呵呵 ");
	m_tab.InsertItem(1," 嘻嘻 ");
	m_tab.InsertItem(2," 哈哈 ");

	
	//建立属性页各页 
	page0.Create(IDD_DIALOG0,GetDlgItem(IDC_TAB1)); 
	page1.Create(IDD_DIALOG1,GetDlgItem(IDC_TAB1)); 
	page2.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB1)); 
	
	//设置页面的位置在m_tab控件范围内 
	CRect rect;
	m_tab.GetClientRect(&rect);
	rect.top+=20; 
	rect.bottom-=4; 
	rect.left+=4; 
	rect.right-=4; 
	page0.MoveWindow(&rect);
	page1.MoveWindow(&rect);	
	page2.MoveWindow(&rect);
	page1.ShowWindow(TRUE); 
	m_tab.SetCurSel(1); 
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMySheet sheet("属性页对话框");
	CChildDialog1 childpage1;
	CChildDialog2 childpage2;
	int CurSel; 
	CurSel=m_tab.GetCurSel(); 
	switch(CurSel) 
	{ 
	case 0: 
		page0.ShowWindow(TRUE);
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		break; 
	case 1: 
		page0.ShowWindow(FALSE);
		page1.ShowWindow(TRUE); 
		page2.ShowWindow(FALSE); 
		break; 
	case 2: 
		if (page0.ShowWindow(TRUE))
		{
			page0.ShowWindow(TRUE);
			page1.ShowWindow(FALSE); 
			page2.ShowWindow(FALSE); 
		}
		if (page1.ShowWindow(TRUE))
		{
			page0.ShowWindow(FALSE);
			page1.ShowWindow(TRUE);
			page2.ShowWindow(FALSE); 
		}
		sheet.AddPage(&childpage1);
		sheet.AddPage(&childpage2);
		sheet.DoModal();
		break;
	default: ; 
	} 

	*pResult = 0;
}
