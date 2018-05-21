#pragma once
#include "GameControl.h"


// CGameDlg 对话框

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)

public:
	CGameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGameDlg();
	CGameControl m_GameC;
	CRect m_rtGameRect;
	bool m_bFirstPoint;
	bool m_bPlaying;
	bool init;
	

	void InitBackground(){
		CBitmap bmpM;
		bmpM.LoadBitmapW(IDB_1_BG);
		CClientDC d(this);
// 创建与视频内存兼容的内存 DC
m_dcMem.CreateCompatibleDC(&d);
// 将位图资源选入 DC
m_dcMem.SelectObject(bmpM);


	};
void UpdateMap()
{
// 计算图片的顶点坐标与图片大小

int nLeft=20;
int nTop=60;
int nElemW=40;
int nElemH=40;
//获取行数和列数
int nRows= 10;
int nCols= 16;
for(int i = 0; i < nRows; i++)
{
for(int j = 0; j < nCols; j++)
{
// 得到图片编号的值
int nElemVal = m_GameC.GetElement(i, j);
// 将背景与掩码相或，边保留，图像区域为 1
m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH , nElemW, nElemH,
&m_dcMask, 0, nElemVal * nElemH, SRCPAINT);
// 与元素图片相与，边保留，图像区域为元素图片
m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH , nElemW, nElemH,
&m_dcElement, 0, nElemVal * nElemH, SRCAND);
}
}
}
	

// 对话框数据
	enum { IDD = IDD_GAME_DIALOG };

protected:
	void CGameDlg::InitElement(void)
{
// 获得当前对话框的视频内存
CClientDC dc(this);
// 加载 BMP 图片资源
HANDLE  hBmp  =  ::LoadImageW(NULL,  _T("theme\\picture\\fruit_element.bmp"),
IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
// 创建与视频内存兼容的内存 DC
m_dcElement.CreateCompatibleDC(&dc);
// 将位图资源选入 DC
m_dcElement.SelectObject(hBmp);
// 加载掩码 BMP 图片资源
HANDLE  hMask  =  ::LoadImageW(NULL,  _T("theme\\picture\\fruit_mask.bmp"),
IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
// 创建与视频内存兼容的内存 DC
m_dcMask.CreateCompatibleDC(&dc);
// 将位图资源选入 DC
m_dcMask.SelectObject(hMask);
	};


	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CDC m_dcMem;
	CDC m_dcElement;
	CDC m_dcMask;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void DrawTipFrame(int r, int c);
	void DrawTipLine(Vertex asvPath[4], int nVexnum);
	afx_msg void OnClickedButton8();
};
