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
#ifndef BOUND_BRANCH_H
#define BOUND_BRANCH_H
#define MAX 100
#define INF 99999
//0-1背包
struct Node
{
	int no;//每个节点唯一的编号
	int lever;//当前节点所在的层
	int weight;//当前节点累加的重量
	int value;//当前节点累加的价值
	int up;//当前节点上界价值
};
//求当前节点的最大上界
void bound(struct Node *n,int index, int *weight, int *value, int maxWeight);
//核心函数
void package(int *weight,int *value,int maxWeight);
static int maxValue = -9999;
static int countPack = 0;



//求单源最短路径(无向和有向图都成立)
void minPath();


//任务分配
struct task
{
	int lever;
	int down;//下界最优成本
	int cost;//已经分配的成本
	int temp[MAX];//任务是否分配
};
void assign_Task();
//求解下届
void getLow(struct task * t, int(*cost)[4]);
static int minCost = 99999;
#endif // !BOUND_BRANCH_H

