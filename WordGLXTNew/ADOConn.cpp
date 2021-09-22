#include "pch.h"
#include "WordGLXTNew.h"
#include "ADOConn.h"
// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

//#include "stdafx.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOConn::ADOConn()
{

}

ADOConn::~ADOConn()
{

}

void ADOConn::OnInitADOConn()
{
    //初始化OLE/COM库环境
    ::CoInitialize(NULL);
    try {
        //创建connection对象
        //下面语句等效于：m_pConnection.CreateInstance("ADODB.Connection");
        m_pConnection.CreateInstance(__uuidof(Connection));

        // 获得配置文件的路径
        TCHAR szFilename[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, szFilename, _countof(szFilename));
        PathRemoveFileSpec(szFilename);
        // 读取配置文件
        const PCTSTR szAppName = _T("数据配置");
        CString strFilename = szFilename;
        strFilename += _T("\\Database.ini");

        CString strInitialCatalog, strDataSource, strUserID, strPassword;
        GetPrivateProfileString(szAppName, _T("InitialCatalog"), _T("WenDGL1"), strInitialCatalog.GetBuffer(1024), 1024, strFilename);
        GetPrivateProfileString(szAppName, _T("DataSource"), _T("127.0.0.1"), strDataSource.GetBuffer(1024), 1024, strFilename);
        GetPrivateProfileString(szAppName, _T("UserID"), _T("sa"), strUserID.GetBuffer(1024), 1024, strFilename);
        GetPrivateProfileString(szAppName, _T("Password"), _T("root"), strPassword.GetBuffer(1024), 1024, strFilename);
        strInitialCatalog.ReleaseBuffer();
        strDataSource.ReleaseBuffer();
        strUserID.ReleaseBuffer();
        strPassword.ReleaseBuffer();

        //设置连接字符串
        CString str;
        str.Format(_T("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=True;Initial Catalog=%s;Data Source=%s;User ID=%s;Password=%s;")
            , strInitialCatalog.GetString()
            , strDataSource.GetString()
            , strUserID.GetString()
            , strPassword.GetString()
        );
        /*str.Format(_T("driver={SQL Server};Server=%s;Database=%s;UID=%s;PWD=%s;")
                   , strDataSource.GetString()
                   , strInitialCatalog.GetString()
                   , strUserID.GetString()
                   , strPassword.GetString()
                  );
                  */
        _bstr_t strConnect = str;

        //SERVER和UID,PWD的设置根据实际情况来设置
        m_pConnection->Open(strConnect, strUserID.GetString(), strPassword.GetString(), adModeUnknown);
    }
    //捕捉异常
    catch (_com_error e) {
        //显示错误信息
        AfxMessageBox(_T("连接数据库失败!"));
        AfxMessageBox(e.Description());
    }
    catch (...) {
        AfxMessageBox(_T("连接数据库失败!"));
    }
}

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
    try {
        //连接数据库，如果connection对象为空，则重新连接数据库
        if (m_pConnection == NULL) {
            OnInitADOConn();
        }
        //创建记录集对象
        //m_pRecordset.CreateInstance(__uuidof(Recordset));
        m_pRecordset.CreateInstance("ADODB.Recordset");
        //取得表中的记录
        m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
    }
    catch (_com_error e) {
        e.Description();
    }
    //返回记录集
    return m_pRecordset;
}

BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
    _variant_t RecordsAffected;
    try {
        //是否已连接数据库
        if (m_pConnection == NULL) {
            OnInitADOConn();
        }
        /***********************************************************************
        *  connection对象的Execute方法说明如下：                               *
        *  Execute(_bstr_t CommandText,VARIANT * RecordsAffected,long Options) *
        *       其中CommandText是命令字符串,通常是SQL命令                      *
        *       参数RecordsAffected是操作完成后所影响的行数                    *
        *       参数Options表示CommandText的类型。                             *
        *          adCmdText-文本命令                                          *
        *          adCmdTable-表名                                             *
        *          adCmdProc-存储过程                                          *
        *          adCmdUnknown-未知                                           *
        ***********************************************************************/
        m_pConnection->Execute(bstrSQL, NULL, adCmdText); //执行SQL语句
        return true;
    }
    catch (_com_error e) {
        e.Description();
        return false;
    }
}

void ADOConn::ExitConnect()
{
    //关闭记录集和连接
    if (m_pRecordset != NULL) {
        m_pRecordset->Close();
    }
    m_pConnection->Close();
    //释放环境
    ::CoUninitialize();
}