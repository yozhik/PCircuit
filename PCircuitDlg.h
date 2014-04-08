// PCircuitDlg.h : header file
//

#if !defined(AFX_PCIRCUITDLG_H__2F66304A_C5D4_4D33_975E_2E54E706B427__INCLUDED_)
#define AFX_PCIRCUITDLG_H__2F66304A_C5D4_4D33_975E_2E54E706B427__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyListCtrl.h"
#include "AddNewCircuit.h"

/////////////////////////////////////////////////////////////////////////////
// CPCircuitDlg dialog
#include <map>
using namespace std;

class CPCircuitDlg : public CDialog
{
// Construction
public:
	CPCircuitDlg(CWnd* pParent = NULL);	// standard constructor

	//************************************
	CMenu m_menu;
	CMyListCtrl *m_List;
	CDatabase m_db1;

	CString sDriver;
	CString sFile;
	CString sDsn;

	map<CString, int> CTID;
	map<CString, int> MID;
	map<CString, int> PID;

	map<int, CString> reverseCTID;
	map<int, CString> reverseMID;
	map<int, CString> reversePID;

	//************************************
	void AddNewCircuit(CAddNewCircuit &dlg);
	void PopulateMap();
	int StringToInt(CString strVal);

	bool m_managerOK, m_programmerOK, m_controllerOK;
	//************************************
// Dialog Data
	//{{AFX_DATA(CPCircuitDlg)
	enum { IDD = IDD_PCIRCUIT_DIALOG };
	CStatic	m_fon;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPCircuitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPCircuitDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnVisualizationShowdiagram();
	afx_msg void OnPasswordEnter();
	virtual void OnOK();
	afx_msg void OnVisualizationShowdatabase();
	afx_msg void OnDestroy();
	afx_msg void OnDatabaseAddcircuit();
	afx_msg void OnDatabaseEditcircuit();
	afx_msg void OnDatabaseDeletecircuit();
	afx_msg void OnDatabaseOpen();
	afx_msg void OnAboutAuthor();
	afx_msg void OnAboutProgram();
	afx_msg void OnSearchNormalcircuits();
	afx_msg void OnSearchDemagedcircuits();
	afx_msg void OnMenuExit();
	afx_msg void OnUpdateVisualizationShowdiagram(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCIRCUITDLG_H__2F66304A_C5D4_4D33_975E_2E54E706B427__INCLUDED_)
