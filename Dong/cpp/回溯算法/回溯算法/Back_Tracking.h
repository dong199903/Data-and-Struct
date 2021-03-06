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
#ifndef BACK_TRACKING_H
#define BACK_TRACKING_H
 //求数列的幂级-递归实现
void Get_Power_Set(int *arr1, int *arr2, int len, int index);
//求解马兵炮问题
void play_Chess();
//0-1背包问题
void backpack_01(int *result, int *w, int *v, int sumW, int sumV, int index, int len);
extern int weight;//背包最大容量
extern int sumWeight;//所有物品重量和
extern int maxValue;//最大价值
//最优装载问题--尽可能多的货物被装上
void optimal(int *result, int *w, int sumW, int index, int len, int maxWeight);
//全排列
void sort_All(int *data, int index, int len);
//求解任务分配
void task_Assign(int *data, int len, int index, int (* task)[4]);
extern int minCost;
/*活动安排*/
class task
{
public:
	int begin;
	int end;
};
extern int maxCount;
void plan_Activity(struct task * t, int *data, int index, int len);
#endif // !BACK_TRACKING_H

