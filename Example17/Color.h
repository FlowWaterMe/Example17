#pragma once


// Color 对话框

class Color : public CDialogEx
{
	DECLARE_DYNAMIC(Color)

public:
	Color(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Color();

// 对话框数据
	enum { IDD = IDD_EXAMPLE19_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedColorButton();
};
