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
#ifndef DAG_H
#define DAG_H
class Node
{
public:
	int index;
	struct Node *next;
};
class LGraph
{
public:
	char data;
	Node *head;
	int degree;//每个点都有个入度个数
};

class LGraph_List
{
public:
	LGraph * list;
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	LGraph_List();
	//图的创建
	void creat_Graph_List();
	//输出测试
	void print();
	//KaHn算法
	void KaHn();
	//基于DFS的拓扑排序算法
	void DAG_DFS_Init();
	void DAG_DFS(int *visit, int num, int*count);
};

#endif // !DAG_H

