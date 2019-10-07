/*************************************************************************
 > File Name: bound_Branch.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-10-02
 >
 > 1）0-1背包
 > 2）单源最短路径
 > 3）任务分配
 ************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include"bound_Branch.h"
//求当前节点的最大上界价值
void bound(struct Node *n, int index,int *weight, int *value, int maxWeight)
{
	int lever = n[index].lever;//当前节点层次
	int sumW = n[index].weight;
	int sumV = n[index].value;
	while (sumW <= maxWeight && lever<countPack)
	{
		sumW += weight[lever];
		sumV += value[lever];
		lever++;
	}
	if (lever < countPack)//未能全部装
	{
		n[index].up = sumV + (maxWeight - sumW)*value[lever] / weight[lever];
	}
	else {//全部装入
		n[index].up = sumV;
	}
}
//0-1背包
void package(int *weight, int *value, int maxWeight)
{
	int *queue,count=0,front,rear,top,index=0;
	front = rear = 0;
	countPack = 3;//物品数量------------------------根据物品个数修改
	queue = (int*)malloc(sizeof(int) * 100);
	struct Node *n;//根节点
	n = (struct Node*)malloc(sizeof(struct Node) * 100);
	n[index].lever = n[index].value = n[index].weight = n[index].no = 0;
	bound(n, index,weight, value, maxWeight);
	//让根节点入队
	queue[rear++] = n[index].no;
	while (front != rear)
	{
		//出队列元素
		top = queue[front];//拿到编号
		front++;
		//求左孩子上界,当前重量，价值，层数,编号
		n[2 * top + 1].no = n[top].no + 1;//编号
		n[2 * top + 1].lever = n[top].lever + 1;//层数
		n[2 * top + 1].weight = n[top].weight +weight[n[2 * top + 1].lever];//重量
		n[2 * top + 1].value = n[top].value + value[n[2 * top + 1].lever];//价值
		bound(n, 2 * top + 1, weight, value, maxWeight);
		//左孩子满足条件，入队列
		if (n[2 * top + 1].up > maxValue && n[2 * top + 1].weight <= maxWeight)
		{
			//当次左孩子已经时叶子节点，如果大于当前最优解，不入队(可入可不入，不入最好),修改最优解
			if (n[2 * top + 1].lever == countPack)
			{
				if (n[2 * top + 1].value > maxValue)
				{
					maxValue = n[2 * top + 1].value;
				}
			}
			else {
				queue[rear++] = n[2 * top + 1].no;
			}

		}
		////求右孩子上界,当前重量，价值，层数
		n[2 * top + 2].no = n[top].no + 2;//编号
		n[2 * top + 2].lever = n[top].lever + 1;//层数
		n[2 * top + 2].weight = n[top].weight; //重量
		n[2 * top + 2].value = n[top].value;//价值
		bound(n, 2 * top + 2, weight, value, maxWeight);
		//右孩子满足条件，入队列
		if (n[2 * top + 2].up > maxValue)
		{
			//当次右孩子已经时叶子节点，如果大于当前最优解，不入队(可入可不入，不入最好),修改最优解
			if (n[2 * top + 2].lever == countPack)
			{
				if (n[2 * top + 2].value > maxValue)
				{
					maxValue = n[2 * top + 2].value;
				}
			}
			else {
				queue[rear++] = n[2 * top + 2].no;
			}
		}
	}
	printf_s("最大价值是:%d ", maxValue);
}



//单源最短路径问题
void minPath()
{
	int data[MAX][MAX],dis[MAX];//二维矩阵存储顶点间距离
	int numEdge,numVer,x,y,w,temp;
	int queue[MAX], front, rear, top,path[MAX];
	front = rear = 0;
	printf("请输入图的点数量和边个数 ");
	scanf_s("%d%d", &numVer,&numEdge);
	//初始化图的权值
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			data[i][j] = INF;
			dis[j] = INF;
			path[j] = -1;
			if (i == j)
			{
				data[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < numEdge; i++)
	{
		printf("请输入每条边点的下标和权值: ");
		scanf_s("%d%d%d", &x, &y,&w);
		data[x][y] = w;
	}
	//开始求解,假设求下标0到其它点的最短距离
	queue[rear++] = 0;
	dis[0] = 0;
	while (front != rear)
	{
		//出队头元素
		top = queue[front++];
		for (int i = 0; i < numVer; i++)
		{
			//存在更短路径，将该点入队列。
			if (data[top][i] < INF&& i!=top && dis[top] + data[top][i] < dis[i])
			{
				dis[i] = dis[top] + data[top][i];
				path[i] = top;
				//如果不在队列，再入队。
				temp = 0;
				for (int j = front; j <= rear; j++)
				{
					if (queue[j] == i)
					{
						temp = 1;
						break;
					}
				}
				if (temp == 0)
				{
					queue[rear++] = i;
				}
			}
		}
	}
	//输出最短距离
	for (int i = 1; i < numVer; i++)
	{
		printf_s("%d",dis[i]);
	}
}

//求解下届
void getLow(struct task * t,int (* cost)[4])
{
	int sum = 0;
	for (int i = t->lever; i < 4; i++)
	{
		int min = 9999;
		for (int j = 0; j < 4; j++)
		{
			if (t->temp[j] == 0 && cost[i][j] < min)
			{
				min = cost[i][j];
			}
		}
		sum += min;
	}
	t->down = sum + t->cost;
}
//任务分配
void assign_Task()
{
	//设置每个人对应每个任务的成本
	int cost[4][4] = { 9,2,7,8,6,4,3,7,5,8,1,8,7,6,9,4 },front,rear;
	struct task queue[MAX],node1,node2,top;//队列
	//入队列根节点
	node1.lever = node1.cost = front =rear = 0;
	for (int i = 0; i < 4; i++)
	{
		node1.temp[i] = 0;//任务未分配
	}
	getLow(&node1, cost);
	queue[rear++] = node1;
	while (front != rear)
	{
		top = queue[front++];//出队
		//对下一人分配任务，
		for (int i = 0; i < 4; i++)
		{
			if (top.temp[i] == 0)//当前任务未被分配,将该任务分配给此人。
			{
				for (int j = 0; j < 4; j++)//复制temp到node2
				{
					node2.temp[j] = top.temp[j];
				}
				node2.temp[i] = 1;
				node2.lever = top.lever + 1;
				node2.cost = top.cost + cost[node2.lever][i];
				getLow(&node2, cost);//求下届
				if (node2.down < minCost)
				{
					if (node2.lever==3)//到达叶子节点
					{
						//for (int k = 0; k < 4; k++)
						//{
							//printf_s("%d ", node2.temp[k]);
						//}
						//printf_s("\n");
						minCost = node2.cost;
						//printf_s("%d\n", minCost);
						queue[rear++] = node2;
					}
					else {
						queue[rear++] = node2;
					}	
				}
			}
		}
	}
	printf_s("%d", minCost);
}


