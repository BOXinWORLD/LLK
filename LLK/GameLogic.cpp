#include "StdAfx.h"
#include "GameLogic.h"


CGameLogic::CGameLogic(void)
{
}


CGameLogic::~CGameLogic(void)
{
}

bool CGameLogic::IsBlank()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			if(pGameMap[i][j] != BLANK) 
				return false;
		}
	}

	return true;
}

bool CGameLogic::IsLink(int** pGameMap, Vertex v1, Vertex v2)
{
PushVertex(v1);
// X ֱ����ʽ
if(v1.row == v2.row)
{if(LinkInRow(pGameMap,v1, v2))
	{PushVertex(v2);
m_nVexNum=2;
return true;}

}
//Y ֱ����ʽ
if(v1.col == v2.col)
{if(LinkInCol(pGameMap,v1, v2))
{PushVertex(v2);
m_nVexNum=2;
return true;
}

}

if(OneCornerLink(pGameMap,v1, v2))
{m_nVexNum=3;return true;
}
if(TwoCornerLink(pGameMap,v1, v2))
{m_nVexNum=4;return true;
}

return false;



}

bool CGameLogic::LinkInRow(int** pGameMap, Vertex v1, Vertex v2)
{
int nCol1 = v1.col;
int nCol2 = v2.col;
int nRow = v1.row;
//��֤ nCol1 ��ֵС�� nCol2
if(nCol1 > nCol2)
{
//���ݽ���
int nTemp = nCol1;
nCol1 = nCol2;
nCol2 = nTemp;
}
//ֱͨ
for(int i = nCol1 + 1; i <= nCol2; i++)
{
if(i == nCol2) return true;
if(pGameMap[nRow][i] != BLANK) break;
}
return false;
}

bool CGameLogic::LinkInCol(int** pGameMap, Vertex v1, Vertex v2)
{
int nRow1 = v1.row;
int nRow2 = v2.row;
int nCol = v1.col;
if(nRow1 > nRow2)
{
int nTemp = nRow1;
nRow1 = nRow2;
nRow2 = nTemp;
}
//ֱͨ
for(int i = nRow1+1; i <= nRow2; i++)
{
if(i == nRow2)  return true;
if(pGameMap[i][nCol] != BLANK) break;
}
return false;
}

bool CGameLogic::OneCornerLink(int** pGameMap, Vertex v1, Vertex v2)
{
// ֱ���ܹ����ӣ���ô����һ��������������к����ཻ�ĵ㣬ֻ����������Ϊ�գ����п���ʵ�ֶ���ֱ������
if (pGameMap[v1.row][v2.col] == BLANK)
{
if(LineY(pGameMap, v1.row, v2.row, v2.col) && LineX(pGameMap, v1.row, v1.col,
v2.col))
{
Vertex v = {v1.row, v2.col, BLANK};
PushVertex(v);
return true;
}
}
if(pGameMap[v2.row][v1.col] == BLANK)
{
if(LineY(pGameMap, v1.row, v2.row, v1.col) && LineX(pGameMap, v2.row, v1.col,
v2.col))
{
Vertex v = {v2.row, v1.col, BLANK};
PushVertex(v);
return true;
}
} 
return false;
}


bool CGameLogic::TwoCornerLink(int** pGameMap, Vertex v1, Vertex v2)
{
//
for(int nCol = 0; nCol < 16; nCol++)
{
// �ҵ�һ���� Y ��ƽ�е���ͨ�߶�
if(pGameMap[v1.row][nCol] == BLANK && pGameMap[v2.row][nCol] == BLANK)
{
if(LineY(pGameMap, v1.row, v2.row, nCol))
{
if(LineX(pGameMap, v1.row, v1.col, nCol) && LineX(pGameMap, v2.row,
v2.col, nCol))
{
// ����ڵ�
Vertex vx1 = {v1.row, nCol, BLANK};
Vertex vx2 = {v2.row, nCol, BLANK};
PushVertex(vx1);
PushVertex(vx2);
return true;
}
}
}
}
for(int nRow = 0; nRow < 10; nRow++)
{
// �ҵ�һ���� X ��ƽ�е���ͨ�߶�
if(pGameMap[nRow][v1.col] == BLANK && pGameMap[nRow][v2.col] == BLANK)
{
if(LineX(pGameMap, nRow, v1.col, v2.col))
{
if(LineY(pGameMap, nRow, v1.row, v1.col) && LineY(pGameMap, nRow,
v2.row, v2.col))
{
// ����ڵ�
Vertex vx1 = {nRow, v1.col, BLANK};
Vertex vx2 = {nRow, v2.col, BLANK};
PushVertex(vx1);
PushVertex(vx2);
return true;
}
}
}
}
return false;
}


int CGameLogic::GetVexPath(Vertex avPath[4])
{
for(int i = 0; i < m_nVexNum; i++)
{
avPath[i] = m_avPath[i];
}
return m_nVexNum;
}

void CGameLogic::PushVertex(Vertex v)
{
	for(int i=0;i<4;i++)
	{
		if(m_avPath[i].picnum==0 && m_avPath[i].col==0 && m_avPath[i].row==0)
	{m_avPath[i]=v;break;}
		
	}
}
void CGameLogic::ClearStack() 
{
	
	for(int i=0;i<4;i++)
	{
		m_avPath[i].col=0;
		m_avPath[i].picnum=0;
		m_avPath[i].row=0;
	}
}
void CGameLogic::Clear(int** pGameMap, Vertex v1, Vertex v2)
{
	pGameMap[v1.row][v1.col]=BLANK;
	pGameMap[v2.row][v2.col]=BLANK;
}


bool CGameLogic::LineY(int** pGameMap, int nRow1, int nRow2, int nCol) 
{
	if(nRow1 > nRow2)
{
//���ݽ���
int nTemp = nRow1;
nRow1 = nRow2;
nRow2 = nTemp;
}
	for(int i = nRow1+1; i <= nRow2; i++)
{
if(i == nRow2)  return true;
if(pGameMap[i][nCol] != BLANK) break;
}
return false;

}

bool CGameLogic::LineX(int** pGameMap, int nRow, int nCol1, int nCol2)
{
	if(nCol1 > nCol2)
{
//���ݽ���
int nTemp = nCol1;
nCol1 = nCol2;
nCol2 = nTemp;
}
//ֱͨ
for(int i = nCol1 + 1; i <= nCol2; i++)
{
if(i == nCol2) return true;
if(pGameMap[nRow][i] != BLANK) break;
}
return false;
}
