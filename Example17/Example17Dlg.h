
// Example17Dlg.h : 头文件
//

#pragma once
#include "FONT.h"
#include "Color.h"
#include "afxwin.h"
// CExample17Dlg 对话框
typedef enum GameType
{
  俄罗斯方块,
  贪吃蛇,
  推箱子
};
class CExample17Dlg : public CDialogEx
{
// 构造
public:
	CExample17Dlg(CWnd* pParent = NULL);	// 标准构造函数
	~CExample17Dlg();
// 对话框数据
	enum { IDD = IDD_EXAMPLE17_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
private:
	FONT mm_font;
	Color mm_color;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	void InitAllcheckRadioStatus();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedSetfontButton();
	afx_msg void OnBnClickedSetcolorButton();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CButton check1;
	CButton check2;
	CButton check3;
	CButton check4;
	CButton check5;
	CButton check6;
	afx_msg void OnBnClickedPortslRadio();
	afx_msg void OnBnClickedForumRadio();
	afx_msg void OnBnClickedBlogRadio();
	afx_msg void OnBnClickedGameButton();
	CComboBox m_typebox;
};
