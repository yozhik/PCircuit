// Pass.cpp : implementation file
//

#include "stdafx.h"
#include "PCircuit.h"
#include "Pass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPass dialog


CPass::CPass(CWnd* pParent /*=NULL*/)
	: CDialog(CPass::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPass)
	m_password = _T("");
	m_r1 = 0;
//	m_r2 = -1;
//	m_r3 = -1;
	//}}AFX_DATA_INIT
}


void CPass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPass)
	DDX_Text(pDX, IDC_EDIT1, m_password);
	DDV_MaxChars(pDX, m_password, 20);
	DDX_Radio(pDX, IDC_RADIO1, m_r1);
	//DDX_Radio(pDX, IDC_RADIO2, m_r2);
	//DDX_Radio(pDX, IDC_RADIO3, m_r3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPass, CDialog)
	//{{AFX_MSG_MAP(CPass)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPass message handlers

void CPass::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(1);

	CDialog::OnOK();
}
