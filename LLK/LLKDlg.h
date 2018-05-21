
// LLKDlg.h : 头文件
//

#pragma once


// CLLKDlg 对话框
class CLLKDlg : public CDialogEx
{
// 构造
public:
	CLLKDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LLK_DIALOG };
	void InitBackground(void){
		CBitmap bmpMain;
		bmpMain.LoadBitmapW(IDB_MAIN_BG);
		CClientDC dc(this);
// 创建与视频内存兼容的内存 DC
m_dcMem.CreateCompatibleDC(&dc);
// 将位图资源选入 DC
m_dcMem.SelectObject(bmpMain);

	};

	protected:
			CDC m_dcMem;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg void OnBnClickedBtnLevel();
	afx_msg void OnBnClickedBtnBasic();
	afx_msg void OnBnClickedBtnRelax();
	afx_msg void OnBnClickedBtnRank();
	afx_msg void OnBnClickedBtnSetting();
	afx_msg void OnBnClickedBtnHelp();
};
