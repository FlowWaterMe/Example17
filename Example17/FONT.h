#pragma once


// FONT 对话框

class FONT : public CDialogEx
{
	DECLARE_DYNAMIC(FONT)
private:
	CFont m_font;
public:
	FONT(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FONT();

// 对话框数据
	enum { IDD = IDD_EXAMPLE18_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFontButton();
};
