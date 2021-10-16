﻿// Dialogin.cpp: 实现文件
//

#include "pch.h"
#include "WordGLXTNew.h"
#include "Dialogin.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Dialogin 对话框
CUsers user;

IMPLEMENT_DYNAMIC(Dialogin, CDialogEx)
Dialogin::Dialogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGIN, pParent)
{
	m_name = _T("mr");
	m_pwd = _T("123");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONLOGIN);

}

Dialogin::~Dialogin()
{
}

void Dialogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
	DDX_Control(pDX, IDCANCEL, m_Cancel);
	DDX_Control(pDX, IDCLOSE, m_Close);
	DDX_Control(pDX, IDOK, m_OK);
}


BEGIN_MESSAGE_MAP(Dialogin, CDialogEx)
	ON_BN_CLICKED(IDCLOSE,OnClose)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Dialogin 消息处理程序


BOOL Dialogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: Add extra initialization here
	SetIcon(m_hIcon, TRUE);

	m_BitmapOK = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_QR));
	m_BitmapCancel = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_QX));
	m_BitmapCloase = ::LoadBitmap(::AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_Close));
	m_OK.SetBitmap(m_BitmapOK);
	m_Cancel.SetBitmap(m_BitmapCancel);
	m_Close.SetBitmap(m_BitmapCloase);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
//
void Dialogin::OnOK()
{
	// TODO: Add extra validation here
	//将对话框中编辑框的数据读取到成员变量中
	UpdateData(true);
	//检查数据有效性
	if (m_name == "")
	{
		MessageBox("请输入用户名", "文档管理系统");
		return;
	}
	if (m_pwd == "")
	{
		MessageBox("请输入密码");
		return;
	}
	//如果读取数据和用户输入不同，则返回
	if (user.HaveCzy(m_name,m_pwd)!= 1)
	{
		MessageBox("用户名或密码错误!", "文档管理系统");
		return;
	}
	user.SetUsername(m_name);
	
	//判断用户级别
	jb = "1";
	if (user.HaveCzyjb(m_name, m_pwd, jb) == 1)
	{
		user.SetJB(jb);
	}
	else
	{
		user.SetJB("0");
	}
	//读取当前系统时间
	t = CTime::GetCurrentTime();
	//将登录动作记录到日志表
	zhi.SetDLsj(t.Format("%y-%m-%d"));
	zhi.SetName(user.GetUsername());
	zhi.SetDZ("登录");
	zhi.sql_insert();
	CDialogEx::OnOK();
}

void Dialogin::OnClose()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
void Dialogin::OnLButtonDown(UINT nFlags, CPoint point)
{   //该函数实现在客户区能够拖动窗体
	// TODO: Add your message handler code here and/or call default	
	CDialogEx::OnLButtonDown(nFlags, point);
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
}
