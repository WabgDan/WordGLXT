#include "Zdmlb.h"
#include "Dwxxb.h"
#include "Zdxxb.h"
#include "Rizhib.h"
#include "msword9.h"
#include "ADOConn.h"
#include "Users.h"
#include "Dwdandlg.h"
// WordGLXTNewDlg.h: 头文件
//

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern CWordGLXTNewApp theApp;
extern CUsers user;

// CWordGLXTNewDlg 对话框
class CWordGLXTNewDlg : public CDialogEx
{

// 构造
public:
	CWordGLXTNewDlg(CWnd* pParent = nullptr);	// 标准构造函数
public:
	CRichEditCtrl m_richedit;
	CTreeCtrl m_tree;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WORDGLXTNEW_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenudwdan();
	afx_msg void OnMenuwdlb();
	afx_msg void OnMenuliulwd();
	afx_msg void OnMenuyhgl();
	afx_msg void OnMenumodpwd();
	afx_msg void OnMenuaddwd();
	afx_msg void OnMenudelwd();
	afx_msg void OnMenumodwd();
	afx_msg void OnMenurzgl();
	afx_msg void OnMENULookFileAttri();
	afx_msg void OnExit();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDwDA();
	afx_msg void OnButtonWDLB();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDel();
	afx_msg void OnButtonScan();
	afx_msg void OnButtonAttri();
	afx_msg void OnButtonUserManage();
	afx_msg void OnButtonmimaModify();
	afx_msg void OnButtonLogManage();
	afx_msg void OnButtonExit();
	afx_msg void OnMenuDBBackUp();
	afx_msg void OnMenuDBRestore();
	afx_msg void OnButtonBackUp();
	afx_msg void OnButtonRestore();
	afx_msg void OnSystemExit();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	BOOL OnToolTipNotify(UINT id, NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()

private:
	POINT Old;
	HTREEITEM arrays[10], brrays[20], hitem[100];
	HTREEITEM m_root, temp;
	CDwxxb dwb;
	CZdmlb mlb;
	CZdxxb xxb;
	CRizhib zhi;
	CImageList m_treeImageList;
	CTime t;
	CStatusBarCtrl m_StatusBar;   //statusBar object
	CString strWordpath;  //Record word path
	CString strText;     //staging the contents of a word document
	void AddtoTree(HTREEITEM m_node);

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
