#include "Rizhib.h"
#include "Users.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialogin.h : header file
//



class Dialogin : public CDialogEx
{
	DECLARE_DYNAMIC(Dialogin)
public:
	Dialogin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dialogin();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_pwd;
	CButton m_Cancel;
	CButton m_Close;
	CButton m_OK;
	CString jb;
	CRizhib zhi;
	CTime t;
protected:
	CBrush m_bkBrush;
	HICON m_hIcon;
private:
	HBITMAP m_BitmapCancel;
	HBITMAP m_BitmapOK;
	HBITMAP m_BitmapCloase;
	
};
