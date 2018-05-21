#pragma once
#include "GameLogic.h"
class CGameControl
{
public:
	CGameControl(void);
	~CGameControl(void);
	Vertex m_svSelFst;//  ѡ�еĵ�һ����
    Vertex m_svSelSec ;// ѡ�еĵڶ�����
	
	CGameLogic m_GameLogic;
	void StarGame(){
m_GameLogic.InitMap();
	}


	int GetElement(int nRow, int nCol) {
		return m_GameLogic.pGameMap[nRow][nCol];

	};
	bool IsWin(){return m_GameLogic.IsBlank();
	};
void SetFirstPoint(int nRow, int nCol)  ;//���õ�һ����
void SetSecPoint(int nRow, int nCol)  ;//���õڶ�����
bool Link(Vertex avPath[4], int &nVexnum) ;// �����ж�
};

