
// LLKDlg.h : ͷ�ļ�
//

#pragma once


// CLLKDlg �Ի���
class CLLKDlg : public CDialogEx
{
// ����
public:
	CLLKDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LLK_DIALOG };
	void InitBackground(void){
		CBitmap bmpMain;
		bmpMain.LoadBitmapW(IDB_MAIN_BG);
		CClientDC dc(this);
// ��������Ƶ�ڴ���ݵ��ڴ� DC
m_dcMem.CreateCompatibleDC(&dc);
// ��λͼ��Դѡ�� DC
m_dcMem.SelectObject(bmpMain);

	};

	protected:
			CDC m_dcMem;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
