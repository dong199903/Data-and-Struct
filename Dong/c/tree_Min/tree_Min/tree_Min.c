/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）普利姆算法
 > 2）克鲁斯卡尔算法
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "tree_Min.h"
 //图的创建
void creat_Graph_Matrix(struct MGraph *g)
{
	int index1, index2,w;
	printf("请输入图的顶点个数和边的个数: ");
	scanf_s("%d%d", &g->numVertes, &g->numEdges);
	g->vetes = (char*)malloc(sizeof(char) * g->numVertes);
	g->data = (int**)malloc(sizeof(int*) *g->numVertes);
	for (int i = 0; i < g->numVertes; i++)
	{
		g->data[i] = (int*)malloc(sizeof(int)* g->numVertes);
	}
	printf("输入每个顶点信息: ");
	for (int i = 0; i < g->numVertes; i++)
	{
		getchar();
		scanf_s("%c", &g->vetes[i]);
		printf("%c ", g->vetes[i]);
	}
	//初始边权值
	for (int i = 0; i < g->numVertes; i++)
	{
		for (int j = 0; j < g->numVertes; j++)
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
	printf("输入边的起始下标和权值\n");
	for (int i = 0; i < g->numEdges; i++)
	{
		scanf_s("%d%d%d", &index1, &index2, &w);
		g->data[index1][index2] = w;
		g->data[index2][index1] = w;
	}
}
//最下生成树-Prime
void Prim(struct MGraph *g, char obj)
{
	int index = 0, min, k;
	//标记数组temp（记录顶点是否被访问）
	int *temp = (int*)malloc(sizeof(int)*g->numVertes);
	//距离数组dis（标记当前最短距离）
	int *dis = (int*)malloc(sizeof(int)*g->numVertes);
	//前驱数组pre（标记每个点前驱节点）
	int *pre = (int*)malloc(sizeof(int)*g->numVertes);
	//寻找起点的下标
	for (int i = 0; i < g->numVertes; i++) {
		if (g->vetes[i] == obj)
		{
			index = i;
			break;
		}
	}
	printf("%d", index);
	//初始化数组
	for (int i = 0; i < g->numVertes; i++)
	{
		dis[i] = g->data[index][i];
		temp[i] = 0;//未访问
		pre[i] = index;//前驱都是起点
	}
	temp[index] = 1;
	for (int i = 1; i < g->numVertes; i++)
	{
		min = MAX;
		//找出最小权值的边,并标记点
		for (int j = 0; j < g->numVertes; j++)
		{
			if (temp[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				k = j;
			}
		}
		//输出边
		printf("%c-->%c\n", g->vetes[index], g->vetes[k]);
		//修改dis,temp,pre数组
		temp[k] = 1;
		index = k;
		for (int j = 0; j < g->numVertes; j++)
		{
			if (temp[j] == 0 && g->data[k][j] < dis[j])
			{
				dis[j] = g->data[k][j];
				pre[j] = k;
			}
		}
	}
}
//最小生成树-Kruskal
void Kruskal(struct MGraph *g)
{
	int min = MAX, temp, num = 0,begin,end;
	struct Edge swap;
	struct Edge *edge = (struct Edge*)malloc(sizeof(struct Edge)*g->numEdges);
	struct UFStree *Utree = (struct UFStree*)malloc(sizeof(struct UFStree)*g->numVertes);
	//初始化edge，Utree
	for (int i = 0; i < g->numVertes; i++)
	{
		Utree[i].high = 0;
		Utree[i].index = i;
		Utree[i].parent = i;
		for (int j = 0; j < g->numVertes; j++)
		{
			if (i<j && g->data[i][j] != 0 && g->data[i][j] != MAX)
			{
				edge[num].begin = i;
				edge[num].end = j;
				edge[num].w = g->data[i][j];
				num++;
			}
		}
	}
	//按照边的权值排序(从小到大)
	for (int i = 0; i < num; i++)
	{
		min = edge[i].w;
		temp = i;
		for(int j = i+1; j < num; j++)
		{
			if (edge[j].w < min)
			{
				min = edge[j].w;
				temp = j;
			}
		}
		if (temp != i)//值拷贝
		{
			swap = edge[i];
			edge[i] = edge[temp];
			edge[temp] = swap;
		}
	}
	//进行逐个边的筛选
	for (int i = 0; i < g->numEdges; i++)
	{
		begin = edge[i].begin;
		end = edge[i].end;
		if (find_Tree(Utree, begin) != find_Tree(Utree, end))
		{
			union_Tree(Utree, begin, end);
			printf("%c-->%c-->%d\n", g->vetes[begin], g->vetes[end],g->data[begin][end]);
		}
	}
	
}

//并查集的查找--根节点
int find_Tree(struct UFStree *tree, int num)
{
	if (tree[num].parent == num)//到根了//
	{
		return num;
	}
	else
	{
		return find_Tree(tree, tree[num].parent);
	}
}
//并查集节点的合并
void union_Tree(struct UFStree *tree, int x, int y)
{
	//先找到各自根，判断高度
	int xP = find_Tree(tree, x);
	int yP = find_Tree(tree, y);
	if (tree[xP].high > tree[yP].high)
	{
		tree[y].parent = xP;
	}
	else if (tree[xP].high < tree[yP].high)
	{
		tree[x].parent = yP;
	}
	else
	{
		tree[y].parent = xP;
		tree[xP].high++;
	}
}