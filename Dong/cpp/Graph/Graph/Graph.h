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
template<class T>
class MGraph
{
public:
	MGraph();
	int **data;//二维数组
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	T *vetex;//顶点数
	//图的创建
	void creat_Graph_Matrix();

	//图的打印
	void print_Graph_Matrix();
};


//邻接表
class Node
{
public:
	int index;
	Node *next;
};


template<class T>
class LGraph
{
public:
	T data;
	Node *head;
};


template<class T>
class LGraph_List
{
public:
	LGraph_List();
	LGraph<T> * list;
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	 //图的创建
	void creat_Graph_List();
	//图的打印
	void print_Graph_List();
};
#endif // !GRAPH_H

