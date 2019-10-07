/*************************************************************************
 > File Name: shortest_Path.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-23
 >
 > 1）迪杰斯特拉算法Dijkstra---------------不能处理带负权的图
 > 2）贝尔曼-福特算法Bellman-Ford----------可以处理带负权的图
 > 3）SPFA算法
 > 4）Flody算法
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
	for (int i = 0; i < g->numVretexes; i++)
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
	int *dis, *pre,index,temp;
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
	//初始化dis数组
	for (int i = 0; i < g->numVretexes; i++)
	{
		dis[i] = MAX;
		pre[i] = -1;
	}
	dis[index] = 0;
	for (int k = 1; k < g->numVretexes; k++)
	{
		for (int i = 0; i < g->numVretexes; i++)
		{
			for (int j = 0; j < g->numVretexes; j++)
			{
				if (j != index && i != j && g->data[i][j] != MAX)
				{
					if (dis[i] + g->data[i][j] < dis[j])
					{
						dis[j] = dis[i] + g->data[i][j];
						pre[j] = i;
					}
				}
			}
		}
	}
	//经过松弛后，如果还可以松弛，表示图中存在负数权回路
	temp = 0;
	for (int i = 0; i < g->numVretexes; i++)
	{
		for (int j = 0; j < g->numVretexes; j++)
		{
			if (j != index && i != j && g->data[i][j] != MAX)
			{
				if (dis[i] + g->data[i][j] < dis[j])
				{
					temp = 1;
					printf_s("图中存在负权回路\n");
					return;
				}
			}
		}
	
	}
	//输出dis数组
	for (int i = 0; i < g->numVretexes; i++)
	{
		printf_s("%d ", dis[i]);
	}
	
}

//SPFA算法---仅仅可以用正权图和有向的负权图
void SPFA(struct MGraph *g, char obj)
{
	int index,i,*queue,*visit,*dis,*path,front,rear,top;
	queue = (int*)malloc(sizeof(int)*100);//防止队列溢出(此处的队列非循环队列)
	visit = (int*)malloc(sizeof(int)*g->numVretexes);
	dis = (int*)malloc(sizeof(int)*g->numVretexes);
	path = (int*)malloc(sizeof(int)*g->numVretexes);
	//1.找出源点
	for (i = 0; i < g->numVretexes; i++)
	{
		if (g->vetex[i] == obj)
		{
			index = i;
		}
	}
	//2:初始化队列,辅助数组
	for (i = 0; i < g->numVretexes; i++)
	{
		visit[i] = 0;
		dis[i] = MAX;
		path[i] = -1;
	}
	front = rear = 0;
	queue[rear++] = index;
	visit[index] = 1;
	dis[index] = 0;
	while (rear != front)//队列空结束
	{
		top = queue[front++];
		visit[top] = 0;
		for (i = 0; i < g->numVretexes; i++)
		{
			if (i != top)
			{
				if (dis[i] > (dis[top] + g->data[top][i]))
				{
					dis[i] = dis[top] + g->data[top][i];
					path[i] = top;
					if (visit[i] == 0)//没在队列里,入队
					{
						queue[rear++] = i;
						visit[i] = 1;
					}
				}
			}
		}
	}
	//输出最端距离和路径
	for (i = 0; i < g->numVretexes; i++)
	{
		if (i != index)
		{
			printf_s("%c-->%c(%d)\n", g->vetex[index], g->vetex[i], dis[i]);
		}
	}
}

void print_Path(int begin, int last, struct MGraph *g, int **path)
{
	if (path[begin][last] == -1)
	{
		printf_s("%c-->%c-->", g->vetex[begin], g->vetex[last]);
	}
	else
	{
		int mid = path[begin][last];
		print_Path(begin, mid, g, path);
		print_Path(mid, last, g, path);
	}
}
//Floyd算法
void Floyd(struct MGraph *g)
{
	int i, j, k,temp=0;
	int **dis, **path;
	dis = (int**)malloc(sizeof(int*) * g->numVretexes);
	path = (int**)malloc(sizeof(int*) * g->numVretexes);
	for (i = 0; i < g->numVretexes; i++)
	{
		dis[i] = (int*)malloc(sizeof(int) *g->numVretexes);
		path[i] = (int*)malloc(sizeof(int) *g->numVretexes);
	}
	//初始化dis和path数组
	for (i = 0; i < g->numVretexes; i++)
	{
		for (j = 0; j < g->numVretexes; j++)
		{
			dis[i][j] = g->data[i][j];
			path[i][j] = -1;
		}
	}
	//开始逐个点p的判断
	for (i = 0; i < g->numVretexes; i++)
	{
		//逐个取出每两个点x,y，判断dis[x][y] > dis[x][p]+dis[p][y]
		for (j = 0; j < g->numVretexes; j++)
		{
			for (k = 0; k < g->numVretexes; k++)
			{
				if (dis[j][k] > dis[j][i] + dis[i][k])
				{
					dis[j][k] = dis[j][i] + dis[i][k];
					path[j][k] = i;
				}
			}
		}
	}

	//输出最短距离
	for (i = 0; i < g->numVretexes; i++)
	{
		for (j = 0; j < g->numVretexes; j++)
		{
			if (i != j)
			{
				//printf_s("%c-->%c(%d)", g->vetex[i], g->vetex[j], dis[i][j]);
				print_Path(i, j, g, path);
				printf("%d\n", dis[i][j]);
			}
		}
	}
}