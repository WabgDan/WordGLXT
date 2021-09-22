#pragma once
#include "ADOConn.h"
//Category header file 
class CZdmlb
{
private:
	int DWbh;
	int LBbh;
	CString LBmc;

public:
	CZdmlb();
	virtual ~CZdmlb();

	CStringArray a_DWbh;
	CStringArray a_LBbh;
	CStringArray a_LBmc;

	int GetDWbh();
	void SetDwbh(int iDWbh);
	int GetLBbh();
	void SetLBbh(int iLBbh);
	CString GetLBmc();
	void SetLBmc(CString cLBmc);
	void sql_insert();
	void sql_update(int iDWbh, int iLBbh);
	void sql_delete(int iDWbh, int iLBbh);
	void sql_deletedw(int iLBbh);
	void Load_dep();
	int HaveId(int iDWbh, int iLBbh);
};

