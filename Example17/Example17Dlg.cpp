
// Example17Dlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CExample17Dlg 对话框


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


// CExample17Dlg 消息处理程序

BOOL CExample17Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CheckDlgButton(IDC_FORUM_RADIO,1);
	OnBnClickedForumRadio();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CExample17Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CExample17Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample17Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] =_T("文本文件(*.lua)|*.lua|所有文件(*.*)|*.*||");
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
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFiler[] = _T("文本文件(*.txt)|*.txt|(Word)文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
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
	// TODO: 在此添加控件通知处理程序代码
		mm_font.DoModal();
}


void CExample17Dlg::OnBnClickedSetcolorButton()
{
	// TODO: 在此添加控件通知处理程序代码
	mm_color.DoModal();
}


void CExample17Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strwebsite;
	if(1 == check1.GetCheck())
	{
		strwebsite +=_T("鸡啄米 ");
	}
	if(1 == check2.GetCheck())
	{
		strwebsite +=_T("新浪 ");
	}
	if(1 == check3.GetCheck())
	{
		strwebsite +=_T("天涯论坛 ");
	}
	if(1 == check4.GetCheck())
	{
		strwebsite +=_T("合勇博客 ");
	}
	if(1 == check5.GetCheck())
	{
		strwebsite +=_T("网易 ");
	}
	if(1 == check6.GetCheck())
	{
		strwebsite +=_T("凤凰卫视 ");
	}
	SetDlgItemText(IDC_WEBSITE_EDIT,strwebsite);
//	CDialogEx::OnOK();

}


void CExample17Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	InitAllcheckRadioStatus();
	check1.EnableWindow(TRUE);
	check4.EnableWindow(TRUE);

}


void CExample17Dlg::OnBnClickedForumRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	InitAllcheckRadioStatus();
	check2.EnableWindow(TRUE);
	check5.EnableWindow(TRUE);
}


void CExample17Dlg::OnBnClickedBlogRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	InitAllcheckRadioStatus();
	check3.EnableWindow(TRUE);
	check6.EnableWindow(TRUE);
}


void CExample17Dlg::OnBnClickedGameButton()
{
	// TODO: 在此添加控件通知处理程序代码
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
	case 俄罗斯方块:
		// MessageBox(_T("请重新输入用户名和密码"),_T("Login"),MB_OKCANCEL|MB_ICONERROR);
		//gamedlg->ShowWindow(SW_SHOW);
		break;
	case 贪吃蛇:
		//gamedlg->ShowWindow(SW_SHOW);
       //  _WinMain(hins,1);
		break;
	case 推箱子:
		//gamedlg->ShowWindow(SW_SHOW);
		break;
	default:
		
		break;
	}
}
/*

*/

