#include "pch.h"
#include "WordGLXTNew.h"
#include "Zdmlb.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CZdmlb::CZdmlb()
{

}

CZdmlb::~CZdmlb()
{

}

int CZdmlb::GetDWbh()
{
	return DWbh;
}

void CZdmlb::SetDwbh(int iDWbh)
{
	DWbh = iDWbh;
}

int CZdmlb::GetLBbh()
{
	return LBbh;
}

void CZdmlb::SetLBbh(int iLBbh)
{
	LBbh = iLBbh;
}

CString CZdmlb::GetLBmc()
{
	return LBmc;
}

void CZdmlb::SetLBmc(CString cLBmc)
{
	LBmc = cLBmc;
}

void CZdmlb::sql_insert()
{
	ADOConn m_AdoConn;
	CString strLBbh;
	strLBbh.Format("%d", LBbh);
	CString strDWbh;
	strDWbh.Format("%d", DWbh);
	_bstr_t vSQL;
	vSQL = "INSERT INTO Zdmlb(LBbh,DWbh,LBmc)VALUES(" + strLBbh + ","
		+ strDWbh + ",'" + LBmc + "')";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

void CZdmlb::sql_update(int iDWbh, int iLBbh)
{
	ADOConn m_AdoConn;
	CString strLBbh;
	strLBbh.Format("%d", iLBbh);
	CString strDWbh;
	strDWbh.Format("%d", iDWbh);
	_bstr_t vSQL;
	vSQL = "UPDATE Zdmlb SET LBmc='"
		+ LBmc + "' WHERE DWbh=" + " " + strDWbh + " and LBbh=" + " " + strLBbh + "";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

void CZdmlb::sql_delete(int iDWbh, int iLBbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from Zdmlb where DWbh=%i and LBbh=%i", iDWbh, iLBbh);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}

void CZdmlb::sql_deletedw(int iDWbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from Zdmlb where DWbh='%i'", iDWbh);
	m_AdoConn.ExecuteSQL((_bstr_t)sql); //执行SQL语句
	m_AdoConn.ExitConnect();
}

void CZdmlb::Load_dep()
{
	//连接数据库
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	//设置SQL语句
	_bstr_t vSQL;
	vSQL = "SELECT*FROM Zdmlb ORDER BY DWbh";
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL); //执行SQL语句
	//初始化数组
	a_DWbh.RemoveAll();//单位编号
	a_LBbh.RemoveAll();//类别编号
	a_LBmc.RemoveAll();//类别名称
	while (m_pRecordset->adoEOF == 0)
	{
		a_LBmc.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("LBmc"));
		a_DWbh.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("DWbh"));
		a_LBbh.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("LBbh"));
		m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();//断开连接数据库
}

int CZdmlb::HaveId(int iDWbh, int iLBbh)
{
	//连接数据库
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("SELECT*FROM Zdmlb WHERE DWbh='%i' AND LBbh='%i'", iDWbh, iLBbh);
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql); //执行SQL语句
	if (m_pRecordset->adoEOF)
		return -1;
	else
		return 1;
	m_AdoConn.ExitConnect();//断开连接数据库
}