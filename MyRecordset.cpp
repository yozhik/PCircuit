// MyRecordset.cpp : implementation file
//

#include "stdafx.h"
#include "PCircuit.h"
#include "MyRecordset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyRecordset

IMPLEMENT_DYNAMIC(CMyRecordset, CRecordset)

CMyRecordset::CMyRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMyRecordset)
	m_ID = 0;
	m_CTID = 0;
	m_MatID = 0;
	m_ProcID = 0;
	m_Width = 0;
	m_Length = 0;
	m_Height = 0;
	m_IsDemaged = FALSE;
	m_IsGood = FALSE;
	m_IsTermedGood = FALSE;
	m_IsPoweredGood = FALSE;
	m_IsCurrentGood = FALSE;
	m_Resistance = 0;
	m_Voltage = 0;
	m_nFields = 14;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CMyRecordset::GetDefaultConnect()
{
	return _T("ODBC;DSN=MS Access Database");
}

CString CMyRecordset::GetDefaultSQL()
{
	return _T("[Circuits]");
}

void CMyRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMyRecordset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[CTID]"), m_CTID);
	RFX_Long(pFX, _T("[MatID]"), m_MatID);
	RFX_Long(pFX, _T("[ProcID]"), m_ProcID);
	RFX_Int(pFX, _T("[Width]"), m_Width);
	RFX_Int(pFX, _T("[Length]"), m_Length);
	RFX_Int(pFX, _T("[Height]"), m_Height);
	RFX_Bool(pFX, _T("[IsDemaged]"), m_IsDemaged);
	RFX_Bool(pFX, _T("[IsGood]"), m_IsGood);
	RFX_Bool(pFX, _T("[IsTermedGood]"), m_IsTermedGood);
	RFX_Bool(pFX, _T("[IsPoweredGood]"), m_IsPoweredGood);
	RFX_Bool(pFX, _T("[IsCurrentGood]"), m_IsCurrentGood);
	RFX_Long(pFX, _T("[Resistance]"), m_Resistance);
	RFX_Long(pFX, _T("[Voltage]"), m_Voltage);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMyRecordset diagnostics

#ifdef _DEBUG
void CMyRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMyRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
