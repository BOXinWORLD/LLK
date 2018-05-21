#pragma once
#include "GameControl.h"


// CGameDlg �Ի���

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)

public:
	CGameDlg(CWnd* pParent = NULL);   // ��׼���캯��
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
// ��������Ƶ�ڴ���ݵ��ڴ� DC
m_dcMem.CreateCompatibleDC(&d);
// ��λͼ��Դѡ�� DC
m_dcMem.SelectObject(bmpM);


	};
void UpdateMap()
{
// ����ͼƬ�Ķ���������ͼƬ��С

int nLeft=20;
int nTop=60;
int nElemW=40;
int nElemH=40;
//��ȡ����������
int nRows= 10;
int nCols= 16;
for(int i = 0; i < nRows; i++)
{
for(int j = 0; j < nCols; j++)
{
// �õ�ͼƬ��ŵ�ֵ
int nElemVal = m_GameC.GetElement(i, j);
// ��������������򣬱߱�����ͼ������Ϊ 1
m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH , nElemW, nElemH,
&m_dcMask, 0, nElemVal * nElemH, SRCPAINT);
// ��Ԫ��ͼƬ���룬�߱�����ͼ������ΪԪ��ͼƬ
m_dcMem.BitBlt(nLeft + j * nElemW, nTop + i * nElemH , nElemW, nElemH,
&m_dcElement, 0, nElemVal * nElemH, SRCAND);
}
}
}
	

// �Ի�������
	enum { IDD = IDD_GAME_DIALOG };

protected:
	void CGameDlg::InitElement(void)
{
// ��õ�ǰ�Ի������Ƶ�ڴ�
CClientDC dc(this);
// ���� BMP ͼƬ��Դ
HANDLE  hBmp  =  ::LoadImageW(NULL,  _T("theme\\picture\\fruit_element.bmp"),
IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
// ��������Ƶ�ڴ���ݵ��ڴ� DC
m_dcElement.CreateCompatibleDC(&dc);
// ��λͼ��Դѡ�� DC
m_dcElement.SelectObject(hBmp);
// �������� BMP ͼƬ��Դ
HANDLE  hMask  =  ::LoadImageW(NULL,  _T("theme\\picture\\fruit_mask.bmp"),
IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
// ��������Ƶ�ڴ���ݵ��ڴ� DC
m_dcMask.CreateCompatibleDC(&dc);
// ��λͼ��Դѡ�� DC
m_dcMask.SelectObject(hMask);
	};


	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
