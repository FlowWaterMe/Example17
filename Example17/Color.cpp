// Color.cpp : 实现文件
//

#include "stdafx.h"
#include "Example17.h"
#include "Color.h"
#include "afxdialogex.h"


// Color 对话框

IMPLEMENT_DYNAMIC(Color, CDialogEx)

Color::Color(CWnd* pParent /*=NULL*/)
	: CDialogEx(Color::IDD, pParent)
{

}

Color::~Color()
{
}

void Color::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Color, CDialogEx)
	ON_BN_CLICKED(IDC_COLOR_BUTTON, &Color::OnBnClickedColorButton)
END_MESSAGE_MAP()


// Color 消息处理程序


void Color::OnBnClickedColorButton()
{
	// TODO: 在此添加控件通知处理程序代码
	COLORREF color = RGB(255,0,0);
	CColorDialog colorDlg(color);
	if(IDOK == colorDlg.DoModal())
	{
		color = colorDlg.GetColor();
		SetDlgItemInt(IDC_COLOR_EDIT,color);
		SetDlgItemInt(IDC_RED_EDIT,GetRValue(color));
		SetDlgItemInt(IDC_GREEN_EDIT,GetGValue(color));
		SetDlgItemInt(IDC_BLUE_EDIT,GetBValue(color));
	}
}
