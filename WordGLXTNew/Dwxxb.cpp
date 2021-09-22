#include "pch.h"
#include "WordGLXTNew.h"
#include "Dwxxb.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDwxxb::CDwxxb()
{

}

CDwxxb::~CDwxxb()
{

}

int CDwxxb::GetDWbh()
{
	return DWbh;
}

void CDwxxb::SetDWbh(int iDWbh)
{
	DWbh = iDWbh;
}

CString CDwxxb::GetDWmc()
{
	return DWmc;
}

void CDwxxb::SetDWmc(CString cDWmc)
{
	DWmc = cDWmc;
}

CString CDwxxb::GetLxr()
{
	return Lxr;
}

void CDwxxb::SetLxr(CString cLxr)
{
	Lxr = cLxr;
}

CString CDwxxb::GetLxdh()
{
	return Lxdh;
}

void CDwxxb::SetLxdh(CString cLxdh)
{
	Lxdh = cLxdh;
}

CString CDwxxb::GetLxdz()
{
	return Lxdz;
}

void CDwxxb::SetLxdz(CString cLxdz)
{
	Lxdz = cLxdz;
}

CString CDwxxb::GetMemo()
{

	return Memo;
}

void CDwxxb::SetMemo(CString cMemo)
{
	Memo = cMemo;
}

void CDwxxb::sql_insert()
{
	ADOConn m_AdoConn;
	CString vSQL;
	vSQL.Format("INSERT INTO Dwxxb(DWbh,DWmc,Lxr,Lxdh,Lxdz,Memo)VALUES(%d,'" + DWmc + "','" + Lxr + "','" + Lxdh + "','" + Lxdz + "','" + Memo + "')", DWbh);
	m_AdoConn.ExecuteSQL(_bstr_t(vSQL));
	m_AdoConn.ExitConnect();
}

void CDwxxb::sql_update(int iDWbh)
{
	ADOConn m_AdoConn;
	CString vSQL;
	vSQL.Format("UPDATE Dwxxb SET DWmc='" + DWmc + "',Lxr='" + Lxr + "',Lxdh='"
		+ Lxdh + "',Lxdz='" + Lxdz + "',Memo='" + Memo + "' WHERE DWbh=%d", iDWbh);
	m_AdoConn.ExecuteSQL(_bstr_t(vSQL));
	m_AdoConn.ExitConnect();
}

void CDwxxb::sql_delete(int iDWbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString sql;
	sql.Format("delete from Dwxxb where DWbh='%i'", iDWbh);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}

void CDwxxb::Load_dep()
{
	//连接数据库
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();

	//设置SQL语句
	_bstr_t vSQL = "SELECT*FROM Dwxxb ORDER BY DWbh";
	_RecordsetPtr m_pRecordset = m_AdoConn.GetRecordSet(vSQL);

	//初始化数组
	a_DWbh.RemoveAll();       //单位编号;
	a_DWmc.RemoveAll();       //单位名称
	while (m_pRecordset->adoEOF == 0)
	{
		a_DWbh.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("DWbh"));
		a_DWmc.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("DWmc"));
		m_pRecordset->MoveNext();//下一个记录集
	}
	m_AdoConn.ExitConnect();    //断开数据库的连接
}

int CDwxxb::HaveId(int iDWbh)   //查找数据库，看有没有指定条件的记录
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	CString strDWbh;
	_RecordsetPtr m_pRecordset;

	strDWbh.Format("SELECT*FROM Dwxxb WHERE DWbh=%d", iDWbh);
	m_pRecordset = m_AdoConn.GetRecordSet(_bstr_t(strDWbh));
	return (m_pRecordset->adoEOF) ? -1 : 1;
	m_AdoConn.ExitConnect();
}