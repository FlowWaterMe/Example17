
// Example17Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example17.h"
#include "Example17Dlg.h"
#include "afxdialogex.h"
#include "snake.h"
#include "table.h"
#include "snaker.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CExample17Dlg �Ի���


//CExample17Dlg::CExample17Dlg(CWnd* pParent /*=NULL*/)
//	: CDialogEx(CExample17Dlg::IDD, pParent)
//{
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
//	//mm_font = new FONT();
//}
CExample17Dlg::CExample17Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample17Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//mm_font = new FONT();
	//gamedlg = NULL;
}
CExample17Dlg::~CExample17Dlg()
{
	if(NULL != mm_font)
	{
		delete mm_font;
	}
	/*if(NULL != gamedlg)
	{
		delete gamedlg;
	}*/
}
void CExample17Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, check1);
	DDX_Control(pDX, IDC_CHECK2, check2);
	DDX_Control(pDX, IDC_CHECK3, check3);
	DDX_Control(pDX, IDC_CHECK4, check4);
	DDX_Control(pDX, IDC_CHECK5, check5);
	DDX_Control(pDX, IDC_CHECK6, check6);
	DDX_Control(pDX, IDC_GAME_COMBO, m_typebox);
}

BEGIN_MESSAGE_MAP(CExample17Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CExample17Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CExample17Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_SETFONT_BUTTON, &CExample17Dlg::OnBnClickedSetfontButton)
	ON_BN_CLICKED(IDC_SETCOLOR_BUTTON, &CExample17Dlg::OnBnClickedSetcolorButton)
	ON_BN_CLICKED(IDOK, &CExample17Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CExample17Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_PORTSL_RADIO, &CExample17Dlg::OnBnClickedPortslRadio)
	ON_BN_CLICKED(IDC_FORUM_RADIO, &CExample17Dlg::OnBnClickedForumRadio)
	ON_BN_CLICKED(IDC_BLOG_RADIO, &CExample17Dlg::OnBnClickedBlogRadio)
	ON_BN_CLICKED(IDC_GAME_BUTTON, &CExample17Dlg::OnBnClickedGameButton)
END_MESSAGE_MAP()


// CExample17Dlg ��Ϣ�������

BOOL CExample17Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CheckDlgButton(IDC_FORUM_RADIO,1);
	OnBnClickedForumRadio();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CExample17Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExample17Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CExample17Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample17Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] =_T("�ı��ļ�(*.lua)|*.lua|�����ļ�(*.*)|*.*||");
	CFileDialog fileDlg(TRUE,_T("txt"),NULL,0,szFilter,this);
	CString strFilePath;
	if(IDOK == fileDlg.DoModal())
	{
		//strFilePath = fileDlg.GetFileName();
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_OPNE_EDIT,strFilePath);

	}
}


void CExample17Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFiler[] = _T("�ı��ļ�(*.txt)|*.txt|(Word)�ļ�(*.doc)|*.doc|�����ļ�(*.*)|*.*||");
	CFileDialog fileDlg(FALSE,_T("doc"),_T("my"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFiler,this);
	CString strFilePath;
	if(IDOK == fileDlg.DoModal())
	{
		//strFilePath = fileDlg.GetFileName();
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_SAVE_EDIT,strFilePath);
	}
}


void CExample17Dlg::OnBnClickedSetfontButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		mm_font.DoModal();
}


void CExample17Dlg::OnBnClickedSetcolorButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	mm_color.DoModal();
}


void CExample17Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strwebsite;
	if(1 == check1.GetCheck())
	{
		strwebsite +=_T("������ ");
	}
	if(1 == check2.GetCheck())
	{
		strwebsite +=_T("���� ");
	}
	if(1 == check3.GetCheck())
	{
		strwebsite +=_T("������̳ ");
	}
	if(1 == check4.GetCheck())
	{
		strwebsite +=_T("���²��� ");
	}
	if(1 == check5.GetCheck())
	{
		strwebsite +=_T("���� ");
	}
	if(1 == check6.GetCheck())
	{
		strwebsite +=_T("������� ");
	}
	SetDlgItemText(IDC_WEBSITE_EDIT,strwebsite);
//	CDialogEx::OnOK();

}


void CExample17Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

void CExample17Dlg::InitAllcheckRadioStatus()
{
	check1.EnableWindow(FALSE);
	check2.EnableWindow(FALSE);
	check3.EnableWindow(FALSE);
	check4.EnableWindow(FALSE);
	check5.EnableWindow(FALSE);
	check6.EnableWindow(FALSE);

	//
	check1.SetCheck(0);
	check2.SetCheck(0);
	check3.SetCheck(0);
	check4.SetCheck(0);
	check5.SetCheck(0);
	check6.SetCheck(0);

}
void CExample17Dlg::OnBnClickedPortslRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	InitAllcheckRadioStatus();
	check1.EnableWindow(TRUE);
	check4.EnableWindow(TRUE);

}


void CExample17Dlg::OnBnClickedForumRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	InitAllcheckRadioStatus();
	check2.EnableWindow(TRUE);
	check5.EnableWindow(TRUE);
}


void CExample17Dlg::OnBnClickedBlogRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	InitAllcheckRadioStatus();
	check3.EnableWindow(TRUE);
	check6.EnableWindow(TRUE);
}


void CExample17Dlg::OnBnClickedGameButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//int i = GetDlgItemInt(IDC_GAME_COMBO,NULL,TRUE);
	int i = m_typebox.GetCurSel();
	CWnd * pwnd = FindWindow(NULL,"IDD_GAME_DIALOG");
	HWND hwnd = pwnd->GetSafeHwnd();
	HINSTANCE hins = (HINSTANCE)::GetWindowLong(hwnd,GWL_HINSTANCE);
	GameType t = GameType(i);
	//if(NULL == gamedlg)
	//{
	//	gamedlg = new GAMEDLG();
	//	gamedlg->Create(IDD_GAME_DIALOG,this);
	//}
	switch (t)
	{
	case ����˹����:
		// MessageBox(_T("�����������û���������"),_T("Login"),MB_OKCANCEL|MB_ICONERROR);
		//gamedlg->ShowWindow(SW_SHOW);
		break;
	case ̰����:
		//gamedlg->ShowWindow(SW_SHOW);
       //  _WinMain(hins,1);
		break;
	case ������:
		//gamedlg->ShowWindow(SW_SHOW);
		break;
	default:
		
		break;
	}
}
/*

*/

