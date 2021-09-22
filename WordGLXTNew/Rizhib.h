#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//Log header file
class CRizhib
{
private:
	CString Name;
	CString DLsj;
	CString DZ;

public:
	CRizhib();
	virtual ~CRizhib();

	CString GetName();
	void SetName(CString cName);
	CString GetDLsj();
	void SetDLsj(CString cDLsj);
	CString GetDZ();
	void SetDZ(CString cDZ);
	void sql_insert();
};

