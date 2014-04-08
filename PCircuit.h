// PCircuit.h : main header file for the PCIRCUIT application
//

#if !defined(AFX_PCIRCUIT_H__25286881_6AA0_42B8_ABFE_8D79F6829C51__INCLUDED_)
#define AFX_PCIRCUIT_H__25286881_6AA0_42B8_ABFE_8D79F6829C51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPCircuitApp:
// See PCircuit.cpp for the implementation of this class
//

class CPCircuitApp : public CWinApp
{
public:
	CPCircuitApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPCircuitApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPCircuitApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCIRCUIT_H__25286881_6AA0_42B8_ABFE_8D79F6829C51__INCLUDED_)
