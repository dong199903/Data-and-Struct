/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）迪杰斯特拉算法Dijkstra---------------不能处理带负权的图
 > 2）贝尔曼-福特算法Bellman-Ford----------可以处理带负权的图
 > 3）SPFA算法
 > 4）Flody算法
 ************************************************************************/
#include "shortest_Path.h"
void main()
{
	struct MGraph g;
	creat_Graph_Matrix(&g);
	//Dijkstra(&g, 'a');
	Bellman_Ford(&g, 'a');
	//SPFA(&g,'a');
	//Floyd(&g);
	system("pause");
}