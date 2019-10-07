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
#include <iostream>
using namespace std;
#include "tree_Min.h"
MGraph::MGraph()
{
	this->numVertes = this->numEdges = 0;
}
//图的创建
void MGraph::creat_Graph_Matrix()
{
	int index1, index2, w;
	cout<<"请输入图的顶点个数和边的个数: ";
	cin>>this->numVertes>>this->numEdges;
	this->vetes = new char[this->numVertes];
	this->data = new int*[this->numVertes];
	for (int i = 0; i < this->numVertes; i++)
	{
		this->data[i] = new int[this->numVertes];
	}
	cout<<"输入每个顶点信息: ";
	for (int i = 0; i < this->numVertes; i++)
	{
		getchar();
		cin>>this->vetes[i];
	}
	//初始边权值
	for (int i = 0; i < this->numVertes; i++)
	{
		for (int j = 0; j < this->numVertes; j++)
		{
			if (i == j)
			{
				this->data[i][j] = 0;
			}
			else
			{
				this->data[i][j] = MAX;
			}
		}
	}
	cout<<"输入边的起始下标和权值\n";
	for (int i = 0; i < this->numEdges; i++)
	{
		cin>>index1>>index2>>w;
		this->data[index1][index2] = w;
		this->data[index2][index1] = w;
	}
}
//最下生成树-Prime
void MGraph::Prim(char obj)
{
	int index = 0, min, k;
	//标记数组temp（记录顶点是否被访问）
	int *temp = new int[this->numVertes];
	//距离数组dis（标记当前最短距离）
	int *dis = new int[this->numVertes];
	//前驱数组pre（标记每个点前驱节点）
	int *pre = new int[this->numVertes];
	//寻找起点的下标
	for (int i = 0; i < this->numVertes; i++) {
		if (this->vetes[i] == obj)
		{
			index = i;
			break;
		}
	}
	cout<<index<<" ";
	//初始化数组
	for (int i = 0; i < this->numVertes; i++)
	{
		dis[i] = this->data[index][i];
		temp[i] = 0;//未访问
		pre[i] = index;//前驱都是起点
	}
	temp[index] = 1;
	for (int i = 1; i < this->numVertes; i++)
	{
		min = MAX;
		//找出最小权值的边,并标记点
		for (int j = 0; j < this->numVertes; j++)
		{
			if (temp[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				k = j;
			}
		}
		//输出边
		cout << this->vetes[index] << "-->" << this->vetes[k] << "\n";
		//修改dis,temp,pre数组
		temp[k] = 1;
		index = k;
		for (int j = 0; j < this->numVertes; j++)
		{
			if (temp[j] == 0 && this->data[k][j] < dis[j])
			{
				dis[j] = this->data[k][j];
				pre[j] = k;
			}
		}
	}
}
//最小生成树-Kruskal
void MGraph::Kruskal()
{
	int min = MAX, temp, num = 0, begin, end;
	Edge swap;
	Edge *edge = new Edge[this->numEdges];
	UFStree *Utree = new UFStree[this->numVertes];
	//初始化edge，Utree
	for (int i = 0; i < this->numVertes; i++)
	{
		Utree[i].high = 0;
		Utree[i].index = i;
		Utree[i].parent = i;
		for (int j = 0; j < this->numVertes; j++)
		{
			if (i<j && this->data[i][j] != 0 && this->data[i][j] != MAX)
			{
				edge[num].begin = i;
				edge[num].end = j;
				edge[num].w = this->data[i][j];
				num++;
			}
		}
	}
	//按照边的权值排序(从小到大)
	for (int i = 0; i < num; i++)
	{
		min = edge[i].w;
		temp = i;
		for (int j = i + 1; j < num; j++)
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
	for (int i = 0; i < this->numEdges; i++)
	{
		begin = edge[i].begin;
		end = edge[i].end;
		if (find_Tree(Utree, begin) != find_Tree(Utree, end))
		{
			union_Tree(Utree, begin, end);
			cout << this->vetes[begin] << "-->" << this->vetes[end] << this->data[begin][end]<<endl;
		}
	}
}


int find_Tree(UFStree *tree, int num)
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
void union_Tree(UFStree *tree, int x, int y)
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
