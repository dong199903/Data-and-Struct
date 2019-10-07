/*************************************************************************
 > File Name: Baxk_Tracking.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-29
 >
 > 1）包含了回溯算法的几大经典题目，通过子集树和排列树的划分进行回溯
 > 2）幂集问题
 > 3）马兵炮问题
 > 4）0-1背包问题
 > 5）最优装载问题
 > 6）全排列问题
 > 7）任务分配问题
 > 8）活动安排问题
 > 9）N皇后问题-----------简易版
 ************************************************************************/
#include "Back_Tracking.h"
#include <stdio.h>
/*
幂集问题
arr1数组是数据
arr2数组保存结果
len代表子集树高度，也是数组arr1长度
index代表当前回溯的层数
*/
void Get_Power_Set(int *arr1, int *arr2, int len, int index)
{
	//回溯到叶子时，直接打印幂集
	if (index >= len)
	{
		printf("( ");
		for (int i = 0; i < len; i++)
		{
			if (arr2[i] != 0)
			{
				printf("%d ", arr2[i]);
			}
		}
		printf(")\n");
	}
	else
	{
		//选择这个数字
		arr2[index] = arr1[index];
		Get_Power_Set(arr1, arr2, len, index + 1);
		//不选择这个数字
		arr2[index] = 0;
		Get_Power_Set(arr1, arr2, len, index + 1);
	}
}



//象棋算法
void play_Chess()
{
	int temp[10];//代表当前下标对应数字是否使用
	for (int i = 0; i < 10; i++)
	{
		temp[i] = 0;
	}

	//开始计算
	for (int a = 1; a < 10; a++)//----------棋子炮
	{
		temp[a] = 1;
		for (int b = 0; b < 10; b++)//----------棋子马
		{
			if (temp[b] == 0)
			{
				temp[b] = 1;
				for (int c = 0; c < 10; c++)//----------棋子车
				{
					if (temp[c] == 0)
					{
						temp[c] = 1;
						int x, y, z;
						x = b * 10 + c;
						y = c * 10 + a;
						z = a * 100 + a * 10 + b;
						if (x + y == z)
						{
							printf("炮:%d 马:%d 车%d\n", a, b, c);
						}
					}
					temp[c] = 0;
				}
			}
			temp[b] = 0;
		}
		temp[a] = 0;
	}
}

//0-1背包问题
/*
resule数组保存解，物品编号
w数组保存物品对应重量
v数组保存物品对应价值
sunW保存当前物品总重量
sumV保存当前物品总价值
index代表树扩展第几层
len代表物品个数，也代表树层数
*/
void backpack_01(int *result, int *w, int *v, int sumW, int sumV,int index,int len)
{
	//如果扩展到叶子节点
	if (index >= len)
	{
		//如果符合条件，就输出最优解
		if (sumW == weight)
		{
			for (int i = 0; i < len; i++)
			{
				if (result[i] != -1)
				{
					printf("物品编号: %d\n", i + 1);
				}
			}
			printf("总重量是: %d,最大价值是: %d\n",sumW, sumV);
		}
	}
	else
	{
		if (sumW + w[index] <= weight)
		{
			sumWeight -= w[index];
			result[index] = index;
			backpack_01(result, w, v, sumW+w[index], sumV+v[index], index + 1, len);
		}
		if (sumW + sumWeight >= weight)
		{
			result[index] = -1;//不选择
			sumWeight += w[index];
			backpack_01(result, w, v, sumW, sumV, index + 1, len);
		}	
	}
}

//最优装载问题
/*
result数组存储的是装载信息
w数组保存每个货物重量
sumW是当前货物总重量
index代表扩展第几层
len代表货物总个数
maxWeight是轮船最大承受量
*/
void optimal(int *result, int *w, int sumW, int index, int len,int maxWeight)
{
	if (index >= len)
	{
		int count=0;
		for (int i = 0; i < len; i++)
		{
			if (result[i] != 0)
			{
				count++;
				printf("货物%d被选\n", i+1);
			}
		}
		printf("总个数%d\n",count);
	}
	else 
	{
		if (sumW + w[index] <= maxWeight)
		{
			result[index] = 1;
			optimal(result, w, sumW + w[index], index+1, len, maxWeight);
		}
		result[index] = 0;
		optimal(result, w, sumW, index + 1, len, maxWeight);
	}
}


void sort_All(int *data,int index, int len)
{
	if (index >= len)
	{
		printf_s("( ");
		for (int i = 0; i < len; i++)
		{
			printf("%d ", data[i]);
		}
		printf_s(")  ");
	}
	else {
		for (int i = index; i < len; i++)
		{
			//交换数据
			int temp = data[i];
			data[i] = data[index];
			data[index] = temp;
			sort_All(data, index + 1, len);
			//恢复数据
			temp = data[i];
			data[i] = data[index];
			data[index] = temp;

		}
	}
}


void task_Assign(int *data, int len, int index, int (*task)[4])
{
	if (index >= len)
	{
		int sum=0;
		//处理排列的数据
		for (int i = 0; i < len; i++)
		{
			sum += task[i][data[i]-1];
		}
		if (sum < minCost)
		{
			minCost = sum;
		}
	}
	else {
		for (int i = index; i < len; i++)
		{
			int temp = data[i];
			data[i] = data[index];
			data[index] = temp;
			task_Assign(data, len, index + 1,task);
			temp = data[i];
			data[i] = data[index];
			data[index] = temp;
		}
	}
}


void plan_Activity(struct task * t, int *data, int index, int len)
{
	if (index >= len)
	{
		int count = 1,last;
		//进行活动安排个数的统计,打印每个活动的顺序
		last = t[data[0]-1].end;//结束时间
		for (int i = 1; i < len; i++)
		{
			if (t[data[i]-1].begin >= last)
			{
				count++;
				last = t[data[i]-1].end;
			}
		}
		if (count > maxCount)
		{
			maxCount = count;
		}
	}
	else {
		for (int i = index; i < len; i++)
		{
			int temp = data[index];
			data[index] = data[i];
			data[i] = temp;
			plan_Activity(t, data, index + 1, len);
			temp = data[index];
			data[index] = data[i];
			data[i] = temp;
		}
	}
}


