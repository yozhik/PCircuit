// PCircuitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PCircuit.h"
#include "PCircuitDlg.h"

#include "MyListCtrl.h"
#include "AddNewCircuit.h"
#include "MyRecordset.h"
#include "EditCircuit.h"
#include "DeleteCircuit.h"
#include "Author.h"
#include "Pass.h"
#include "Draw.h"
#include "ExitDlg.h"


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
// CPCircuitDlg dialog

CPCircuitDlg::CPCircuitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPCircuitDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPCircuitDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	m_List = NULL;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPCircuitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPCircuitDlg)
	DDX_Control(pDX, IDC_STATIC1, m_fon);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPCircuitDlg, CDialog)
	//{{AFX_MSG_MAP(CPCircuitDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_VISUALIZATION_SHOWDIAGRAM, OnVisualizationShowdiagram)
	ON_COMMAND(ID_MENU_PASSWORD, OnPasswordEnter)
	ON_COMMAND(ID_VISUALIZATION_SHOWDATABASE, OnVisualizationShowdatabase)
	ON_WM_DESTROY()
	ON_COMMAND(ID_DATABASE_ADDCIRCUIT, OnDatabaseAddcircuit)
	ON_COMMAND(ID_DATABASE_EDITCIRCUIT, OnDatabaseEditcircuit)
	ON_COMMAND(ID_DATABASE_DELETECIRCUIT, OnDatabaseDeletecircuit)
	ON_COMMAND(ID_DATABASE_OPEN, OnDatabaseOpen)
	ON_COMMAND(ID_ABOUT_AUTHOR, OnAboutAuthor)
	ON_COMMAND(ID_ABOUT_PROGRAM, OnAboutProgram)
	ON_COMMAND(ID_SEARCH_NORMALCIRCUITS, OnSearchNormalcircuits)
	ON_COMMAND(ID_SEARCH_DEMAGEDCIRCUITS, OnSearchDemagedcircuits)
	ON_COMMAND(ID_MENU_EXIT, OnMenuExit)
	ON_UPDATE_COMMAND_UI(ID_VISUALIZATION_SHOWDIAGRAM, OnUpdateVisualizationShowdiagram)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPCircuitDlg message handlers

BOOL CPCircuitDlg::OnInitDialog()
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
	m_menu.LoadMenu(IDR_MENU1);
	this->SetMenu(&m_menu);
	
	// TODO: Add extra initialization here

	sDriver = "MICROSOFT ACCESS DRIVER (*.mdb)";
	//sFile = "D:\\pboards.mdb";
	CString fname = "\\pboards.mdb";

		TCHAR fileName[MAX_PATH];
		INT ret = GetModuleFileName(NULL, _TEXT(fileName), MAX_PATH);
		CString str(fileName);
		INT delPos = str.ReverseFind(_TEXT('\\'));
		str.Delete(delPos, (str.GetLength() - delPos));
		//add to path line out setting's file name
		str+=_TEXT(fname);
		INT pos = 0;
		do
		{
			pos = str.Find(_TEXT("\\"), pos);
			if(pos > 0)
			{
				str.Insert(pos, _TEXT("\\"));
				pos+=2;
			}
		}while(pos != -1);
	sFile = str;

	sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);

	PopulateMap(); 

	m_managerOK = false;
	m_programmerOK = false; 
	m_controllerOK = false;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPCircuitDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPCircuitDlg::OnPaint() 
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
HCURSOR CPCircuitDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPCircuitDlg::OnVisualizationShowdiagram() 
{
	// TODO: Add your command handler code here
	if(m_List)
	{
		m_List->DeleteAllItems();
		m_List->ShowWindow(SW_HIDE);
		delete m_List;
		m_List = NULL;
	}

	int iCount = 0, iGood = 0; 	
	
	// Build ODBC connection string
	sDsn.Empty();
	sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);
	CString SqlString;
	TRY
	{
		// Open the database
		m_db1.Open(NULL,false,false,sDsn);
		
		// Allocate the recordset
		CRecordset recset( &m_db1 );

		//  ID, CTID, MatID, ProcID, Width, Height, Length, Resistance, Voltage
		SqlString =  "SELECT Width, Height, Length, Resistance, Voltage, IsDemaged, IsGood, IsTermedGood, IsPoweredGood, IsCurrentGood FROM Circuits";


		// Execute the query
		recset.Open(CRecordset::forwardOnly,SqlString,CRecordset::readOnly);

		CString sID, sCTID, sMatID, sProcID, sWidth, sLength, sHeight, sResistance, sVoltage;
		// Loop through each record
		int id = 0;
		CDBVariant varValue;
		BYTE IsDemaged, IsGood, IsTermGood, IsPowerGood, IsCurrentGood;

		while( !recset.IsEOF() )
		{

			// Copy each column into a variable
			recset.GetFieldValue("Width", sWidth);
			recset.GetFieldValue("Height", sHeight);
			recset.GetFieldValue("Length", sLength);
			recset.GetFieldValue("Resistance", sResistance);
			recset.GetFieldValue("Voltage", sVoltage);

			CDBVariant varValue1;
			recset.GetFieldValue("IsDemaged", varValue1, SQL_C_UTINYINT);
			IsDemaged = varValue1.m_chVal;

			CDBVariant varValue2;
			recset.GetFieldValue("IsGood", varValue2, SQL_C_UTINYINT);
			IsGood = varValue2.m_chVal;

			CDBVariant varValue3;
			recset.GetFieldValue("IsTermedGood", varValue3, SQL_C_UTINYINT);
			IsTermGood = varValue3.m_chVal;

			CDBVariant varValue4;
			recset.GetFieldValue("IsPoweredGood", varValue4, SQL_C_UTINYINT);
			IsPowerGood = varValue4.m_chVal;

			CDBVariant varValue5;
			recset.GetFieldValue("IsCurrentGood", varValue5, SQL_C_UTINYINT);
			IsCurrentGood = varValue5.m_chVal;


			int Resistance = 0, Voltage = 0;
			Resistance  = StringToInt(sResistance);
			Voltage  = StringToInt(sVoltage);


			if(!IsDemaged && IsGood && IsTermGood && IsPowerGood && IsCurrentGood && Resistance >= 30000 && (Voltage >= 500 && Voltage <= 700))
			{		
				iGood++;  //count of not demaged circuits
			}
			iCount++;
			// goto next record
			recset.MoveNext();
		}
		// Close the database
		m_db1.Close();
	}
	CATCH(CDBException, e)
	{
		// If a database exception occured, show error msg
		AfxMessageBox("Database error: "+e->m_strError);
	}
	END_CATCH;	

	m_fon.ShowWindow(SW_SHOW);
	CDraw dlg;
	dlg.m_nAngleBlue = ((iCount - iGood) * 360) / iCount;
	dlg.m_nAngleYellow = (iGood * 360) / iCount + 2;
		//dlg.m_nAngleGreen = 70;

	dlg.DoModal();
}

void CPCircuitDlg::OnPasswordEnter() 
{
	// TODO: Add your command handler code here
	CPass dlg;
	while(dlg.DoModal() == IDOK)
	{
		switch(dlg.m_r1)
		{
		
			case 0: //Manager
				if(dlg.m_password == "1111")
				{
						m_managerOK = true;
						m_programmerOK = false; 
						m_controllerOK = false;
				}
				else
					MessageBox("Невірний пароль! Спробуйте ще раз.", "Помилка", MB_ICONSTOP);

				break;
			case 1: //Programmer
				if(dlg.m_password == "2222")
				{
						m_managerOK = false;
						m_programmerOK = true; 
						m_controllerOK = false;
				}
				else
					MessageBox("Невірний пароль! Спробуйте ще раз.", "Помилка", MB_ICONSTOP);
				break;
			case 2: //Controller
				if(dlg.m_password == "3333")
				{
						m_managerOK = false;
						m_programmerOK = false; 
						m_controllerOK = true;
				}
				else
					MessageBox("Невірний пароль! Спробуйте ще раз.", "Помилка", MB_ICONSTOP);
				break;
		}
		if(m_managerOK || m_programmerOK || m_controllerOK) break;
	}
}

void CPCircuitDlg::OnOK() 
{

}

void CPCircuitDlg::OnVisualizationShowdatabase() 
{
	// TODO: Add your command handler code here
	m_fon.ShowWindow(SW_HIDE);
	if(m_List)
	{
		m_List->DeleteAllItems();
		m_List->ShowWindow(SW_HIDE);
		delete m_List;
		m_List = NULL;
	}

	m_List = new CMyListCtrl;
	CRect winRect;
	this->GetClientRect(&winRect);


	m_List->Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT, CRect(winRect.left + 20,winRect.top + 10,winRect.right - 20,winRect.bottom - 10), this, 1);
	m_List->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//insert columns
	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 50;
	lvColumn.pszText = " # ";
	m_List->InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 50;
	lvColumn.pszText = " ID ";
	m_List->InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	lvColumn.pszText = " Назва ";
	m_List->InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Матеріал ";
	m_List->InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Тип обробки ";
	m_List->InsertColumn(4, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Розмір, мм ";
	m_List->InsertColumn(5, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 70;
	lvColumn.pszText = " Опір, Ом ";
	m_List->InsertColumn(6, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 90;
	lvColumn.pszText = " Вольтаж, В ";
	m_List->InsertColumn(7, &lvColumn);

	int iRec = 0; 	
	
	// Build ODBC connection string
	sDsn.Empty();
	sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);
	CString SqlString;
	TRY
	{
		// Open the database
		m_db1.Open(NULL,false,false,sDsn);
		
		// Allocate the recordset
		CRecordset recset( &m_db1 );

		// Build the SQL statement ID, CTID, MatID, ProcID, Width, Height, Lenghth, Resistance, Voltage
		SqlString =  "SELECT ID, CTID, MatID, ProcID, Width, Height, Length, Resistance, Voltage FROM Circuits";


		// Execute the query
		recset.Open(CRecordset::forwardOnly,SqlString,CRecordset::readOnly);

		CString sID, sCTID, sMatID, sProcID, sWidth, sLength, sHeight, sResistance, sVoltage;
		// Loop through each record
		int id = 0;
		while( !recset.IsEOF() )
		{
			// Copy each column into a variable
			recset.GetFieldValue("ID", sID);
			recset.GetFieldValue("CTID", sCTID);
			recset.GetFieldValue("MatID", sMatID);
			recset.GetFieldValue("ProcID", sProcID);
			recset.GetFieldValue("Width", sWidth);
			recset.GetFieldValue("Height", sHeight);
			recset.GetFieldValue("Length", sLength);
			recset.GetFieldValue("Resistance", sResistance);
			recset.GetFieldValue("Voltage", sVoltage);
			
			TCHAR buf[5];
			memset(buf, '\0', 5);
			itoa(iRec, buf, 10);
			// Insert values into the list control
			int nItem = m_List->InsertItem(iRec, buf); //insert first string column[0]

			m_List->SetItemText(nItem, 0, buf);

			m_List->SetItemText(nItem, 1, sID);

			id = StringToInt(sCTID);
			m_List->SetItemText(nItem, 2, reverseCTID.find(id)->second); 

			id = StringToInt(sMatID);
			m_List->SetItemText(nItem, 3, reverseMID.find(id)->second); 
			
			id = StringToInt(sProcID);
			m_List->SetItemText(nItem, 4, reversePID.find(id)->second); 

			CString sf;
			sf.Format(_TEXT("%s * %s * %s"),sLength, sWidth, sHeight);
			m_List->SetItemText(nItem, 5, sf); 

			m_List->SetItemText(nItem, 6, sResistance); 

			m_List->SetItemText(nItem, 7, sVoltage); 
		
			iRec++;
			// goto next record
			recset.MoveNext();
		}
		// Close the database
		m_db1.Close();
	}
	CATCH(CDBException, e)
	{
		// If a database exception occured, show error msg
		AfxMessageBox("Database error: "+e->m_strError);
	}
	END_CATCH;
	
}

void CPCircuitDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	if(m_List)
	{
		m_List->DeleteAllItems();
		delete m_List;
		m_List = NULL;
	}	
	CTID.clear();
	MID.clear();
	PID.clear();

	reverseCTID.clear();
	reverseMID.clear();
	reversePID.clear();
}

void CPCircuitDlg::OnDatabaseAddcircuit() 
{
	// TODO: Add your command handler code here
	CAddNewCircuit dlg;
	
	dlg.sDriver = sDriver;
	dlg.sDsn = sDsn;
	dlg.sFile = sFile;
	
	//set maps
	dlg.CTID = CTID;
	dlg.MID = MID;
	dlg.PID = PID;

	if(dlg.DoModal() == IDOK)
	{
		AddNewCircuit(dlg);
	}
}

void CPCircuitDlg::AddNewCircuit(CAddNewCircuit &dlg)
{
		sDsn.Empty();
		sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);
		m_db1.Open(NULL,false,false,sDsn, false);
		CMyRecordset rec(&m_db1);

		try
		{
			rec.Open(CRecordset::dynaset, "SELECT *  FROM Circuits"); 
			if(rec.CanAppend()) 
			{
				rec.AddNew();
			}
			if(dlg.k1)
				rec.m_CTID = dlg.k1;
			else
				rec.m_CTID = 1;

			if(dlg.k2)
				rec.m_MatID = dlg.k2;
			else
				rec.m_MatID = 1;

			if(dlg.k3)
				rec.m_ProcID = dlg.k3;
			else
				rec.m_ProcID = 1;			
			

			rec.m_Height = dlg.m_height;
			rec.m_IsCurrentGood = dlg.m_iscurrent;
			rec.m_IsDemaged = dlg.m_isdemaged;
			rec.m_IsGood = dlg.m_isgoodp;
			rec.m_IsPoweredGood = dlg.m_ispowered;
			rec.m_IsTermedGood = dlg.m_istermed;
			rec.m_Length = dlg.m_len;
			rec.m_Resistance = dlg.m_resistance;
			rec.m_Voltage = dlg.m_voltage;
			rec.m_Width = dlg.m_width;
			
			rec.Update();
			rec.Close(); 
		}
		catch(CDBException cdb)
		{
			AfxMessageBox(cdb.m_strStateNativeOrigin);
		}		
		m_db1.Close();
}

void CPCircuitDlg::PopulateMap()
{
	try
	{
		// Open the database
		m_db1.Open(NULL,false,false,sDsn);
		
		// Allocate the recordset

		CRecordset recset1( &m_db1 );
		CRecordset recset2( &m_db1 );
		CRecordset recset3( &m_db1 );


		CString sCTID, sMatID, sProcID, sID;
		int id = 0;

		CString SqlString1, SqlString2, SqlString3;
		SqlString1 =  "SELECT * FROM CircTypes";
		SqlString2 =  "SELECT * FROM Matherials";
		SqlString3 =  "SELECT * FROM ProcTypes";
		// Loop through each record
			
		recset1.Open(CRecordset::forwardOnly,SqlString1,CRecordset::readOnly);
		while( !recset1.IsEOF() )
		{
			// Copy each column into a variable
			recset1.GetFieldValue("CID", sID);
			recset1.GetFieldValue("CName", sCTID);
			id = StringToInt(sID);
			CTID.insert ( pair<CString, int>(sCTID, id) );
			reverseCTID.insert( pair<int, CString>(id, sCTID) );
			recset1.MoveNext();
		}
		recset1.Close();

		recset2.Open(CRecordset::forwardOnly,SqlString2,CRecordset::readOnly);
		while( !recset2.IsEOF() )
		{
			// Copy each column into a variable
			recset2.GetFieldValue("MID", sID);
			recset2.GetFieldValue("MName", sMatID);
			id = StringToInt(sID);
			MID.insert ( pair<CString, int>(sMatID, id) );
			reverseMID.insert( pair<int, CString>(id, sMatID) );
			recset2.MoveNext();
		}
		recset2.Close();

		recset3.Open(CRecordset::forwardOnly,SqlString3,CRecordset::readOnly);
		while( !recset3.IsEOF() )
		{
			// Copy each column into a variable
			recset3.GetFieldValue("PID", sID);
			recset3.GetFieldValue("PName", sProcID);
			id = StringToInt(sID);
			PID.insert ( pair<CString, int>(sProcID, id) );
			reversePID.insert( pair<int, CString>(id, sProcID) );
			recset3.MoveNext();
		}
		recset3.Close();
	}
	catch(CDBException *e)
	{
		// If a database exception occured, show error msg
		AfxMessageBox("Database error: "+e->m_strError);
	}	
	m_db1.Close();
}

int CPCircuitDlg::StringToInt(CString strVal) 
{
    int tmpIntVal;
    LPTSTR s = NULL;
	s = new TCHAR[strVal.GetLength() + 1];
	memset(s, '\0', strVal.GetLength() + 1);
    for(int j=0; j<strVal.GetLength(); j++) 
        s[j] = strVal.GetAt(j);
	s[j] = '\0';
    tmpIntVal = atoi(s); 
	delete s;
    return tmpIntVal;
}

void CPCircuitDlg::OnDatabaseEditcircuit() 
{
	// TODO: Add your command handler code here
	CEditCircuit dlg1;
	if(dlg1.DoModal() == IDOK)
	{
		CAddNewCircuit dlg;
	
		dlg.sDriver = sDriver;
		dlg.sDsn = sDsn;
		dlg.sFile = sFile;
	
		//set maps
		dlg.CTID = CTID;
		dlg.MID = MID;
		dlg.PID = PID;

		sDsn.Empty();
		sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);
		m_db1.Open(NULL,false,false,sDsn, false);
		CMyRecordset rec(&m_db1);

		try
		{
			rec.Open(CRecordset::dynaset, "SELECT *  FROM Circuits"); 
			while(!rec.IsEOF())
				rec.MoveNext();
			int count = rec.GetRecordCount();
			if(!rec.IsBOF())
				rec.MoveFirst();
			if(count <= 0 )
			{
				MessageBox(_TEXT("There are no records to edit"), _TEXT("Error"), MB_ICONSTOP);
				rec.Close();
				m_db1.Close();
				return;
			}
			if(count < dlg1.m_EditNumber)
			{
				MessageBox(_TEXT("There are no such record to edit! Index is to large!"), _TEXT("Error"), MB_ICONSTOP);
				rec.Close();
				m_db1.Close();
				return;
			}

			if(rec.CanUpdate()) 
			{
				rec.Move(dlg1.m_EditNumber);
				rec.Edit();
			}

			if(dlg.DoModal() == IDOK)
			{

				if(dlg.k1)
					rec.m_CTID = dlg.k1;
				else
					rec.m_CTID = 1;

				if(dlg.k2)
					rec.m_MatID = dlg.k2;
				else
					rec.m_MatID = 1;

				if(dlg.k3)
					rec.m_ProcID = dlg.k3;
				else
					rec.m_ProcID = 1;			
			

				rec.m_Height = dlg.m_height;
				rec.m_IsCurrentGood = dlg.m_iscurrent;
				rec.m_IsDemaged = dlg.m_isdemaged;
				rec.m_IsGood = dlg.m_isgoodp;
				rec.m_IsPoweredGood = dlg.m_ispowered;
				rec.m_IsTermedGood = dlg.m_istermed;
				rec.m_Length = dlg.m_len;
				rec.m_Resistance = dlg.m_resistance;
				rec.m_Voltage = dlg.m_voltage;
				rec.m_Width = dlg.m_width;
			
				rec.Update();
				rec.Close(); 
			}
			else
			{
				rec.Close();
			}
		}
		catch(CDBException cdb)
		{
			AfxMessageBox(cdb.m_strStateNativeOrigin);
		}		
		m_db1.Close();		
	}
	
}

void CPCircuitDlg::OnDatabaseDeletecircuit() 
{
	// TODO: Add your command handler code here
	CDeleteCircuit dlg1;
	if(dlg1.DoModal() == IDOK)
	{

		sDsn.Empty();
		sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);
		m_db1.Open(NULL,false,false,sDsn, false);
		CMyRecordset rec(&m_db1);

		try
		{
			rec.Open(CRecordset::dynaset, "SELECT *  FROM Circuits"); 
			while(!rec.IsEOF())
				rec.MoveNext();

			int count = rec.GetRecordCount();
			if(!rec.IsBOF())
				rec.MoveFirst();
			if(count <= 0 )
			{
				MessageBox(_TEXT("There are no records to delete"), _TEXT("Error"), MB_ICONSTOP);
				rec.Close();
				m_db1.Close();
				return;
			}
			if(count < dlg1.m_DeleteNumber)
			{
				MessageBox(_TEXT("There are no such record to delete! Index is to large!"), _TEXT("Error"), MB_ICONSTOP);
				rec.Close();
				m_db1.Close();
				return;
			}

			rec.Move(dlg1.m_DeleteNumber);
			rec.Delete();


			rec.Close(); 
			
		}

		catch(CDBException cdb)
		{
			AfxMessageBox(cdb.m_strStateNativeOrigin);
		}		
		m_db1.Close();		
	}
}

void CPCircuitDlg::OnDatabaseOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog fileDlg(TRUE,NULL,"*.mdb");
	if (fileDlg.DoModal() == IDOK)	//if file selected
	{
		sFile = fileDlg.GetPathName(); 
		sDsn.Empty();
		sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);
		//CRSIniWriter wr( _TEXT(strIni.GetBuffer(strIni.GetLength()) ) );
		//strIni.ReleaseBuffer();
		//wr.WriteString(_TEXT("DataBase"), _TEXT("Records"), _TEXT(fileName.GetBuffer(fileName.GetLength()) ));
		//fileName.ReleaseBuffer();
	}	
}

void CPCircuitDlg::OnAboutAuthor() 
{
	// TODO: Add your command handler code here
	CAuthor dlg;
	dlg.DoModal();
}

void CPCircuitDlg::OnAboutProgram() 
{
	// TODO: Add your command handler code here
	MessageBox(_TEXT("Програма контролю якості виготовлення печатних плат"), _TEXT("About program"));
}

void CPCircuitDlg::OnSearchNormalcircuits() 
{
	// TODO: Add your command handler code here
	m_fon.ShowWindow(SW_HIDE);
	if(m_List)
	{
		m_List->DeleteAllItems();
		m_List->ShowWindow(SW_HIDE);
		delete m_List;
		m_List = NULL;
	}

	m_List = new CMyListCtrl;
	CRect winRect;
	this->GetClientRect(&winRect);


	m_List->Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT, CRect(winRect.left + 20,winRect.top + 10,winRect.right - 20,winRect.bottom - 10), this, 1);
	m_List->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//insert columns
	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 50;
	lvColumn.pszText = " # ";
	m_List->InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 50;
	lvColumn.pszText = " ID ";
	m_List->InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	lvColumn.pszText = " Назва ";
	m_List->InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Матеріал ";
	m_List->InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Тип обробки ";
	m_List->InsertColumn(4, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Розмір, мм ";
	m_List->InsertColumn(5, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 70;
	lvColumn.pszText = " Опір, Ом ";
	m_List->InsertColumn(6, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 90;
	lvColumn.pszText = " Вольтаж, В ";
	m_List->InsertColumn(7, &lvColumn);

	int iRec = 0; 	
	
	// Build ODBC connection string
	sDsn.Empty();
	sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);
	CString SqlString;
	TRY
	{
		// Open the database
		m_db1.Open(NULL,false,false,sDsn);
		
		// Allocate the recordset
		CRecordset recset( &m_db1 );

		//  ID, CTID, MatID, ProcID, Width, Height, Length, Resistance, Voltage
		SqlString =  "SELECT * FROM Circuits";


		// Execute the query
		recset.Open(CRecordset::forwardOnly,SqlString,CRecordset::readOnly);

		CString sID, sCTID, sMatID, sProcID, sWidth, sLength, sHeight, sResistance, sVoltage;
		// Loop through each record
		int id = 0;
		CDBVariant varValue;
		BYTE IsDemaged, IsGood, IsTermGood, IsPowerGood, IsCurrentGood;

		while( !recset.IsEOF() )
		{

			// Copy each column into a variable
			recset.GetFieldValue("ID", sID);
			recset.GetFieldValue("CTID", sCTID);
			recset.GetFieldValue("MatID", sMatID);
			recset.GetFieldValue("ProcID", sProcID);
			recset.GetFieldValue("Width", sWidth);
			recset.GetFieldValue("Height", sHeight);
			recset.GetFieldValue("Length", sLength);
			recset.GetFieldValue("Resistance", sResistance);
			recset.GetFieldValue("Voltage", sVoltage);

			CDBVariant varValue1;
			recset.GetFieldValue("IsDemaged", varValue1, SQL_C_UTINYINT);
			IsDemaged = varValue1.m_chVal;

			CDBVariant varValue2;
			recset.GetFieldValue("IsGood", varValue2, SQL_C_UTINYINT);
			IsGood = varValue2.m_chVal;

			CDBVariant varValue3;
			recset.GetFieldValue("IsTermedGood", varValue3, SQL_C_UTINYINT);
			IsTermGood = varValue3.m_chVal;

			CDBVariant varValue4;
			recset.GetFieldValue("IsPoweredGood", varValue4, SQL_C_UTINYINT);
			IsPowerGood = varValue4.m_chVal;

			CDBVariant varValue5;
			recset.GetFieldValue("IsCurrentGood", varValue5, SQL_C_UTINYINT);
			IsCurrentGood = varValue5.m_chVal;


			int Resistance = 0, Voltage = 0;
			Resistance  = StringToInt(sResistance);
			Voltage  = StringToInt(sVoltage);


			if(!IsDemaged && IsGood && IsTermGood && IsPowerGood && IsCurrentGood && Resistance >= 30000 && (Voltage >= 500 && Voltage <= 700))
			{


			TCHAR buf[5];
			memset(buf, '\0', 5);
			itoa(iRec, buf, 10);
			// Insert values into the list control
			int nItem = m_List->InsertItem(iRec, buf); //insert first string column[0]

			m_List->SetItemText(nItem, 0, buf);

			m_List->SetItemText(nItem, 1, sID);

			id = StringToInt(sCTID);
			m_List->SetItemText(nItem, 2, reverseCTID.find(id)->second); 

			id = StringToInt(sMatID);
			m_List->SetItemText(nItem, 3, reverseMID.find(id)->second); 
			
			id = StringToInt(sProcID);
			m_List->SetItemText(nItem, 4, reversePID.find(id)->second); 

			CString sf;
			sf.Format(_TEXT("%s * %s * %s"),sLength, sWidth, sHeight);
			m_List->SetItemText(nItem, 5, sf); 

			m_List->SetItemText(nItem, 6, sResistance); 

			m_List->SetItemText(nItem, 7, sVoltage); 
		
			
			
			}
			iRec++;
			// goto next record
			recset.MoveNext();
		}
		// Close the database
		m_db1.Close();
	}
	CATCH(CDBException, e)
	{
		// If a database exception occured, show error msg
		AfxMessageBox("Database error: "+e->m_strError);
	}
	END_CATCH;	
}

void CPCircuitDlg::OnSearchDemagedcircuits() 
{
	// TODO: Add your command handler code here
	m_fon.ShowWindow(SW_HIDE);
	if(m_List)
	{
		m_List->DeleteAllItems();
		m_List->ShowWindow(SW_HIDE);
		delete m_List;
		m_List = NULL;
	}

	m_List = new CMyListCtrl;
	CRect winRect;
	this->GetClientRect(&winRect);


	m_List->Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT, CRect(winRect.left + 20,winRect.top + 10,winRect.right - 20,winRect.bottom - 10), this, 1);
	m_List->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//insert columns
	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 50;
	lvColumn.pszText = " # ";
	m_List->InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 50;
	lvColumn.pszText = " ID ";
	m_List->InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	lvColumn.pszText = " Назва ";
	m_List->InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Матеріал ";
	m_List->InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Тип обробки ";
	m_List->InsertColumn(4, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.pszText = " Розмір, мм ";
	m_List->InsertColumn(5, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 70;
	lvColumn.pszText = " Опір, Ом ";
	m_List->InsertColumn(6, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 90;
	lvColumn.pszText = " Вольтаж, В ";
	m_List->InsertColumn(7, &lvColumn);

	int iRec = 0; 	
	
	// Build ODBC connection string
	sDsn.Empty();
	sDsn.Format("ODBC;DRIVER={%s};DSN=%s;DBQ=%s",sDriver, sFile, sFile);
	CString SqlString;
	TRY
	{
		// Open the database
		m_db1.Open(NULL,false,false,sDsn);
		
		// Allocate the recordset
		CRecordset recset( &m_db1 );

		//  ID, CTID, MatID, ProcID, Width, Height, Length, Resistance, Voltage
		SqlString =  "SELECT * FROM Circuits";


		// Execute the query
		recset.Open(CRecordset::forwardOnly,SqlString,CRecordset::readOnly);

		CString sID, sCTID, sMatID, sProcID, sWidth, sLength, sHeight, sResistance, sVoltage;
		// Loop through each record
		int id = 0;
		CDBVariant varValue;
		BYTE IsDemaged, IsGood, IsTermGood, IsPowerGood, IsCurrentGood;

		while( !recset.IsEOF() )
		{

			// Copy each column into a variable
			recset.GetFieldValue("ID", sID);
			recset.GetFieldValue("CTID", sCTID);
			recset.GetFieldValue("MatID", sMatID);
			recset.GetFieldValue("ProcID", sProcID);
			recset.GetFieldValue("Width", sWidth);
			recset.GetFieldValue("Height", sHeight);
			recset.GetFieldValue("Length", sLength);
			recset.GetFieldValue("Resistance", sResistance);
			recset.GetFieldValue("Voltage", sVoltage);

			CDBVariant varValue1;
			recset.GetFieldValue("IsDemaged", varValue1, SQL_C_UTINYINT);
			IsDemaged = varValue1.m_chVal;

			CDBVariant varValue2;
			recset.GetFieldValue("IsGood", varValue2, SQL_C_UTINYINT);
			IsGood = varValue2.m_chVal;

			CDBVariant varValue3;
			recset.GetFieldValue("IsTermedGood", varValue3, SQL_C_UTINYINT);
			IsTermGood = varValue3.m_chVal;

			CDBVariant varValue4;
			recset.GetFieldValue("IsPoweredGood", varValue4, SQL_C_UTINYINT);
			IsPowerGood = varValue4.m_chVal;

			CDBVariant varValue5;
			recset.GetFieldValue("IsCurrentGood", varValue5, SQL_C_UTINYINT);
			IsCurrentGood = varValue5.m_chVal;


			int Resistance = 0, Voltage = 0;
			Resistance  = StringToInt(sResistance);
			Voltage  = StringToInt(sVoltage);


			if(IsDemaged || !IsGood || !IsTermGood || !IsPowerGood || !IsCurrentGood || Resistance < 30000 || (Voltage < 500 || Voltage > 700))
			{


			TCHAR buf[5];
			memset(buf, '\0', 5);
			itoa(iRec, buf, 10);
			// Insert values into the list control
			int nItem = m_List->InsertItem(iRec, buf); //insert first string column[0]

			m_List->SetItemText(nItem, 0, buf);

			m_List->SetItemText(nItem, 1, sID);

			id = StringToInt(sCTID);
			m_List->SetItemText(nItem, 2, reverseCTID.find(id)->second); 

			id = StringToInt(sMatID);
			m_List->SetItemText(nItem, 3, reverseMID.find(id)->second); 
			
			id = StringToInt(sProcID);
			m_List->SetItemText(nItem, 4, reversePID.find(id)->second); 

			CString sf;
			sf.Format(_TEXT("%s * %s * %s"),sLength, sWidth, sHeight);
			m_List->SetItemText(nItem, 5, sf); 

			m_List->SetItemText(nItem, 6, sResistance); 

			m_List->SetItemText(nItem, 7, sVoltage); 
		
			
			
			}
			iRec++;
			// goto next record
			recset.MoveNext();
		}
		// Close the database
		m_db1.Close();
	}
	CATCH(CDBException, e)
	{
		// If a database exception occured, show error msg
		AfxMessageBox("Database error: "+e->m_strError);
	}
	END_CATCH;	
}

void CPCircuitDlg::OnMenuExit() 
{
	// TODO: Add your command handler code here
	CExitDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		CDialog::OnOK();
	
	}
}

void CPCircuitDlg::OnUpdateVisualizationShowdiagram(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here

}

void CPCircuitDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDown(nFlags, point);	
}

void CPCircuitDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_managerOK || m_controllerOK || m_programmerOK)
	{
		this->GetMenu()->EnableMenuItem(ID_VISUALIZATION_SHOWDIAGRAM,  MF_ENABLED ); 
		this->GetMenu()->EnableMenuItem(ID_VISUALIZATION_SHOWDATABASE,  MF_ENABLED );
		this->GetMenu()->EnableMenuItem(ID_SEARCH_NORMALCIRCUITS,  MF_ENABLED ); 
		this->GetMenu()->EnableMenuItem(ID_SEARCH_DEMAGEDCIRCUITS,  MF_ENABLED );
		this->GetMenu()->EnableMenuItem(ID_DATABASE_OPEN,  MF_ENABLED );


	}
	else
	{
		this->GetMenu()->EnableMenuItem(ID_VISUALIZATION_SHOWDIAGRAM,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED ); 
		this->GetMenu()->EnableMenuItem(ID_VISUALIZATION_SHOWDATABASE,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED );
		this->GetMenu()->EnableMenuItem(ID_SEARCH_NORMALCIRCUITS,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED ); 
		this->GetMenu()->EnableMenuItem(ID_SEARCH_DEMAGEDCIRCUITS,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED );
		this->GetMenu()->EnableMenuItem(ID_DATABASE_OPEN,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED );
	}


	

	if(m_programmerOK)
	{
		this->GetMenu()->EnableMenuItem(ID_DATABASE_CREATE,  MF_ENABLED ); 
		this->GetMenu()->EnableMenuItem(ID_DATABASE_DELETECIRCUIT,  MF_ENABLED );

	}
	else
	{
		this->GetMenu()->EnableMenuItem(ID_DATABASE_CREATE,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED ); 
		this->GetMenu()->EnableMenuItem(ID_DATABASE_DELETECIRCUIT,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED );			
	}

	if(m_controllerOK || m_programmerOK)
	{
		this->GetMenu()->EnableMenuItem(ID_DATABASE_ADDCIRCUIT,  MF_ENABLED );
		this->GetMenu()->EnableMenuItem(ID_DATABASE_EDITCIRCUIT,  MF_ENABLED );

	}
	else
	{
		this->GetMenu()->EnableMenuItem(ID_DATABASE_ADDCIRCUIT,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED );
		this->GetMenu()->EnableMenuItem(ID_DATABASE_EDITCIRCUIT,  MF_BYCOMMAND | MF_DISABLED | MF_GRAYED );		
			
	}


	CDialog::OnMouseMove(nFlags, point);
}

void CPCircuitDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CExitDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		CDialog::OnClose();
	
	}

}
