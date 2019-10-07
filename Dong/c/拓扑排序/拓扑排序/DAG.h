/*************************************************************************
 > File Name: DAG.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-24
 >
 > 1）拓扑排序的KaHn算法
 > 2）拓扑排序的DFS算法
 > 3）
 ************************************************************************/
#ifndef DAG_H
#define DAG_H
struct Node
{
	int index;
	struct Node *next;
};
struct LGraph
{
	char data;
	struct Node *head;
	int degree;//每个点都有个入度个数
};

struct LGraph_List
{
	struct LGraph * list;
	int numVretexes;//顶点个数
	int numEdges;//边的个数
};
//图的创建
void creat_Graph_List(struct LGraph_List *g);
//输出测试
void print(struct LGraph_List *g);
//KaHn算法
void KaHn(struct LGraph_List *g);
//基于DFS的拓扑排序算法
void DAG_DFS_Init(struct LGraph_List *g);
void DAG_DFS(struct LGraph_List *g,int *visit,int num,int*count);
#endif // !DAG_H

