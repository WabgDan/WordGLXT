#include "Rizhib.h"
#include "Users.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialogin.h : header file
//
extern CUsers user;
/////////////////////////////////////////////////////////////////////////////
// CDialogin dialog

// Dialogin 对话框

class CDialogin : public CDialogEx
{
	DECLARE_DYNAMIC(Dialogin)

	
	

public:
	CString jb;
	CRizhib zhi;
	CTime t;
	CDialogin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogin();

// 对话框数据
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGIN };
//#endif

protected:
	CBrush m_bkBrush;
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

	
private:
	HBITMAP m_BitmapClose;
	HBITMAP m_BitmapCancel;
	HBITMAP m_BitmapOk;
public:
	CString m_name;
	CString m_pwd;
	CButton m_Cancel;
	CButton m_Close;
	CButton m_OK;
	
	HICON m_hicon;
	CBrush m_bkBrush;
};
