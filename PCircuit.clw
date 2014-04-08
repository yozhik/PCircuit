; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPass
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PCircuit.h"

ClassCount=12
Class1=CPCircuitApp
Class2=CPCircuitDlg
Class3=CAboutDlg

ResourceCount=13
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PCIRCUIT_DIALOG
Resource4=IDD_ADD_DIALOG
Resource5=IDD_AUTHOR_DIALOG
Class4=CMyListCtrl
Resource6=IDD_EDIT_DIALOG
Class5=CAddNewCircuit
Class6=CMyRecordset
Resource7=IDD_EXIT_DIALOG
Class7=CEditCircuit
Resource8=IDD_DIALOG3
Class8=CDeleteCircuit
Resource9=IDD_PCIRCUIT_DIALOG (Russian)
Class9=CAuthor
Resource10=IDD_PASSWORD_DIALOG
Class10=CPass
Resource11=IDD_ABOUTBOX (English (U.S.))
Class11=CDraw
Resource12=IDD_DELETE_DIALOG
Class12=CExitDlg
Resource13=IDR_MENU1

[CLS:CPCircuitApp]
Type=0
HeaderFile=PCircuit.h
ImplementationFile=PCircuit.cpp
Filter=N

[CLS:CPCircuitDlg]
Type=0
HeaderFile=PCircuitDlg.h
ImplementationFile=PCircuitDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPCircuitDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=PCircuitDlg.h
ImplementationFile=PCircuitDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_PCIRCUIT_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CPCircuitDlg

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MENU1]
Type=1
Class=CPCircuitDlg
Command1=ID_MENU_PASSWORD
Command2=ID_MENU_EXIT
Command3=ID_DATABASE_CREATE
Command4=ID_DATABASE_OPEN
Command5=ID_DATABASE_ADDCIRCUIT
Command6=ID_DATABASE_EDITCIRCUIT
Command7=ID_DATABASE_DELETECIRCUIT
Command8=ID_SEARCH_NORMALCIRCUITS
Command9=ID_SEARCH_DEMAGEDCIRCUITS
Command10=ID_VISUALIZATION_SHOWDIAGRAM
Command11=ID_VISUALIZATION_SHOWDATABASE
Command12=ID_ABOUT_AUTHOR
Command13=ID_ABOUT_PROGRAM
CommandCount=13

[CLS:CMyListCtrl]
Type=0
HeaderFile=MyListCtrl.h
ImplementationFile=MyListCtrl.cpp
BaseClass=CListCtrl
Filter=W
LastObject=CMyListCtrl

[DLG:IDD_ADD_DIALOG]
Type=1
Class=CAddNewCircuit
ControlCount=27
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_EDIT3,edit,1350631552
Control4=IDC_CHECK2,button,1342242819
Control5=IDC_CHECK3,button,1342242819
Control6=IDC_CHECK4,button,1342242819
Control7=IDC_CHECK5,button,1342242819
Control8=IDC_CHECK6,button,1342242819
Control9=IDC_EDIT4,edit,1350631552
Control10=IDC_EDIT5,edit,1350631552
Control11=IDC_COMBO1,combobox,1344340226
Control12=IDC_COMBO2,combobox,1344340226
Control13=IDC_COMBO3,combobox,1344340226
Control14=IDOK,button,1342242817
Control15=IDCANCEL,button,1342242816
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342177294

[CLS:CAddNewCircuit]
Type=0
HeaderFile=AddNewCircuit.h
ImplementationFile=AddNewCircuit.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[CLS:CMyRecordset]
Type=0
HeaderFile=MyRecordset.h
ImplementationFile=MyRecordset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CMyRecordset]
DB=1
DBType=ODBC
ColumnCount=14
Column1=[ID], 4, 4
Column2=[CTID], 4, 4
Column3=[MatID], 4, 4
Column4=[ProcID], 4, 4
Column5=[Width], 5, 2
Column6=[Length], 5, 2
Column7=[Height], 5, 2
Column8=[IsDemaged], -7, 1
Column9=[IsGood], -7, 1
Column10=[IsTermedGood], -7, 1
Column11=[IsPoweredGood], -7, 1
Column12=[IsCurrentGood], -7, 1
Column13=[Resistance], 4, 4
Column14=[Voltage], 4, 4

[DLG:IDD_PCIRCUIT_DIALOG (Russian)]
Type=1
Class=CPCircuitDlg
ControlCount=1
Control1=IDC_STATIC1,static,1342177294

[DLG:IDD_EDIT_DIALOG]
Type=1
Class=CEditCircuit
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342177294
Control5=IDC_STATIC,static,1342308352

[CLS:CEditCircuit]
Type=0
HeaderFile=EditCircuit.h
ImplementationFile=EditCircuit.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

[DLG:IDD_DELETE_DIALOG]
Type=1
Class=CDeleteCircuit
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342177294
Control5=IDC_STATIC,static,1342308352

[CLS:CDeleteCircuit]
Type=0
HeaderFile=DeleteCircuit.h
ImplementationFile=DeleteCircuit.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_AUTHOR_DIALOG]
Type=1
Class=CAuthor
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177294
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[CLS:CAuthor]
Type=0
HeaderFile=Author.h
ImplementationFile=Author.cpp
BaseClass=CDialog
Filter=D
LastObject=CAuthor

[DLG:IDD_PASSWORD_DIALOG]
Type=1
Class=CPass
ControlCount=9
Control1=IDC_RADIO1,button,1342310665
Control2=IDC_RADIO2,button,1342179593
Control3=IDC_RADIO3,button,1342179593
Control4=IDC_EDIT1,edit,1350631552
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816
Control7=IDC_STATIC,static,1342177294
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[CLS:CPass]
Type=0
HeaderFile=Pass.h
ImplementationFile=Pass.cpp
BaseClass=CDialog
Filter=D
LastObject=CPass
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=CDraw
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_PIECHART1,static,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[CLS:CDraw]
Type=0
HeaderFile=Draw.h
ImplementationFile=Draw.cpp
BaseClass=CDialog
Filter=D
LastObject=CDraw
VirtualFilter=dWC

[DLG:IDD_EXIT_DIALOG]
Type=1
Class=CExitDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177294
Control4=IDC_STATIC,static,1342308352

[CLS:CExitDlg]
Type=0
HeaderFile=ExitDlg.h
ImplementationFile=ExitDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CExitDlg
VirtualFilter=dWC

