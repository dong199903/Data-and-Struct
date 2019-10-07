/*************************************************************************
 > File Name: greedy.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-10-03
 >
 > 1）0-1背包问题的贪心算法
 > 2）活动安排问题的贪心算法
 > 3）最优装载的贪心算法
 ************************************************************************/
#ifndef GREEDY_H
#define GREEDY_H
//0-1背包
void back_Pack();

struct plan
{
	int begin;
	int last;
};
//活动安排
void plan_Acivity();
//最优装载
void load();

#endif // !GREEDY_H