/*************************************************************************
> File Name: DFS.H
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-08-23
>
> 1）基于图的邻接矩阵的深度优先遍历(递归实现)
> 2）基于图的邻接矩阵的深度优先遍历(非递归实现)
> 3）基于图的邻接表的深度优先遍历(递归实现)
> 4）基于图的邻接表的深度优先遍历(非递归实现)
************************************************************************/
#ifndef DFS_H
#define DFS_H
//邻接矩阵
struct MGraph
{
	int **data;//二维数组
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	char *vetex;//顶点数组
};
//设计是形参的数组
struct Array
{
	int len;
	int data[100];
};
//图的初始化-邻接矩阵
void Init_Graph_Matrix(struct MGraph *g);

//图的创建-邻接矩阵
void creat_Graph_Matrix(struct MGraph *g);

//图的打印-邻接矩阵
void print_Graph_Matrix(struct MGraph *g);

//图的深度遍历-邻接矩阵-递归
void DFS_Matrix(struct MGraph *g);
void DFS(struct MGraph *g, int index, int *visit);

//图的深度遍历-邻接矩阵-非递归
void DFS_Matrix_Stack(struct MGraph *g, int index);

//图的深度优先搜索-邻接矩阵(搜索两个点之间的路径)
void DFS_Search(struct MGraph *g, struct Array arr,int *temp,int obj1, int obj2);
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

//图的深度遍历-邻接表-递归
void DFS_List(struct LGraph_List *g);
void DFS_DG(struct LGraph_List *g, int *visit, int index);

//图的深度遍历-邻接表-非递归
void DFS_List_Stack(struct LGraph_List *g);

#endif // !DFS_H

