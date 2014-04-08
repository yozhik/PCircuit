#if !defined(AFX_DELETECIRCUIT_H__3249DA12_A744_426C_8B52_CBAAE9597B83__INCLUDED_)
#define AFX_DELETECIRCUIT_H__3249DA12_A744_426C_8B52_CBAAE9597B83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeleteCircuit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeleteCircuit dialog

class CDeleteCircuit : public CDialog
{
// Construction
public:
	CDeleteCircuit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteCircuit)
	enum { IDD = IDD_DELETE_DIALOG };
	int		m_DeleteNumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteCircuit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeleteCircuit)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETECIRCUIT_H__3249DA12_A744_426C_8B52_CBAAE9597B83__INCLUDED_)
