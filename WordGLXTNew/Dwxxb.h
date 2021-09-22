#include "ADOConn.h"
#pragma once

//Company header file
class CDwxxb
{
private:
	int DWbh;
	CString DWmc;
	CString Lxr;
	CString Lxdh;
	CString Lxdz;
	CString Memo;

public:
	CDwxxb();
	virtual ~CDwxxb();

	CStringArray a_DWbh;//用数组来存储文档编号
	CStringArray a_DWmc;//用数组来存储文档名称

	int GetDWbh();
	void SetDWbh(int iDWbh);
	CString GetDWmc();
	void SetDWmc(CString cDWmc);
	CString GetLxr();
	void SetLxr(CString cLxr);
	CString GetLxdh();
	void SetLxdh(CString cLxdh);
	CString GetLxdz();
	void SetLxdz(CString cLxdz);
	CString GetMemo();
	void SetMemo(CString cMemo);
	void sql_insert();
	void sql_update(int iDWbh);
	void sql_delete(int iDWbh);
	//批量读取表中数据
	void Load_dep();
	//判断是否存在相同记录
	int HaveId(int iDWbh);
};

