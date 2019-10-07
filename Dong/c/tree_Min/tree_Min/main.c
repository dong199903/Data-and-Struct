/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-20
 >
 > 1）普利姆算法
 > 2）克鲁斯卡尔算法
 *************************************************************************/
#include "tree_Min.h"
#include<stdio.h>
void main()
{
	struct MGraph g;
	creat_Graph_Matrix(&g);
	//Prim(&g,'a');
	Kruskal(&g);
	system("pause");
}