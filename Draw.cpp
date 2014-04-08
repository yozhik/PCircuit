// Draw.cpp : implementation file
//

#include "stdafx.h"
#include "PCircuit.h"
#include "Draw.h"
#include "PieChartCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDraw dialog


CDraw::CDraw(CWnd* pParent /*=NULL*/)
	: CDialog(CDraw::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDraw)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
		m_strInfo = _T("");
	m_colorBlue = RGB(255,0,0); //red
	m_colorYellow = RGB(0,0,0); //black
	m_colorText = RGB(255,255,255); //white
}


void CDraw::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDraw)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDraw, CDialog)
	//{{AFX_MSG_MAP(CDraw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDraw message handlers

BOOL CDraw::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_wndChart.SubclassDlgItem(IDC_PIECHART1, this);

	m_wndChart.Reset();
	m_wndChart.AddPiece(m_colorBlue,		m_colorText, m_nAngleBlue, m_strInfo);
	m_wndChart.AddPiece(m_colorYellow,		m_colorText, m_nAngleYellow, m_strInfo);
	m_wndChart.SetTitle("Діаграма якості печатних плат");
	m_wndChart.InvalidateRect(NULL, FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDraw::OnButton1() 
{
	// TODO: Add your control notification handler code here

}


void CDraw::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
