#if !defined(AFX_AUTHOR_H__D84644E5_C784_4764_8FD1_E917730E9B11__INCLUDED_)
#define AFX_AUTHOR_H__D84644E5_C784_4764_8FD1_E917730E9B11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Author.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAuthor dialog

class CAuthor : public CDialog
{
// Construction
public:
	CAuthor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAuthor)
	enum { IDD = IDD_AUTHOR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAuthor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAuthor)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTHOR_H__D84644E5_C784_4764_8FD1_E917730E9B11__INCLUDED_)
