// DeleteCircuit.cpp : implementation file
//

#include "stdafx.h"
#include "PCircuit.h"
#include "DeleteCircuit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteCircuit dialog


CDeleteCircuit::CDeleteCircuit(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteCircuit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteCircuit)
	m_DeleteNumber = 0;
	//}}AFX_DATA_INIT
}


void CDeleteCircuit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteCircuit)
	DDX_Text(pDX, IDC_EDIT1, m_DeleteNumber);
	DDV_MinMaxInt(pDX, m_DeleteNumber, 1, 65000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeleteCircuit, CDialog)
	//{{AFX_MSG_MAP(CDeleteCircuit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteCircuit message handlers

void CDeleteCircuit::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(1);
	
	CDialog::OnOK();
}
