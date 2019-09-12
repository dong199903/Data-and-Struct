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
#include "BFS.h"
void main()
{
	struct MGraph g1;
	Init_Graph_Matrix(&g1);
	creat_Graph_Matrix(&g1);
	BFS_Matrix(&g1);
	printf("\n");
	Find_Path(&g1, 'a', 'c');
	struct LGraph_List g2;
	creat_Graph_List(&g2);
	BFS_List_Queue(&g2);
	system("pause");

}