#pragma once
#include "GameLogic.h"
class CGameControl
{
public:
	CGameControl(void);
	~CGameControl(void);
	Vertex m_svSelFst;//  选中的第一个点
    Vertex m_svSelSec ;// 选中的第二个点
	
	CGameLogic m_GameLogic;
	void StarGame(){
m_GameLogic.InitMap();
	}


	int GetElement(int nRow, int nCol) {
		return m_GameLogic.pGameMap[nRow][nCol];

	};
	bool IsWin(){return m_GameLogic.IsBlank();
	};
void SetFirstPoint(int nRow, int nCol)  ;//设置第一个点
void SetSecPoint(int nRow, int nCol)  ;//设置第二个点
bool Link(Vertex avPath[4], int &nVexnum) ;// 消子判断
};

