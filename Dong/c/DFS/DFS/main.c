/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-23
 >
 > 1）基于图的邻接矩阵的深度优先遍历(递归实现)
 > 2）基于图的邻接矩阵的深度优先遍历(非递归实现)
 > 3）基于图的邻接表的深度优先遍历(递归实现)
 > 4）基于图的邻接表的深度优先遍历(非递归实现)
 > 5）基于图的深度优先搜索(寻找简单路径)
 ************************************************************************/
#include "DFS.h"
void main()
{
	struct MGraph g1;
	Init_Graph_Matrix(&g1);
	creat_Graph_Matrix(&g1);
	DFS_Matrix(&g1);
	DFS_Matrix_Stack(&g1, 0);
	Find_Path(&g1, 'a', 'c');
	struct LGraph_List g2;
	creat_Graph_List(&g2);
	DFS_List(&g2);
	DFS_List_Stack(&g2);
	system("pause");
}