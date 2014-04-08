#if !defined(AFX_EXITDLG_H__39BD3324_7940_432D_900E_CE94148AD7D1__INCLUDED_)
#define AFX_EXITDLG_H__39BD3324_7940_432D_900E_CE94148AD7D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExitDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExitDlg dialog

class CExitDlg : public CDialog
{
// Construction
public:
	CExitDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExitDlg)
	enum { IDD = IDD_EXIT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExitDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXITDLG_H__39BD3324_7940_432D_900E_CE94148AD7D1__INCLUDED_)
