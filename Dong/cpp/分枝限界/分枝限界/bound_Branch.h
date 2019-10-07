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
#ifndef BOUND_BRANCH_H
#define BOUND_BRANCH_H
#define MAX 100
#define INF 99999
class Node
{
public:
	int no;//每个节点唯一的编号
	int lever;//当前节点所在的层
	int weight;//当前节点累加的重量
	int value;//当前节点累加的价值
	int up;//当前节点上界价值
};
class task
{
public:
	int lever;
	int down;//下界最优成本
	int cost;//已经分配的成本
	int temp[MAX];//任务是否分配
};
class bound_Branch
{
public:
	/*------------------0-1背包---------------------*/
	int maxValue;
	int countPack;
	int w[3] = { 16,15,15 };
	int v[3] = { 45,25,25 };
	bound_Branch();
	//求当前节点的最大上界
	void bound(Node *n, int index,int maxWeight);
	//核心函数
	void package(int maxWeight);


	/*------------------单源最短路径-----------------*/
	void minPath();//无向图和有向图都成立

	/*------------------任务分配---------------------*/
	void assign_Task();
	//求解下届
	void getLow(task * t, int(*cost)[4]);
	int minCost;
};
#endif // !BOUND_BRANCH_H

