#pragma once
#define BLANK 20
struct Vertex
{
    int row;
	int col;
	int picnum;
}; 

class CGameLogic
{
public:
	CGameLogic(void);
	~CGameLogic(void);
	int** pGameMap ;
		Vertex m_avPath[4] ;
	int m_nVexNum ;
	void InitMap()
{
// 获取地图大小和花色
//int nRows = CGameControl::s_nRows;
//int nCols = CGameControl::s_nCols;
//int nPicNum = CGameControl::s_nPicNum;

int nRows = 10;
int nCols = 16;
int nPicNum = 20;
// 开辟内存区域
pGameMap = new int*[nRows];
if(NULL == pGameMap)
{
//throw new CGameException(_T("内存操作异常！\n"));
}
else
{
for (int i = 0; i < nRows; i++)
{
pGameMap[i] = new int[nCols];
if(NULL == pGameMap)
{
//throw new CGameException(_T("内存操作异常！\n"));
}
memset(pGameMap[i], NULL, sizeof(int) * nCols);
}
}


// 多少花色
if ((nRows * nCols) % (nPicNum * 2) != 0)
{
//ReleaseMap(pGameMap);
//throw new CGameException(_T("游戏花色与游戏地图大小不匹配！"));
}
int nRepeatNum = nRows * nCols / nPicNum;
int nCount = 0;
for(int i = 0; i < nPicNum; i++)
{
// 重复数
for(int j = 0; j < nRepeatNum; j++)
{
pGameMap[nCount / nCols][nCount % nCols] = i;
nCount++;
}
}

// 设置种子
srand((int)time(NULL));
// 随机任意交换两个数字
int nVertexNum = nRows * nCols;
for(int i = 0; i < nVertexNum; i++)
{
// 随机得到两个坐标
int nIndex1 = rand() % nVertexNum;
int nIndex2 = rand() % nVertexNum;
// 交换两个数值
int nTmp = pGameMap[nIndex1 / nCols][nIndex1 % nCols];
pGameMap[nIndex1  /  nCols][nIndex1  %  nCols]  =  pGameMap[nIndex2  /
nCols][nIndex2 % nCols];
pGameMap[nIndex2 / nCols][nIndex2 % nCols] = nTmp;
}
//return pGameMap;
	};  

	void ReleaseMap(int** &pGameMap)
{
for (int i = 0; i < 10; i++)
{
delete []pGameMap[i];
}
delete []pGameMap;
};

bool IsLink(int** pGameMap, Vertex v1, Vertex v2)  ;
bool IsBlank();
void Clear(int** pGameMap, Vertex v1, Vertex v2);
int GetVexPath(Vertex avPath[4])  ;
	
bool LinkInRow(int** pGameMap, Vertex v1, Vertex v2);//  判断横向是否连通
bool LinkInCol(int** pGameMap, Vertex v1, Vertex v2) ;// 判断纵向是否连通
bool OneCornerLink(int** pGameMap, Vertex v1, Vertex v2) ;// 一个拐点连通判断
bool LineY(int** pGameMap, int nRow1, int nRow2, int nCol) ;// 直线连通 Y 轴
bool LineX(int** pGameMap, int nRow, int nCol1, int nCol2) ;// 直线连通 X 轴
void PushVertex(Vertex v);//  添加一个路径顶点
void PopVertex() ;// 取出一个顶点
void ClearStack() ;// 清除栈
bool TwoCornerLink(int** pGameMap, Vertex v1, Vertex v2) ;// 三条直线消子判断



};

