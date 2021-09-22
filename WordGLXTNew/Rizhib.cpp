#include "pch.h"
#include "WordGLXTNew.h"
#include "Rizhib.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRizhib::CRizhib()
{

}

CRizhib::~CRizhib()
{

}

CString CRizhib::GetName()
{
	return Name;
}

void CRizhib::SetName(CString cName)
{
	Name = cName;
}

CString CRizhib::GetDLsj()
{
	return DLsj;
}

void CRizhib::SetDLsj(CString cDLsj)
{
	DLsj = cDLsj;
}

CString CRizhib::GetDZ()
{
	return DZ;
}

void CRizhib::SetDZ(CString cDZ)
{
	DZ = cDZ;
}

void CRizhib::sql_insert()
{
	ADOConn m_AdoConn;
	_bstr_t vSQL;
	vSQL = "insert into Rizhib(Name,DLsj,DZ)values('" + Name + "','" + DLsj + "','" + DZ + "')";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}
