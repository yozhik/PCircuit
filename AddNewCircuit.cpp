// AddNewCircuit.cpp : implementation file
//

#include "stdafx.h"
#include "PCircuit.h"
#include "AddNewCircuit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddNewCircuit dialog


CAddNewCircuit::CAddNewCircuit(CWnd* pParent /*=NULL*/)
	: CDialog(CAddNewCircuit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddNewCircuit)
	m_len = 0;
	m_width = 0;
	m_height = 0;
	m_resistance = 0;
	m_voltage = 0;
	m_isdemaged = FALSE;
	m_isgoodp = FALSE;
	m_istermed = FALSE;
	m_iscurrent = FALSE;
	m_ispowered = FALSE;
	m_combo1 = _T("");
	m_combo2 = _T("");
	m_combo3 = _T("");
	//}}AFX_DATA_INIT
}


void CAddNewCircuit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddNewCircuit)
	DDX_Control(pDX, IDOK, m_OK);
	DDX_Control(pDX, IDC_COMBO3, m_ProcID);
	DDX_Control(pDX, IDC_COMBO2, m_MatID);
	DDX_Control(pDX, IDC_COMBO1, m_CTID);
	DDX_Text(pDX, IDC_EDIT1, m_len);
	DDV_MinMaxInt(pDX, m_len, 1, 2000);
	DDX_Text(pDX, IDC_EDIT2, m_width);
	DDV_MinMaxInt(pDX, m_width, 1, 2000);
	DDX_Text(pDX, IDC_EDIT3, m_height);
	DDV_MinMaxInt(pDX, m_height, 1, 2000);
	DDX_Text(pDX, IDC_EDIT4, m_resistance);
	DDV_MinMaxInt(pDX, m_resistance, 1, 65000);
	DDX_Text(pDX, IDC_EDIT5, m_voltage);
	DDV_MinMaxInt(pDX, m_voltage, 1, 65000);
	DDX_Check(pDX, IDC_CHECK2, m_isdemaged);
	DDX_Check(pDX, IDC_CHECK3, m_isgoodp);
	DDX_Check(pDX, IDC_CHECK4, m_istermed);
	DDX_Check(pDX, IDC_CHECK5, m_iscurrent);
	DDX_Check(pDX, IDC_CHECK6, m_ispowered);
	DDX_CBString(pDX, IDC_COMBO1, m_combo1);
	DDX_CBString(pDX, IDC_COMBO2, m_combo2);
	DDX_CBString(pDX, IDC_COMBO3, m_combo3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddNewCircuit, CDialog)
	//{{AFX_MSG_MAP(CAddNewCircuit)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddNewCircuit message handlers

void CAddNewCircuit::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(1);

	k1 = CTID.find(m_combo1)->second;
	k3 = PID.find(m_combo3)->second;
	k2 = MID.find(m_combo2)->second;


	CDialog::OnOK();
}

BOOL CAddNewCircuit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//Optimesed variant conecting to Database
	map<CString, int>::iterator pMap;

	for(pMap = CTID.begin(); pMap != CTID.end(); pMap++)
	{
		m_CTID.AddString((*pMap).first);
	}

	for(pMap = MID.begin(); pMap != MID.end(); pMap++)
	{
		m_MatID.AddString((*pMap).first);
	}

	for(pMap = PID.begin(); pMap != PID.end(); pMap++)
	{
		m_ProcID.AddString((*pMap).first);
	}

	m_combo1 = CTID.begin()->first;
	m_combo2 = MID.begin()->first;
	m_combo3 = PID.begin()->first;


	/*	CDatabase m_db1;

	try
	{
		// Open the database
		m_db1.Open(NULL,false,false,sDsn);
		
		// Allocate the recordset

		CRecordset recset1( &m_db1 );
		CRecordset recset2( &m_db1 );
		CRecordset recset3( &m_db1 );


		CString sCTID, sMatID, sProcID;

		CString SqlString1, SqlString2, SqlString3;
		SqlString1 =  "SELECT CName FROM CircTypes";
		SqlString2 =  "SELECT MName FROM Matherials";
		SqlString3 =  "SELECT PName FROM ProcTypes";
		// Loop through each record
			
		recset1.Open(CRecordset::forwardOnly,SqlString1,CRecordset::readOnly);
		while( !recset1.IsEOF() )
		{
			// Copy each column into a variable
			recset1.GetFieldValue("CName", sCTID);
			m_CTID.AddString(sCTID);
			recset1.MoveNext();
		}
		recset1.Close();

		recset2.Open(CRecordset::forwardOnly,SqlString2,CRecordset::readOnly);
		while( !recset2.IsEOF() )
		{
			// Copy each column into a variable
			recset2.GetFieldValue("MName", sMatID);
			m_MatID.AddString(sMatID);
			recset2.MoveNext();
		}
		recset2.Close();

		recset3.Open(CRecordset::forwardOnly,SqlString3,CRecordset::readOnly);
		while( !recset3.IsEOF() )
		{
			// Copy each column into a variable
			recset3.GetFieldValue("PName", sProcID);
			m_ProcID.AddString(sProcID);
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
*/
	UpdateData(0);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddNewCircuit::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	CTID.clear();
	MID.clear();
	PID.clear();
}
