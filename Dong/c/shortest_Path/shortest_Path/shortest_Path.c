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
#include <stdio.h>
#include <stdlib.h>
 //图的创建-邻接矩阵
void creat_Graph_Matrix(struct MGraph *g)
{
	int x1, x2,w;
	printf("请输入图的顶点个数和边的个数: ");
	scanf_s("%d%d", &g->numVretexes, &g->numEdges);
	g->vetex = (char*)malloc(sizeof(char)*g->numVretexes);
	g->data = (int**)malloc(sizeof(int*)*g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		g->data[i] = (int*)malloc(sizeof(int)*g->numVretexes);
	}
	for (int i = 0; i < g->numVretexes; i++)
	{
		for (int j = 0; j < g->numVretexes; j++)
		{
			if (i == j)
			{
				g->data[i][j] = 0;
			}
			else
			{
				g->data[i][j] = MAX;
			}
			
		}
	}
	for (int i = 0; i < g->numEdges; i++)
	{
		getchar();//吸收空格
		printf("请输入第%d个顶点信息: ", i + 1);
		scanf_s("%c", &g->vetex[i]);
	}

	for (int i = 0; i < g->numEdges; i++)
	{
		printf("请输入第%d条边两个端点的下标和权值 ", i + 1);
		scanf_s("%d%d%d", &x1, &x2, &w);
		g->data[x1][x2] = w;//代表两点相连接构成边
		g->data[x2][x1] = w;
	}
}
//迪杰斯特拉算法
void Dijkstra(struct MGraph *g, char obj)
{
	int *temp, *dis, *pre,index,min,k;
	temp = (int*)malloc(sizeof(int) * g->numVretexes);
	dis = (int*)malloc(sizeof(int) * g->numVretexes);
	pre = (int*)malloc(sizeof(int) * g->numVretexes);
	//找出源节点的位置
	for (int i = 0; i < g->numVretexes; i++)
	{
		if (g->vetex[i] == obj)
		{
			index = i;
			break;
		}
	}
	//初始化辅助数组
	for (int i = 0; i < g->numVretexes; i++)
	{
		temp[i] = 0;
		pre[i] = -1;
		dis[i] = g->data[index][i];
	}
	temp[index] = 1;
	for (int i = 1; i < g->numVretexes; i++)
	{
		min = MAX;
		//找出当前dis存储最小的下标
		for (int j = 0; j < g->numVretexes; j++)
		{
			if (temp[j] == 0 && g->data[index][j] < min)
			{
				min = g->data[index][j];
				k = j;//标记最小值的位置
			}
		}
		temp[k] = 1;
		index = k;
		//从该点开始，逐个判断并修改dis数组
		for (int j = 0; j < g->numVretexes; j++)
		{
			if (temp[j] == 0 && (g->data[k][j] + dis[k]) < dis[j])
			{
				dis[j] = g->data[k][j] + dis[k];
				pre[j] = k;
			}
		}
	}

	//dis数组就是源点到各个点的最短路径
	for (int i = 0; i < g->numVretexes;i++)
	{
		printf("%c-->%c(%d)\n", obj, g->vetex[i], dis[i]);
	}
	printf("\n");
}
//贝尔曼-福特算法
void Bellman_Ford(struct MGraph *g, char obj)
{
	int *dis, *pre,index;
	dis = (int*)malloc(sizeof(int) *g->numVretexes);
	pre = (int*)malloc(sizeof(int) * g->numVretexes);
	//找出目标点位置
	for (int i = 0; i < g->numVretexes; i++)
	{
		if (g->vetex[i] == obj) {
			index = i;
			break;
		}
	}
	//初始化辅助数组
	for (int i = 0; i < g->numVretexes; i++)
	{
		dis[i] = g->data[index][i];
		if (i!=index && dis[i] < MAX)
		{
			pre[i] = index;
		}
		else
		{
			pre[i] = -1;
		}
	}
	//n-1论循环
	for (int i = 1; i < g->numVretexes; i++)
	{
		//每个点都进行松弛测试
		for (int j = 0; j < g->numVretexes; j++)
		{
			if (j != index)//起点不用松弛操作
			{
				for (int k = 0; k < g->numVretexes; k++)
				{
					if (dis[k] != MAX && dis[k] + g->data[k][j] < dis[j])
					{
						dis[j] = dis[k] + g->data[k][j];
						pre[j] = k;
					}
				}
			}
		}
	}
	//输出dis数组--距离
	for (int i = 0; i < g->numVretexes; i++)
	{
		printf("%c-->%c(%d)\n", obj, g->vetex[i], dis[i]);
	}
	printf("\n");
}