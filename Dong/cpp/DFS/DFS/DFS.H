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
#ifndef DFS_H
#define DFS_H

 //设计是形参的数组
class Array
{
public:
	int len;
	int data[100];
};


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
	void creat_Graph_Matrix();
	void print_Graph_Matrix();
	//图的深度遍历-邻接矩阵-递归
	void DFS_Matrix();
	void DFS(int index, int *visit);
	//图的深度遍历-邻接矩阵-非递归
	void DFS_Matrix_Stack(int index);
	//图的深度优先搜索-邻接矩阵(搜索两个点之间的路径)
	void DFS_Search(Array arr, int *temp, int obj1, int obj2);
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
	T data;
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
	//图的深度遍历-邻接表-递归
	void DFS_List();
	void DFS_DG( int *visit, int index);
	//图的深度遍历-邻接表-非递归
	void DFS_List_Stack();
};
#endif // !DFS_H

