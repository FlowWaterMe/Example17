#pragma once


// Color �Ի���

class Color : public CDialogEx
{
	DECLARE_DYNAMIC(Color)

public:
	Color(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Color();

// �Ի�������
	enum { IDD = IDD_EXAMPLE19_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedColorButton();
};
