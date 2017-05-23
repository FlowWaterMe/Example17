// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example17.h"
#include "Login.h"
#include "afxdialogex.h"
#include "Example17Dlg.h"
// Login �Ի���

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=NULL*/)
	: CDialogEx(Login::IDD, pParent)
	, UserName(_T(""))
	, PassWord(_T(""))
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USER_EDIT, UserName);
	DDX_Text(pDX, IDC_PASSWORD_EDIT, PassWord);
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
	ON_BN_CLICKED(IDOK, &Login::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Login::OnBnClickedCancel)
END_MESSAGE_MAP()


// Login ��Ϣ�������
bool Login::checklogin()
{
	CString usr = "admin";
	CString password = "admin";
	GetDlgItemText(IDC_USER_EDIT,UserName);
	GetDlgItemText(IDC_PASSWORD_EDIT,PassWord);
	if(usr == UserName && password == PassWord)
	{
		return TRUE;
	}
	return FALSE;
}

void Login::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	CExample17Dlg dlg;
	if(checklogin() == TRUE)
	{

	    dlg.DoModal();
	}
	else
	{
		INT_PTR nRes;
		nRes = MessageBox(_T("�����������û���������"),_T("Login"),MB_OKCANCEL|MB_ICONERROR);
		if(IDCANCEL == nRes)
		{
			return;
		}
		Login dlg;
		dlg.DoModal();
		
	}


}


void Login::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();

}
