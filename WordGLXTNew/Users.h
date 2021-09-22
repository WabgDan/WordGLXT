#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUsers
{
private:
	CString Username;
	CString Pwd;
	CString JB;

public:
	CUsers();
	virtual ~CUsers();

	CString GetUsername();
	void SetUsername(CString cUsername);
	CString GetPwd();
	void SetPwd(CString cPwd);
	CString GetJB();
	void SetJB(CString cJB);
	void sql_insert();
	void sql_update(CString cUsername);
	void sql_delete(CString cUsername);
	void sql_updatepwd(CString cUsername);

	int Havename(CString cUsername);
	int HaveCzy(CString cUsername, CString cPwd);
	int HaveCzyjb(CString cUsername, CString cPwd, CString cJB);
};

