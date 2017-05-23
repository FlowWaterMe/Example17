// Color.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example17.h"
#include "Color.h"
#include "afxdialogex.h"


// Color �Ի���

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


// Color ��Ϣ�������


void Color::OnBnClickedColorButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
