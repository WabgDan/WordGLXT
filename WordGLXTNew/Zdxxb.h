#include "ADOConn.h"
#pragma once

//Document header file
class CZdxxb
{
private:
	int LBbh;
	int WDbh;
	int DWbh;
	CString GJz;
	CString WDmc;
	CString WJlj;
	CString Memo;
	CString Tjrxm;

public:
	CZdxxb();
	virtual ~CZdxxb();

	CStringArray a_WDbh;
	CStringArray a_LBbh;
	CStringArray a_WJlj;
	CStringArray a_DWbh;
	CStringArray a_WDmc;
	CStringArray a_GJz;

	int GetDWbh();
	void SetDWbh(int iDWbh);
	int GetLBbh();
	void SetLBbh(int iLBbh);
	int GetWDbh();
	void SetWDbh(int iWDbh);
	CString GetGJz();
	void SetGJz(CString cGJz);
	CString GetWDmc();
	void SetWDmc(CString cWDmc);
	CString GetWJlj();
	void SetWJlj(CString cWJlj);
	CString GetMemo();
	void SetMemo(CString cMemo);
	CString GetTjrxm();
	void SetTjrxm(CString cTjrxm);
	void sql_insert();
	void sql_update(int iWDbh);
	void sql_deletelb(int iDWbh, int iLBbh);
	void sql_delete(int iWDbh);
	void sql_deletedw(int iDWbh);
	int sql_selectwdmc(CString cWDmc);
	void Load_dep();
	int HaveId(int iDWbh, int iLBbh, int iWDbh);
};

