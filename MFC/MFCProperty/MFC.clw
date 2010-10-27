; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFCDlg
LastTemplate=CPropertySheet
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC.h"

ClassCount=9
Class1=CMFCApp
Class2=CMFCDlg
Class3=CAboutDlg

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG2
Resource4=IDD_DIALOG1
Resource5=IDD_CHILDDIALOG1
Class4=CPage0
Class5=CPage1
Class6=CPage2
Resource6=IDD_CHILDDIALOG2
Resource7=IDD_DIALOGBAR (English (U.S.))
Resource8=IDD_DIALOG0
Resource9=IDD_MAINDIALOG
Class7=CChildDialog1
Class8=CChildDialog2
Class9=CMySheet
Resource10=IDD_DIALOG3

[CLS:CMFCApp]
Type=0
HeaderFile=MFC.h
ImplementationFile=MFC.cpp
Filter=N

[CLS:CMFCDlg]
Type=0
HeaderFile=MFCDlg.h
ImplementationFile=MFCDlg.cpp
Filter=D
LastObject=CMFCDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCDlg.h
ImplementationFile=MFCDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG0]
Type=1
Class=CPage0
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_OK,button,1342242816
Control3=IDC_CANCEL,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CPage1
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_OK,button,1342242816
Control3=IDC_CANCEL,button,1342242816

[DLG:IDD_DIALOG2]
Type=1
Class=CPage2
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:CPage0]
Type=0
HeaderFile=Page0.h
ImplementationFile=Page0.cpp
BaseClass=CDialog
Filter=D
LastObject=CPage0

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CDialog
Filter=D
LastObject=CPage1

[CLS:CPage2]
Type=0
HeaderFile=Page2.h
ImplementationFile=Page2.cpp
BaseClass=CDialog
Filter=D
LastObject=CPage2

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG3]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_CHILDDIALOG2]
Type=1
Class=CChildDialog2
ControlCount=3
Control1=IDC_TAB1,SysTabControl32,1342177280
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816

[DLG:IDD_CHILDDIALOG1]
Type=1
Class=CChildDialog1
ControlCount=3
Control1=IDC_TAB1,SysTabControl32,1342177280
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816

[DLG:IDD_MAINDIALOG]
Type=1
Class=CMFCDlg
ControlCount=3
Control1=IDC_TAB1,SysTabControl32,1342177280
Control2=IDC_BUTTON2,button,1342242817
Control3=IDC_BUTTON3,button,1342242817

[CLS:CChildDialog1]
Type=0
HeaderFile=ChildDialog1.h
ImplementationFile=ChildDialog1.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CChildDialog1

[CLS:CChildDialog2]
Type=0
HeaderFile=ChildDialog2.h
ImplementationFile=ChildDialog2.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CChildDialog2

[CLS:CMySheet]
Type=0
HeaderFile=MySheet.h
ImplementationFile=MySheet.cpp
BaseClass=CPropertySheet
Filter=W

