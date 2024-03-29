// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__B8D01B34_20DA_49AE_9FA1_664D67A28ABD__INCLUDED_)
#define AFX_ADOCONN_H__B8D01B34_20DA_49AE_9FA1_664D67A28ABD__INCLUDED_
#import "c:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")rename("BOF","adoBOF")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn
{
public:
	//添加一个指向Connection对象的指针
	_ConnectionPtr m_pConnection;
	//添加一个指向Recordset对象的指针
	_RecordsetPtr m_pRecordset;

public:
	ADOConn();
	virtual ~ADOConn();

	//初始化--连接数据库
	void OnInitADOConn();
	//执行查询
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	//执行SQL语句
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	//断开数据库连接
	void ExitConnect();
};

#endif // !defined(AFX_ADOCONN_H__B8D01B34_20DA_49AE_9FA1_664D67A28ABD__INCLUDED_)
