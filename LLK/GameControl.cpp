#include "StdAfx.h"
#include "GameControl.h"
#include "GameLogic.h"


CGameControl::CGameControl(void)
{
}


CGameControl::~CGameControl(void)
{
}

void CGameControl::SetFirstPoint(int nRow, int nCol)
{
	m_svSelFst.col=nCol;
	m_svSelFst.row=nRow;
	m_svSelFst.picnum=m_GameLogic.pGameMap[nRow][nCol];
}

void CGameControl::SetSecPoint(int nRow, int nCol) 
{
	m_svSelSec.col=nCol;
	m_svSelSec.row=nRow;
	m_svSelSec.picnum=m_GameLogic.pGameMap[nRow][nCol];
}


bool CGameControl::Link(Vertex avPath[4], int &nVexnum)
{
// 判断是否同一张图片
if(m_svSelFst.row == m_svSelSec.row && m_svSelFst.col == m_svSelSec.col)
{
return false;
}
// 判断图片是否相同
if(m_GameLogic.pGameMap[m_svSelFst.row][m_svSelFst.col]!=m_GameLogic.pGameMap[m_svSelSec.row][m_svSelSec.col])
{
return false;
}


// 判断
if(m_GameLogic.IsLink(m_GameLogic.pGameMap, m_svSelFst, m_svSelSec))
{
// 消子
m_GameLogic.Clear(m_GameLogic.pGameMap, m_svSelFst, m_svSelSec);
// 返回路径顶点
nVexnum = m_GameLogic.GetVexPath(avPath);
return true;
}
return false;
}


