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
#ifndef BFS_H
#define BFS_H
 //邻接矩阵
template<class T>
class MGraph
{
public:
	int **data;//二维数组
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	T *vetex;//顶点数组
	MGraph();
	//图的创建-邻接矩阵
	void creat_Graph_Matrix();

	//图的广度遍历-邻接矩阵
	void BFS_Matrix();

	//图的广度搜索-找路径
	void Find_Path(char obj1, char obj2);
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
	char data;
	Node *head;
};


template<class T>
class LGraph_List
{
public:
	LGraph<T> * list;
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	LGraph_List();
	//图的创建-邻接表
	void creat_Graph_List();
	//图的广度遍历-邻接表
	void BFS_List_Queue();
};



#endif // !BFS_H

