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
	for (int a = 1; a < 10; a++)//----------棋子兵
	{
		temp[a] = 1;
		for (int b = 0; b < 10; b++)//----------棋子炮
		{
			if (temp[b] != 1)
			{
				temp[b] = 1;
				for (int c = 0; c < 10; c++)//----------棋子马
				{
					if (temp[c] != 1)
					{
						temp[c] = 1;
						for (int d = 0; d < 10; d++)//----------棋子卒
						{
							if (temp[d] != 1)
							{
								temp[d] = 1;
								for (int e = 0; e < 10; e++)//----------棋子车
								{
									if (temp[e] != 1)
									{
										temp[e] = 1;
										int x1, x2, x3;
										x1 = 1000 * a + 100 * b + 10 * c + d;
										x2 = 100 * a + 100 * b + 10 * e + d;
										x3 = 10000 * e + 1000 * d + 100 * c + 10 * a + b;
										if (x1 + x2 == x3)
										{
											printf("兵:%d  炮:%d  马:%d  卒:%d  车:%d\n", a, b, c, d, e);
										}
										temp[e] = 0;//关键的回溯上一步
									}
								}
								temp[d] = 0;
							}
						}
						temp[c] = 0;
					}
				}
				temp[b] = 0;
			}	
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
	printf("%d %d %d\n", weight, sumWeight, maxValue);
	//如果扩展到叶子节点
	if (index >= len)
	{
		//如果符合条件，就输出最优解
		if (sumW == weight && sumV>maxValue)
		{
			maxValue = sumV;
			for (int i = 0; i < len; i++)
			{
				if (result[i] != 0)
				{
					printf("物品编号: %d\n", i + 1);
				}
			}
			printf("总重量是: %d,最大价值是: %d\n",weight, maxValue);
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
		if (sumWeight + sumW > weight)
		{
			sumWeight -= w[index];
			result[index] = 0;//不选择
			backpack_01(result, w, v, sumW, sumV, index + 1, len);
		}
	}
}