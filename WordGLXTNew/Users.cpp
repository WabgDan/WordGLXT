#include "pch.h"
#include "WordGLXTNew.h"
#include "Users.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUsers::CUsers()
{

}

CUsers::~CUsers()
{

}

CString CUsers::GetUsername()
{
	return Username;
}

void CUsers::SetUsername(CString cUsername)
{
	Username = cUsername;
}

CString CUsers::GetPwd()
{
	return Pwd;
}

void CUsers::SetPwd(CString cPwd)
{
	Pwd = cPwd;
}

CString CUsers::GetJB()
{
	return JB;
}

void CUsers::SetJB(CString cJB)
{
	JB = cJB;
}

void CUsers::sql_insert()
{
	ADOConn m_AdoConn;
	_bstr_t vSQL;
	vSQL = "insert into Users(Username,Pwd,JB)values('" + Username + "','" + Pwd + "','" + JB + "')";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

void CUsers::sql_update(CString cUsername)
{
	ADOConn m_AdoConn;
	_bstr_t vSQL;
	vSQL = "update Users set Pwd='" + Pwd + "',JB='" + JB + "' where Username=" + " " + cUsername + "'";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

void CUsers::sql_delete(CString cUsername)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from Users where Username='%s'", cUsername);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}

int CUsers::Havename(CString cUsername)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("SELECT*FROM Users WHERE Username='%s'", cUsername);
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if (m_pRecordset->adoEOF)
		return -1;
	else
		return 1;
	m_AdoConn.ExitConnect();
}

int CUsers::HaveCzy(CString cUsername, CString cPwd)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("SELECT * FROM Users WHERE Username='%s' AND Pwd='%s'", cUsername, cPwd);
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if (m_pRecordset->adoEOF)
		return -1;
	else
		return 1;
	m_AdoConn.ExitConnect();
}

int CUsers::HaveCzyjb(CString cUsername, CString cPwd, CString cJB)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("SELECT*FROM Users WHERE Username='%s' AND Pwd='%s' AND JB='%s'", cUsername, cPwd, cJB);
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if (m_pRecordset->adoEOF)
		return -1;
	else
		return 1;
	m_AdoConn.ExitConnect();
}

void CUsers::sql_updatepwd(CString cUsername)
{
	ADOConn m_AdoConn;
	_bstr_t vSQL;
	vSQL = "UPDATE Users SET Pwd='" + Pwd + "' WHERE Username=" + " '" + cUsername + "'";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}