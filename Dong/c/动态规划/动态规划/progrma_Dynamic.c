/*************************************************************************
 > File Name: program_Dynamic.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-10-06
 >
 > 1）最大连续子序列和
 > 2）三角形最短路径
 > 3）最长递增子序列
 > 4）0-1背包 
 > 5）完全背包
 ************************************************************************/
#include "program_Dynamic.h"
#include <stdio.h>

void maxSum()
{
	int data[] = { 0,-2,11,-4,13,-5,-2 };//0位置不用
	int len = sizeof(data) / sizeof(int);
	int *dp,max=-9999;
	dp = (int *)malloc(sizeof(int) * len);
	dp[0] = 0;
	for (int i = 1; i < len; i++)
	{
		if (dp[i - 1] + data[i] > data[i])
		{
			dp[i] = dp[i - 1] + data[i];
		}
		else
		{
			dp[i] = data[i];
		}
	}

	//直接找出dp数组最大，就是最大结果
	for (int i = 0; i < len; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	printf_s("最大连续子序列和是: %d", max);
}

//三角形最短路径
void minPath()
{
	int i, j, high,**data,**dp,**pre,min,index,num;
	printf_s("输入三角形的高度: ");
	scanf_s("%d", &high);
	data = (int **)malloc(sizeof(int *)*high);
	dp = (int **)malloc(sizeof(int *)*high);
	pre = (int **)malloc(sizeof(int *)*high);
	//输入三角形(二维数组里)
	for (i = 0; i < high; i++)
	{
		data[i] = (int *)malloc(sizeof(int) * high);
		dp[i] = (int *)malloc(sizeof(int) * high);
		pre[i] = (int *)malloc(sizeof(int) * high);
		for (j = 0; j <= i;j++)
		{
			scanf_s("%d", &data[i][j]);
		}
	}
	
	//初始化边界问题
	dp[0][0] = data[0][0];
	pre[0][0] = -1;
	for (i = 1; i < high; i++)
	{
		dp[i][i] = dp[i - 1][i - 1] + data[i][i];
		dp[i][0] = dp[i - 1][0] + data[i][0];
		pre[i][i] = i-1;
		pre[i][0] = 0;
	}
	//其它正常情况
	for (i = 1; i < high; i++)
	{
		for (j = 1; j < high; j++)
		{
			if (i != j &&j != 0)
			{
				if (dp[i - 1][j - 1] > dp[i - 1][j])
				{
					dp[i][j] = dp[i - 1][j] + data[i][j];
					pre[i][j] = j;
				}
				else {
					dp[i][j] = dp[i - 1][j-1] + data[i][j];
					pre[i][j] = j-1;
				}
			}
		}
	}
	//找出最短距离
	min = dp[high - 1][0];
	index = 0;
	for (i = 1; i < high; i++)
	{
		if (dp[high-1][i] < min)
		{
			min = dp[high-1][i];
			index = i;
		}
	}
	printf_s("最短距离是:%d它的路径是: ",min);
	num = high-1;
	while (num!=0)
	{
		printf("%d ",data[num][index]);
		index = pre[num][index];
		num--;	
	}
	printf_s("%d\n", data[0][0]);
}


//最长递增子序列
void maxLen()
{
	int len, *data,i,j,*dp,max;
	printf_s("输入你的数组长度: ");
	scanf_s("%d", &len);
	data = (int *)malloc(sizeof(int) * len);
	dp = (int *)malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
	{
		scanf_s("%d", &data[i]);
	}
	for (i = 0; i < len; i++)
	{
		dp[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (data[j] < data[i])
			{
				if (dp[j] + 1 > dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	max = dp[0];
	//找出最大长度
	for (i = 1; i < len; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	printf_s("%d", max);
}


//0-1背包
void package()
{
	int w[] = { 2,2,6,5,4 };
	int v[] = { 6,3,5,4,6 };
	int len = 5, maxWeight = 10,i,j,weight;//dp数组存储结果
	int dp[MAX][MAX];
	weight = maxWeight;//weight存储当前背包剩余容量
	for (i = 0; i < len; i++)
	{
		dp[i][0] = 0;
	}
	for (i = 0; i <= weight; i++)
	{
		if (w[0] <= i)//第一个物品是边界值，
		{
			dp[0][i] = v[0];
		}
		else
		{
			dp[0][i] = 0;
		}
	}
	
	for (i = 1; i < len; i++)
	{
		for (j = 0; j <= weight; j++)
		{
			//是否可以放下第i个物品
			if (j >= w[i])
			{
				if (dp[i - 1][j] > dp[i - 1][j - w[i]] + v[i])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - w[i]] + v[i];
				}
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (i = 0; i < len; i++)
	{
		for (j = 0; j <= weight; j++)
		{
			printf_s("%d ", dp[i][j]);
		}
		printf_s("\n");
	}
	printf_s("最大价值%d\n",dp[4][10]);
	//逆序推导选择的物品
	len--;
	while (len > 0)
	{
		if (dp[len][weight] != dp[len - 1][weight])//选择物品len
		{
			printf_s("物品%d被选中\n", len+1);
			weight -= w[len];
		}
		len--;
	}
	if(weight!=0)
	{
	        printf_s("物品%d被选中\n", len+1);
	}
}

//完全背包
void full_Pack()
{
	int weight[] = {3, 4, 2};
	int value[] = { 4,5,3 };
	int len = 3, maxWeight = 7;
	int dp[MAX][MAX],i,j,k,max,count[MAX][MAX];
	//初始化边界
	for (i = 0; i < len; i++)
	{
		dp[i][0] = 0;
	}
	for (i = 0; i <= maxWeight; i++)
	{
		for (k = 0; k*weight[0] <= i; k++)//背包容量足够，放入物品0越多，价值越大。
		{
			dp[0][i] = k*value[0];
			count[0][i] = k;
		}
	}
	//开始
	for (i = 1; i < len; i++)
	{
		for (j = 1; j <= maxWeight; j++)
		{
			max = dp[i][0];
			dp[i][j] = max;
			count[i][j] = 0;
			for (k = 0; k*weight[i] <= j; k++)
			{
				if (dp[i - 1][j - weight[i] * k] + value[i] * k > max)
				{
					max = dp[i - 1][j - weight[i] * k] + value[i] * k;
					dp[i][j] = max;
					count[i][j] = k;
				}
			}
		}
	}
	printf_s("最大价值: %d\n", dp[2][7]);
	//输出选择物品
	len--;
	while (len >= 0)
	{
		printf_s("%d %d\n", len + 1, count[len][maxWeight]);
		maxWeight -= weight[len] * count[len][maxWeight];
		len--;
	}
}