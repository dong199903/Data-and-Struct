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
#include "Graph.h"
void main()
{
	//邻接矩阵测试
	struct MGraph gh;
	Init_Graph_Matrix(&gh);
	creat_Graph_Matrix(&gh);
	print_Graph_Matrix(&gh);



	//邻接表测试
	/*
	struct LGraph_List g;
	creat_Graph_List(&g);
	print_Graph_List(&g);
	*/
	system("pause");
}