/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-24
 >
 > 1）拓扑排序的KaHn算法
 > 2）拓扑排序的DFS算法
 > 3）
 ************************************************************************/
#include "DAG.h"
void main()
{
	struct LGraph_List g;
	creat_Graph_List(&g);
	//print(&g);
	//KaHn(&g);
	DAG_DFS_Init(&g);
	system("pause");
}