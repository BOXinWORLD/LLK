// GameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LLK.h"
#include "GameDlg.h"
#include "GameControl.h"
#include "afxdialogex.h"


// CGameDlg �Ի���

IMPLEMENT_DYNAMIC(CGameDlg, CDialogEx)

CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGameDlg::IDD, pParent)
{m_rtGameRect=CRect(15,55,665,465);
m_bPlaying= false;

}

CGameDlg::~CGameDlg()
{
}

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON7, &CGameDlg::OnBnClickedButton7)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON8, &CGameDlg::OnClickedButton8)
END_MESSAGE_MAP()


// CGameDlg ��Ϣ�������




void CGameDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(init)InitElement();
	init=false;
	m_GameC.StarGame();
	UpdateMap();
	InvalidateRect(m_rtGameRect, true );
	m_bPlaying=true;
	CButton *pBtn= (CButton *)GetDlgItem(IDC_BUTTON7);
	pBtn->EnableWindow(FALSE);
}


void CGameDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	dc.BitBlt(0, 0, 800, 600, &m_dcMem, 0, 0, SRCCOPY);


}


BOOL CGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CGameDlg::InitBackground();
	SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CGameDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// �ж������������

if(point.y < 60 || point.y > 460|| point.x < 20 || point.x > 680)
{	return CDialogEx::OnLButtonUp(nFlags, point);}

int r=(point.y-60)/40;
int c=(point.x-20)/40;

if(m_GameC.GetElement(r, c)==BLANK)
{return CDialogEx::OnLButtonUp(nFlags, point);}

DrawTipFrame(r,c);

if(m_bFirstPoint) // ��һ����
{
	m_GameC.SetFirstPoint(r,c);
	m_GameC.m_GameLogic.ClearStack();

}
else // �ڶ�����
{
	m_GameC.SetSecPoint(r,c);

// �����ж�
	bool bSuc = m_GameC.Link(m_GameC.m_GameLogic.m_avPath, m_GameC.m_GameLogic.m_nVexNum);
if(bSuc)
{
	Vertex v = {r, c, BLANK};
	m_GameC.m_GameLogic.PushVertex(v);
// ����ʾ��
DrawTipLine(m_GameC.m_GameLogic.m_avPath, m_GameC.m_GameLogic.m_nVexNum);
Sleep(350);
m_GameC.m_GameLogic.ClearStack();
// ���µ�ͼ
UpdateMap();
}
InvalidateRect(m_rtGameRect, true );
if(bSuc&&m_GameC.m_GameLogic.IsBlank())
{
 AfxMessageBox(_T("��ʤ��"));
 m_bPlaying= false;
 CButton *pBtn= (CButton *)GetDlgItem(IDC_BUTTON7);
	pBtn->EnableWindow(TRUE);

}

} 
m_bFirstPoint = !m_bFirstPoint;

}


void CGameDlg::DrawTipFrame(int r,int c)
{
	CPen NewPen(PS_SOLID, 4, RGB(233,43,43));  
	CClientDC dc(this);
dc.SelectObject(&NewPen);  
 dc.SelectStockObject(NULL_BRUSH);   
dc.Rectangle(40*c+20, 40*r+60,40*c+60, 40*r+100);  
  
NewPen.DeleteObject();
}

void CGameDlg::DrawTipLine(Vertex asvPath[4], int nVexnum)
{
CClientDC dc(this);
CPen penLine(PS_SOLID, 2, RGB(0, 255, 0));
CPen* pOldPen = dc.SelectObject(&penLine);
dc.MoveTo(20 + asvPath[0].col * 40 + 40 / 2,
60 + asvPath[0].row * 40 + 40 / 2);
for(int i = 1; i < nVexnum; i++)
{
dc.LineTo(20+ asvPath[i].col * 40 + 40 / 2,
60 + asvPath[i].row * 40 + 40 / 2);
}
dc.SelectObject(pOldPen);
}




void CGameDlg::OnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_GameC.StarGame();
	UpdateMap();
	InvalidateRect(m_rtGameRect, true );
}
