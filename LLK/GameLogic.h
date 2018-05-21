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
// ��ȡ��ͼ��С�ͻ�ɫ
//int nRows = CGameControl::s_nRows;
//int nCols = CGameControl::s_nCols;
//int nPicNum = CGameControl::s_nPicNum;

int nRows = 10;
int nCols = 16;
int nPicNum = 20;
// �����ڴ�����
pGameMap = new int*[nRows];
if(NULL == pGameMap)
{
//throw new CGameException(_T("�ڴ�����쳣��\n"));
}
else
{
for (int i = 0; i < nRows; i++)
{
pGameMap[i] = new int[nCols];
if(NULL == pGameMap)
{
//throw new CGameException(_T("�ڴ�����쳣��\n"));
}
memset(pGameMap[i], NULL, sizeof(int) * nCols);
}
}


// ���ٻ�ɫ
if ((nRows * nCols) % (nPicNum * 2) != 0)
{
//ReleaseMap(pGameMap);
//throw new CGameException(_T("��Ϸ��ɫ����Ϸ��ͼ��С��ƥ�䣡"));
}
int nRepeatNum = nRows * nCols / nPicNum;
int nCount = 0;
for(int i = 0; i < nPicNum; i++)
{
// �ظ���
for(int j = 0; j < nRepeatNum; j++)
{
pGameMap[nCount / nCols][nCount % nCols] = i;
nCount++;
}
}

// ��������
srand((int)time(NULL));
// ������⽻����������
int nVertexNum = nRows * nCols;
for(int i = 0; i < nVertexNum; i++)
{
// ����õ���������
int nIndex1 = rand() % nVertexNum;
int nIndex2 = rand() % nVertexNum;
// ����������ֵ
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
	
bool LinkInRow(int** pGameMap, Vertex v1, Vertex v2);//  �жϺ����Ƿ���ͨ
bool LinkInCol(int** pGameMap, Vertex v1, Vertex v2) ;// �ж������Ƿ���ͨ
bool OneCornerLink(int** pGameMap, Vertex v1, Vertex v2) ;// һ���յ���ͨ�ж�
bool LineY(int** pGameMap, int nRow1, int nRow2, int nCol) ;// ֱ����ͨ Y ��
bool LineX(int** pGameMap, int nRow, int nCol1, int nCol2) ;// ֱ����ͨ X ��
void PushVertex(Vertex v);//  ���һ��·������
void PopVertex() ;// ȡ��һ������
void ClearStack() ;// ���ջ
bool TwoCornerLink(int** pGameMap, Vertex v1, Vertex v2) ;// ����ֱ�������ж�



};

