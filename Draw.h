#if !defined(AFX_DRAW_H__FA42013F_60A9_4AC5_8E60_C9A0C61FBA26__INCLUDED_)
#define AFX_DRAW_H__FA42013F_60A9_4AC5_8E60_C9A0C61FBA26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Draw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDraw dialog
#include "ColourPicker.h"
#include "PieChartCtrl.h"

class CDraw : public CDialog
{
// Construction
public:
	CDraw(CWnd* pParent = NULL);   // standard constructor
	COLORREF m_colorBlue, m_colorYellow, m_colorGreen, m_colorText;
	CPieChartCtrl m_wndChart;

// Dialog Data
	//{{AFX_DATA(CDraw)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CColourPicker	m_wndTextColor;
	CColourPicker	m_wndBackColor;
	CString	m_strInfo;
	CString	m_strUser;
	int		m_nAngleBlue;
	int		m_nAngleYellow;
	int		m_nAngleGreen;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDraw)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDraw)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAW_H__FA42013F_60A9_4AC5_8E60_C9A0C61FBA26__INCLUDED_)
