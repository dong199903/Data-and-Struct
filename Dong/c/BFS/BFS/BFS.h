/*************************************************************************
 > File Name: BFS.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）图的广度遍历
 > 2）图的广度搜索-找路径
 > 3）
 ************************************************************************/
#ifndef BFS_H
#define BFS_H
 //邻接矩阵
struct MGraph
{
	int **data;//二维数组
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	char *vetex;//顶点数组
};
//图的初始化-邻接矩阵
void Init_Graph_Matrix(struct MGraph *g);

//图的创建-邻接矩阵
void creat_Graph_Matrix(struct MGraph *g);

//图的打印-邻接矩阵
void print_Graph_Matrix(struct MGraph *g);

//图的广度遍历-邻接矩阵
void BFS_Matrix(struct MGraph *g);

//图的广度搜索-找路径
void Find_Path(struct MGraph *g, char obj1, char obj2);


//邻接表
struct Node
{
	int index;
	struct Node *next;
};
struct LGraph
{
	char data;
	struct Node *head;
};

struct LGraph_List
{
	struct LGraph * list;
	int numVretexes;//顶点个数
	int numEdges;//边的个数
};

//图的创建-邻接表
void creat_Graph_List(struct LGraph_List *g);

//图的打印-邻接表
void print_Graph_List(struct LGraph_List *g);

//图的广度遍历-邻接表
void BFS_List_Queue(struct LGraph_List *g);
#endif // !BFS_H

