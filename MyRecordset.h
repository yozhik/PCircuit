#if !defined(AFX_MYRECORDSET_H__CF6ADB23_0F2F_46B4_ADD1_F1F2A376D04C__INCLUDED_)
#define AFX_MYRECORDSET_H__CF6ADB23_0F2F_46B4_ADD1_F1F2A376D04C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyRecordset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyRecordset recordset

class CMyRecordset : public CRecordset
{
public:
	CMyRecordset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMyRecordset)

// Field/Param Data
	//{{AFX_FIELD(CMyRecordset, CRecordset)
	long	m_ID;
	long	m_CTID;
	long	m_MatID;
	long	m_ProcID;
	int		m_Width;
	int		m_Length;
	int		m_Height;
	BOOL	m_IsDemaged;
	BOOL	m_IsGood;
	BOOL	m_IsTermedGood;
	BOOL	m_IsPoweredGood;
	BOOL	m_IsCurrentGood;
	long	m_Resistance;
	long	m_Voltage;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyRecordset)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYRECORDSET_H__CF6ADB23_0F2F_46B4_ADD1_F1F2A376D04C__INCLUDED_)
