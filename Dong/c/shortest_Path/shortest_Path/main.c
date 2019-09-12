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
#include "shortest_Path.h"
void main()
{
	struct MGraph g;
	creat_Graph_Matrix(&g);
	//Dijkstra(&g, 'a');
	Bellman_Ford(&g, 'a');
	system("pause");
}