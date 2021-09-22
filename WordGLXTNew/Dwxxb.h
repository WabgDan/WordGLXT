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

	CStringArray a_DWbh;//���������洢�ĵ����
	CStringArray a_DWmc;//���������洢�ĵ�����

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
	//������ȡ��������
	void Load_dep();
	//�ж��Ƿ������ͬ��¼
	int HaveId(int iDWbh);
};

