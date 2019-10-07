/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）0-1背包的分支限界算法
 > 2）单源最短路径的分枝限界算法
 > 3）任务分配的分枝限界算法
 ************************************************************************/
#include "bound_Branch.h"
#include <iostream>
#include <queue>
using namespace std;
bound_Branch::bound_Branch()
{
	maxValue = -99999;
	countPack = 0;
	minCost = 99999;
}
void bound_Branch::bound(Node *n, int index, int maxWeight)
{
	int lever = n[index].lever;//当前节点层次
	int sumW = n[index].weight;
	int sumV = n[index].value;
	while (sumW <= maxWeight && lever<countPack)
	{
		sumW += w[lever];
		sumV += v[lever];
		lever++;
	}
	if (lever < countPack)//未能全部装
	{
		n[index].up = sumV + (maxWeight - sumW)*v[lever] / w[lever];
	}
	else {//全部装入
		n[index].up = sumV;
	}
}
//核心函数
void bound_Branch::package(int maxWeight)
{
	int count = 0,top, index = 0;
	countPack = 3;//物品数量------------------------根据物品个数修改
	queue<int> q;
	Node *n;//根节点
	n = (Node*)malloc(sizeof(Node) * 100);
	n[index].lever = n[index].value = n[index].weight = n[index].no = 0;
	bound(n, index,  maxWeight);
	//让根节点入队
	q.push(n[index].no);
	while (!q.empty())
	{
		//出队列元素
		top = q.front();//拿到编号
		q.pop();
		//求左孩子上界,当前重量，价值，层数,编号
		n[2 * top + 1].no = 2*n[top].no+1;//编号
		n[2 * top + 1].lever = n[top].lever + 1;//层数
		n[2 * top + 1].weight = n[top].weight + w[n[2 * top + 1].lever-1];//重量
		n[2 * top + 1].value = n[top].value + v[n[2 * top + 1].lever-1];//价值
		bound(n, 2 * top + 1,  maxWeight);
		//左孩子满足条件，入队列
		if (n[2 * top + 1].up > maxValue && n[2 * top + 1].weight <= maxWeight)
		{
			//当次左孩子已经时叶子节点，如果大于当前最优解，不入队(可入可不入，不入最好),修改最优解
			if (n[2 * top + 1].lever == countPack)
			{
				if (n[2 * top + 1].value > maxValue)
				{
					maxValue = n[2 * top + 1].value;
					q.push(n[2 * top + 1].no);
				}
			}
			else {
				q.push(n[2 * top + 1].no);
			}
		}
		////求右孩子上界,当前重量，价值，层数
		n[2 * top + 2].no = 2*n[top].no + 2;//编号
		n[2 * top + 2].lever = n[top].lever + 1;//层数
		n[2 * top + 2].weight = n[top].weight; //重量
		n[2 * top + 2].value = n[top].value;//价值
		bound(n, 2 * top + 2,  maxWeight);
		//右孩子满足条件，入队列
		if (n[2 * top + 2].up > maxValue && n[2 * top + 2].weight <= maxWeight)
		{
			//当次右孩子已经时叶子节点，如果大于当前最优解，不入队(可入可不入，不入最好),修改最优解
			if (n[2 * top + 2].lever == countPack)
			{
				if (n[2 * top + 2].value > maxValue)
				{
					maxValue = n[2 * top + 2].value;
					q.push(n[2 * top + 2].no);
				}
			}
			else {
				q.push(n[2 * top + 2].no);
			}
		}
	}
	cout << "最大价值是: " << maxValue << endl;
}

void bound_Branch::minPath()
{
	int data[MAX][MAX], dis[MAX];//二维矩阵存储顶点间距离
	int numEdge, numVer, x, y, w, temp;
	int queue[MAX], front, rear, top, path[MAX];
	front = rear = 0;
	printf("请输入图的点数量和边个数 ");
	scanf_s("%d%d", &numVer, &numEdge);
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
		scanf_s("%d%d%d", &x, &y, &w);
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
			if (data[top][i] < INF&& i != top && dis[top] + data[top][i] < dis[i])
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
		printf_s("%d", dis[i]);
	}
}

/*任务分配*/
void bound_Branch::assign_Task()
{
	//设置每个人对应每个任务的成本
	int cost[4][4] = { 9,2,7,8,6,4,3,7,5,8,1,8,7,6,9,4 }, front, rear;
	task queue[MAX], node1, node2, top;//队列
	//入队列根节点
	node1.lever = node1.cost = front = rear = 0;
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
				node2.cost = top.cost + cost[node2.lever-1][i];
				//cout << node2.cost << endl;
				getLow(&node2, cost);//求下届
				if (node2.down < minCost)
				{
					if (node2.lever == 4)//到达叶子节点
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
	
//求解下届
void bound_Branch::getLow(task * t, int(*cost)[4])
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