//
// Created by sunzhijun on 18-2-17.
//

#ifndef SUANFA_ASTAR_H
#define SUANFA_ASTAR_H


#include <list>
#include <stdio.h>
#include <cstdlib>


typedef unsigned char TileType;

typedef struct AStarPoint
{
    int i, j;
}AStarPoint;

typedef struct AStarNode
{//节点结构体
    int f, g, h;//f=g+h
    int row;  //该节点所在行
    int col;  //该节点所在列
    AStarPoint direct;//parent节点要移动的方向就能到达本节点
    struct AStarNode * parent;
}AStarNode;

typedef struct AStarList
{//OPEN CLOSED 表结构体
    AStarNode * npoint;
    struct AStarList * next;
}AStarList;

#define MAXROW  100
#define MAXCOL  100
class AStar
{
public:
    AStar();
    ~AStar();

    static AStar* getInstance();
    static void destroy();

    static std::list<AStarPoint>
    run(TileType inMap[MAXROW][MAXCOL],
        int inRow, int inCol,
        int StartX, int StartY, int EndX, int EndY);
    void PrintMap();//测试用

    AStarNode* getNodeFromOpen();
    void pushOpen(AStarNode * suc);
    void pushClosed(AStarNode * suc);
    int getH(int row, int col);
    int getRowPosition(int y);
    int getColPosition(int x);
    AStarNode* checkOpen(int row, int col);
    bool isInClose(int row, int col);
    void creatNextLapNode(AStarNode *bestNode, int row, int col, int G_OFFSET);

    bool isCanMove(int col, int row);
    void seachSeccessionNode(AStarNode *bestNode);
    std::list<AStarPoint>
    findPath(TileType inMap[MAXROW][MAXCOL],
             int inRow, int inCol,
             int StartX, int StartY, int EndX, int EndY);
private:
    int map[MAXROW][MAXCOL];
    int rows;
    int cols;
    int destinationRow;
    int destinationCol;
};

AStar::AStar()
{
}

AStar::~AStar()
{
}

static AStar* m_only_AStar = nullptr;
AStar* AStar::getInstance()
{
    if (!m_only_AStar)
    {
        m_only_AStar = new AStar;
    }

    return m_only_AStar;
}

void AStar::destroy()
{
    if (m_only_AStar)
    {
        delete m_only_AStar;
        m_only_AStar = nullptr;
    }
}

#define NULL    0
#define G_OFFSET1 10    //每个图块G值的增加值
#define G_OFFSET2 14
#define TileSize  1     //图块大小
#define Tile_Lock 0
#define Tile_Open 1
#define Tile_Start 2
#define Tile_End  3
#define Tile_Path 4

static AStarList* Open = NULL;
static AStarList* Closed = NULL;
void ClearList(AStarList* list)
{
    AStarList* temp = list->next;
    AStarNode *p_node;
    if (temp == NULL)
        return;
    while (temp != NULL)
    {
        AStarList* head = temp;
        temp = temp->next;
        p_node = head->npoint;
        delete p_node;
        delete head;
        list->next = temp;
    }
}

void ClearOpenData()
{//清空Open表
    ClearList(Open);
}

void ClearClosedData()
{//清空Close表
    ClearList(Closed);
}
std::list<AStarPoint> AStar::run(TileType inMap[MAXROW][MAXCOL], int inRow, int inCol, int StartX, int StartY, int EndX, int EndY)
{//主接口
    auto astar = AStar::getInstance();

    Open = new AStarList;
    Open->next = nullptr;
    Closed = new AStarList;
    Closed->next = nullptr;

    auto ret = astar->findPath(inMap, inRow, inCol, StartX, StartY, EndX, EndY);

    ClearOpenData();
    ClearClosedData();
    delete(Open);
    delete(Closed);

    return ret;
}

void AStar::PrintMap()
{//输出地图
    int i, j;
    for (i = 0; i<rows; i++)
    {
        for (j = 0; j<cols; j++)
        {
            if (map[i][j] == Tile_Open) {
                printf("□");
            }
            else if (map[i][j] == Tile_Lock) {
                printf("■");
            }
            else if (map[i][j] == Tile_Start) {
                printf("☆");
            }
            else if (map[i][j] == Tile_End) {
                printf("★");
            }
            else if (map[i][j] == Tile_Path) {
                printf("●");
            }
        }
        printf("\n");
    }
}


AStarNode* AStar::getNodeFromOpen()
{//选取Open表上f值最小的节点，返回该节点地址
    AStarList* temp = Open->next,
            *min = Open->next,
            *minp = Open;
    AStarNode * minx;
    if (temp == NULL)
        return NULL;

    while (temp->next != NULL)
    {
        if ((temp->next->npoint->f) < (min->npoint->f))
        {
            min = temp->next;//min表示f最小的链表节
            minp = temp;//指向min的指针，为的是在后面的释放中用到
        }
        temp = temp->next;//temp指向下一个链表节
    }
    minx = min->npoint;
    temp = minp->next;
    minp->next = minp->next->next;
    delete temp;
    return minx;
}

void AStar::pushOpen(AStarNode * suc)
{//把节点放入Open表中
    AStarList * temp;
    temp = new AStarList;
    temp->npoint = suc;

    temp->next = Open->next;
    Open->next = temp;
}

void AStar::pushClosed(AStarNode * suc)
{//把节点放入Close表中
    AStarList * temp;
    temp = new AStarList;
    temp->npoint = suc;
    temp->next = Closed->next;
    Closed->next = temp;
}

int AStar::getH(int row, int col)
{//得到该图块的H值
    int x;
    x = abs(destinationRow - row) + abs(destinationCol - col) + 1;
    return x * 10;
}

int AStar::getRowPosition(int y)
{//得到该位置所在地图行
    return (y / TileSize);
}

int AStar::getColPosition(int x)
{//得到该位置所在地图列
    return (x / TileSize);
}

bool AStar::isCanMove(int col, int row)
{//检测该图块是否可通行
    if (col < 0 || col >= cols)
        return false;
    if (row < 0 || row >= rows)
        return false;
    if (map[row][col] == Tile_Lock)
        return false;

    return true;
}

AStarNode* AStar::checkOpen(int row, int col)
{//校验Open表
    AStarList* temp = Open->next;
    if (temp == NULL)
        return NULL;
    while (temp != NULL)
    {
        if ((temp->npoint->row == row) && (temp->npoint->col == col))
        {
            return temp->npoint;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

bool AStar::isInClose(int row, int col)
{//是否存在于Close表
    AStarList* temp = Closed->next;
    if (temp == NULL)
        return false;
    while (temp != NULL)
    {
        if ((temp->npoint->row == row) && (temp->npoint->col == col))
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

void AStar::creatNextLapNode(AStarNode *bestNode, int row, int col, int G_OFFSET)
{//创建下一圈的node
    int g = bestNode->g + G_OFFSET;
    if (!isInClose(row, col))
    {
        AStarNode *oldNode = NULL;
        if ((oldNode = checkOpen(row, col)) != NULL)
        {
            if (oldNode->g > g)
            {
                oldNode->direct.i = bestNode->col;
                oldNode->direct.j = bestNode->row;
                oldNode->parent = bestNode;
                oldNode->g = g;
                oldNode->f = g + oldNode->h;
            }
        }
        else
        {
            AStarNode *node = new AStarNode;
            node->parent = bestNode;
            node->g = g;
            node->h = getH(row, col);
            node->f = node->g + node->h;
            node->row = row;
            node->col = col;
            node->direct.i = bestNode->col;
            node->direct.j = bestNode->row;

            pushOpen(node);
        }
    }
}

void AStar::seachSeccessionNode(AStarNode *bestNode)
{//根据传入的节点生成子节点
    int row, col;
    //上部节点
    if (isCanMove(row = bestNode->row - 1, col = bestNode->col))
    {
        creatNextLapNode(bestNode, row, col, G_OFFSET1);
    }
    //下部节点
    if (isCanMove(row = bestNode->row + 1, col = bestNode->col))
    {
        creatNextLapNode(bestNode, row, col, G_OFFSET1);
    }
    //左部节点
    if (isCanMove(row = bestNode->row, col = bestNode->col - 1))
    {
        creatNextLapNode(bestNode, row, col, G_OFFSET1);
    }
    //右部节点
    if (isCanMove(row = bestNode->row, col = bestNode->col + 1))
    {
        creatNextLapNode(bestNode, row, col, G_OFFSET1);
    }
    ////左上角
    //if(isCanMove(row = bestNode->row-1, col = bestNode->col - 1))
    //{
    //  creatNextLapNode(bestNode, row, col,G_OFFSET2);
    //}
    ////右上角
    //if(isCanMove(row = bestNode->row+1, col = bestNode->col - 1))
    //{
    //  creatNextLapNode(bestNode, row, col,G_OFFSET2);
    //}
    ////左下角
    //if(isCanMove(row = bestNode->row-1, col = bestNode->col + 1))
    //{
    //  creatNextLapNode(bestNode, row, col,G_OFFSET2);
    //}
    ////右下角
    //if(isCanMove(row = bestNode->row+1, col = bestNode->col + 1))
    //{
    //  creatNextLapNode(bestNode, row, col,G_OFFSET2);
    //}

    pushClosed(bestNode);
}

std::list<AStarPoint> AStar::findPath(TileType inMap[MAXROW][MAXCOL], int inRow, int inCol, int StartX, int StartY, int EndX, int EndY)
{//主函数
    rows = inRow;
    cols = inCol;
    for (int i = 0; i < rows; i++)
    {
        for (int x = 0; x < cols; x++)
        {
            map[i][x] = inMap[i][x];
            if (i == StartX && x == StartY)
            {
                map[i][x] = Tile_Start;
            }
            if (i == EndX && x == EndY)
            {
                map[i][x] = Tile_End;
            }
        }
    }
    PrintMap();

    AStarNode *startNode = new AStarNode;
    AStarNode *bestNode = NULL;
    destinationRow = getRowPosition(EndY);
    destinationCol = getColPosition(EndX);

    startNode->parent = NULL;
    startNode->row = getRowPosition(StartY);
    startNode->col = getColPosition(StartX);
    startNode->g = 0;
    startNode->h = getH(startNode->row, startNode->col);
    startNode->f = startNode->g + startNode->h;
    startNode->direct.i = startNode->col;
    startNode->direct.j = startNode->row;
    pushOpen(startNode);

    std::list<AStarPoint> ret;
    AStarPoint point;
    while (true)
    {
        bestNode = getNodeFromOpen(); //从OPEN表中取出f值最小的节点
        if (bestNode == NULL)//未找到路径
        {
            break;
        }
        else if (bestNode->row == destinationRow && bestNode->col == destinationCol)
        {
            map[bestNode->col][bestNode->row] = Tile_Path;
            point.i = bestNode->col;
            point.j = bestNode->row;
            ret.push_front(point);//实际运行去掉,不然会到达最后一个格子再折返
            while (!(bestNode->direct.i == StartX&&bestNode->direct.j == StartY))
            {
                map[bestNode->direct.i][bestNode->direct.j] = Tile_Path;
                bestNode = bestNode->parent;

                point.i = bestNode->col;
                point.j = bestNode->row;
                ret.push_front(point);
            }
            break;
        }

        seachSeccessionNode(bestNode);
    }
    PrintMap();

    return ret;
}



#endif //SUANFA_ASTAR_H
