#include "pch.h"
#include "WordGLXTNew.h"
#include "Zdxxb.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CZdxxb::CZdxxb()
{

}

CZdxxb::~CZdxxb()
{

}

int CZdxxb::GetDWbh()
{
	return DWbh;
}

void CZdxxb::SetDWbh(int iDWbh)
{
	DWbh = iDWbh;
}

int CZdxxb::GetLBbh()
{
	return LBbh;
}

void CZdxxb::SetLBbh(int iLBbh)
{
	LBbh = iLBbh;
}

int CZdxxb::GetWDbh()
{
	return WDbh;
}

void CZdxxb::SetWDbh(int iWDbh)
{
	WDbh = iWDbh;
}

CString CZdxxb::GetGJz()
{
	return GJz;
}

void CZdxxb::SetGJz(CString cGJz)
{
	GJz = cGJz;
}

CString CZdxxb::GetWDmc()
{
	return WDmc;
}

void CZdxxb::SetWDmc(CString cWDmc)
{
	WDmc = cWDmc;
}

CString CZdxxb::GetWJlj()
{
	return WJlj;
}

void CZdxxb::SetWJlj(CString cWJlj)
{
	WJlj = cWJlj;
}

CString CZdxxb::GetMemo()
{
	return Memo;
}

void CZdxxb::SetMemo(CString cMemo)
{
	Memo = cMemo;
}

CString CZdxxb::GetTjrxm()
{
	return Tjrxm;
}

void CZdxxb::SetTjrxm(CString cTjrxm)
{
	Tjrxm = cTjrxm;
}

void CZdxxb::sql_insert()
{
	ADOConn m_AdoConn;
	CString strLBbh;
	strLBbh.Format("%d", LBbh);
	CString strWDbh;
	strWDbh.Format("%d", WDbh);
	CString strDWbh;
	strDWbh.Format("%d", DWbh);
	_bstr_t vSQL;
	vSQL = "INSERT INTO Zdxxb(DWbh,LBbh,WDbh,GJz,WDmc,WJlj,Memo,Tjrxm)VALUES("
		+ strDWbh + "," + strLBbh + "," + strWDbh + ",'" + GJz + "','" + WDmc + "','" + WJlj + "','"
		+ Memo + "','" + Tjrxm + "')";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

void CZdxxb::sql_update(int iWDbh)
{
	ADOConn m_AdoConn;
	CString strLBbh;
	strLBbh.Format("%d", LBbh);
	CString strWDbh;
	strWDbh.Format("%d", iWDbh);
	CString strDWbh;
	strDWbh.Format("%d", DWbh);
	_bstr_t vSQL;
	vSQL = "UPDATE Zdxxb SET DWbh=" + strDWbh + ",LBbh=" + strLBbh + ",WDmc='" + WDmc + "',GJz='"
		+ GJz + "',WJlj='" + WJlj + "',Memo='" + Memo + "',Tjrxm='"
		+ Tjrxm + "' WHERE WDbh=" + " " + strWDbh + "";
	m_AdoConn.ExecuteSQL(vSQL);
	m_AdoConn.ExitConnect();
}

void CZdxxb::sql_deletelb(int iDWbh, int iLBbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from Zdxxb where DWbh=%i AND LBbh=%i", iDWbh, iLBbh);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}

void CZdxxb::sql_delete(int iWDbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from Zdxxb where WDbh='%i'", iWDbh);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}

void CZdxxb::sql_deletedw(int iDWbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from Zdxxb where DWbh='%i'", iDWbh);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}

void CZdxxb::Load_dep()
{
	//连接数据库
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	//设置SQL语句
	_bstr_t vSQL;
	vSQL = "SELECT*FROM Zdxxb ORDER BY WDbh";
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
	//初始化数组
	a_LBbh.RemoveAll(); //类别编号
	a_WDbh.RemoveAll(); //文档编号
	a_WJlj.RemoveAll(); //文件路径
	a_DWbh.RemoveAll(); //单位编号
	a_WDmc.RemoveAll(); //文档名称
	a_GJz.RemoveAll();  //关键字
	while (m_pRecordset->adoEOF == 0)
	{
		a_WDbh.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("WDbh"));
		a_WJlj.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("WJlj"));
		a_LBbh.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("LBbh"));
		a_DWbh.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("DWbh"));
		a_WDmc.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("WDmc"));
		a_GJz.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("GJz"));
		m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();//断开连接
}

int CZdxxb::sql_selectwdmc(CString cWDmc)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("select WDmc from Zdxxb where WDmc='%s'", cWDmc);
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if (m_pRecordset->adoEOF)
		return -1;
	else
		return 1;
	m_AdoConn.ExitConnect();
}

int CZdxxb::HaveId(int iDWbh, int iLBbh, int iWDbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("SELECT*FROM Zdxxb WHERE DWbh='%i' AND LBbh='%i' AND WDbh='%i'", iDWbh, iLBbh, iWDbh);
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if (m_pRecordset->adoEOF)
		return -1;
	else
		return 1;
	m_AdoConn.ExitConnect();
}