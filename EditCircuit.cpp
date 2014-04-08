// EditCircuit.cpp : implementation file
//

#include "stdafx.h"
#include "PCircuit.h"
#include "EditCircuit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditCircuit dialog


CEditCircuit::CEditCircuit(CWnd* pParent /*=NULL*/)
	: CDialog(CEditCircuit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditCircuit)
	m_EditNumber = 0;
	//}}AFX_DATA_INIT
}


void CEditCircuit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditCircuit)
	DDX_Text(pDX, IDC_EDIT1, m_EditNumber);
	DDV_MinMaxInt(pDX, m_EditNumber, 1, 65000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditCircuit, CDialog)
	//{{AFX_MSG_MAP(CEditCircuit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditCircuit message handlers

void CEditCircuit::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(1);
	CDialog::OnOK();
}
