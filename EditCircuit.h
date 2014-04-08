#if !defined(AFX_EDITCIRCUIT_H__71CF4E6A_46BD_4616_8475_6050101191A8__INCLUDED_)
#define AFX_EDITCIRCUIT_H__71CF4E6A_46BD_4616_8475_6050101191A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditCircuit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditCircuit dialog

class CEditCircuit : public CDialog
{
// Construction
public:
	CEditCircuit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditCircuit)
	enum { IDD = IDD_EDIT_DIALOG };
	int		m_EditNumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditCircuit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditCircuit)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITCIRCUIT_H__71CF4E6A_46BD_4616_8475_6050101191A8__INCLUDED_)
