#if !defined(AFX_PASS_H__21AE32A4_2C5E_4504_A964_3E75C92BEF77__INCLUDED_)
#define AFX_PASS_H__21AE32A4_2C5E_4504_A964_3E75C92BEF77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Pass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPass dialog

class CPass : public CDialog
{
// Construction
public:
	CPass(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPass)
	enum { IDD = IDD_PASSWORD_DIALOG };
	CString	m_password;
	int		m_r1;
	//int		m_r2;
	//int		m_r3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPass)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPass)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASS_H__21AE32A4_2C5E_4504_A964_3E75C92BEF77__INCLUDED_)
