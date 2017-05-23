// FONT.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example17.h"
#include "FONT.h"
#include "afxdialogex.h"


// FONT �Ի���

IMPLEMENT_DYNAMIC(FONT, CDialogEx)

FONT::FONT(CWnd* pParent /*=NULL*/)
	: CDialogEx(FONT::IDD, pParent)
{

}

FONT::~FONT()
{
}

void FONT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FONT, CDialogEx)
	ON_BN_CLICKED(IDC_FONT_BUTTON, &FONT::OnBnClickedFontButton)
END_MESSAGE_MAP()


// FONT ��Ϣ�������


void FONT::OnBnClickedFontButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFontName;
	LOGFONT lf;
	memset(&lf,0,sizeof(LOGFONT));
	_tcscpy_s(lf.lfFaceName,LF_FACESIZE,_T("����"));
	CFontDialog fontDlg(&lf);
	if(IDOK == fontDlg.DoModal())
	{
		if(m_font.m_hObject)
		{
			m_font.DeleteObject();
		}
		m_font.CreateFontIndirect(fontDlg.m_cf.lpLogFont);
		GetDlgItem(IDC_FONT_EDIT)->SetFont(&m_font);
		strFontName = fontDlg.m_cf.lpLogFont->lfFaceName;
		SetDlgItemText(IDC_FONT_EDIT,strFontName);
	}


}
