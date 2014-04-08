#if !defined(AFX_ADDNEWCIRCUIT_H__08A16E02_9075_48E5_823F_5BDDAD65DD41__INCLUDED_)
#define AFX_ADDNEWCIRCUIT_H__08A16E02_9075_48E5_823F_5BDDAD65DD41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddNewCircuit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddNewCircuit dialog
#include <map>
using namespace std;

class CAddNewCircuit : public CDialog
{
// Construction
public:
	CAddNewCircuit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddNewCircuit)
	enum { IDD = IDD_ADD_DIALOG };
	CButton	m_OK;
	CComboBox	m_ProcID;
	CComboBox	m_MatID;
	CComboBox	m_CTID;
	int		m_len;
	int		m_width;
	int		m_height;
	int		m_resistance;
	int		m_voltage;
	BOOL	m_isdemaged;
	BOOL	m_isgoodp;
	BOOL	m_istermed;
	BOOL	m_iscurrent;
	BOOL	m_ispowered;
	CString sDriver;
	CString sFile;
	CString sDsn;
	CString	m_combo1;
	CString	m_combo2;
	CString	m_combo3;
	//}}AFX_DATA
	map<CString, int> CTID;  int k1;
	map<CString, int> MID;   int k2; 
	map<CString, int> PID;   int k3; 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddNewCircuit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddNewCircuit)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDNEWCIRCUIT_H__08A16E02_9075_48E5_823F_5BDDAD65DD41__INCLUDED_)
