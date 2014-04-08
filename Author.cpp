// Author.cpp : implementation file
//

#include "stdafx.h"
#include "PCircuit.h"
#include "Author.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAuthor dialog


CAuthor::CAuthor(CWnd* pParent /*=NULL*/)
	: CDialog(CAuthor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAuthor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAuthor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAuthor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAuthor, CDialog)
	//{{AFX_MSG_MAP(CAuthor)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAuthor message handlers
