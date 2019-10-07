/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）图的广度遍历
 > 2）图的广度搜索-找路径
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