#pragma once


// FONT �Ի���

class FONT : public CDialogEx
{
	DECLARE_DYNAMIC(FONT)
private:
	CFont m_font;
public:
	FONT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FONT();

// �Ի�������
	enum { IDD = IDD_EXAMPLE18_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFontButton();
};
