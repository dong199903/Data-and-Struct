/*************************************************************************
 > File Name: greedy.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-10-03
 >
 > 1）0-1背包问题的贪心算法
 > 2）活动安排问题的贪心算法
 > 3）最优装载的贪心算法
 ************************************************************************/
#include <iostream>
using namespace std;
#include "greedy.h"
//背包问题--每个物品可以取出一部分,要求最大价值
void back_Pack()
{
	double sumW = 100, sumV = 0;//背包最大容量100kg
	double weight[] = { 100,30,60,20,50 };
	double value[] = { 100,90,120,80,75 };
	int temp[5] = { 0 }, index;//标记当前物品选择与否
	double bi[5] = { 0 }, maxBi;//性价比
	for (int i = 0; i < 5; i++)
	{
		bi[i] = value[i] * 1.0 / weight[i];
	}
	//开始挑选物品
	for (int i = 0; i < 5; i++)
	{
		maxBi = -9999;
		//挑选当前未选的物品性价比最大的
		for (int j = 0; j < 5; j++)
		{
			if (temp[j] == 0 && bi[j] > maxBi)
			{
				maxBi = bi[j];
				index = j;
			}
		}
		//背包容量不足
		if (sumW <= 0)
		{
			break;
		}
		//背包容量足
		temp[index] = 1;
		if (sumW >= weight[index])
		{
			sumW -= weight[index];//全部放入
			sumV += value[index];
		}
		else {
			sumV += bi[index] * sumW;
			sumW = 0;//容量不足，放入一部分
		}
	}
	//输出最大价值
	printf_s("%lf", sumV);
}


//活动安排--最多个数
void plan_Acivity()
{
	struct plan s[11] = { { 2,5 },{ 4,8 },{ 6,10 },{ 1,3 } };
	struct plan temp;
	int sum = 0;
	//按照活动开始时间排序
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i - 1; j++)
		{
			if (s[j].begin > s[j + 1].begin)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	//开始逐个安排活动
	temp = s[0];
	sum++;
	for (int i = 1; i < 4; i++)
	{
		if (s[i].begin > temp.last)//判断次活动是否可以安排
		{
			sum++;
			temp = s[i];
		}

	}
	printf_s("%d", sum);
}

//最优装载--最多物品
void load()
{
	int weight[5] = { 5,2,6,4,3 }, temp, maxW = 10;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i - 1; j++)
		{
			if (weight[j] > weight[j + 1])
			{
				temp = weight[j];
				weight[j] = weight[j + 1];
				weight[j + 1] = temp;
			}
		}
	}
	//开始逐个装载
	for (int i = 0; i < 5; i++)
	{
		if (maxW - weight[i] > 0)
		{
			printf_s("%d\n", weight[i]);
			maxW -= weight[i];
		}
	}
}
