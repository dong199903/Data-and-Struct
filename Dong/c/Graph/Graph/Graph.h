/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H
//邻接矩阵
struct MGraph
{
	int **data;//二维数组
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	char *vetex;//顶点数组
};
//图的初始化
void Init_Graph_Matrix(struct MGraph *g);

//图的创建
void creat_Graph_Matrix(struct MGraph *g);

//图的打印
void print_Graph_Matrix(struct MGraph *g);


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


//图的创建
void creat_Graph_List(struct LGraph_List *g);

//图的打印
void print_Graph_List(struct LGraph_List *g);
#endif // !GRAPH_H

