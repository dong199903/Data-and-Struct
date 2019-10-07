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
#include "program_Dynamic.h"
#include <iostream>
using namespace std;
//最大连续子序列和
void program_Dynamic::maxSum()
{
	int data[] = { 0,-2,11,-4,13,-5,-2 };//0位置不用
	int len = sizeof(data) / sizeof(int);
	int *dp, max = -9999;
	dp = new int[len];
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
	cout<<"最大连续子序列和是: "<<max;
}

//三角形最短路径
void program_Dynamic::minPath()
{
	int i, j, high, **data, **dp, **pre, min, index, num;
	cout<<"输入三角形的高度: ";
	cin>>high;
	data = new int*[high];
	dp = new int*[high];
	pre = new int*[high];
	//输入三角形(二维数组里)
	for (i = 0; i < high; i++)
	{
		data[i] = new int[high];
		dp[i] = new int[high];
		pre[i] = new int[high];
		for (j = 0; j <= i; j++)
		{
			cin>>data[i][j];
		}
	}

	//初始化边界问题
	dp[0][0] = data[0][0];
	pre[0][0] = -1;
	for (i = 1; i < high; i++)
	{
		dp[i][i] = dp[i - 1][i - 1] + data[i][i];
		dp[i][0] = dp[i - 1][0] + data[i][0];
		pre[i][i] = i - 1;
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
					dp[i][j] = dp[i - 1][j - 1] + data[i][j];
					pre[i][j] = j - 1;
				}
			}
		}
	}
	//找出最短距离
	min = dp[high - 1][0];
	index = 0;
	for (i = 1; i < high; i++)
	{
		if (dp[high - 1][i] < min)
		{
			min = dp[high - 1][i];
			index = i;
		}
	}
	cout<<"最短距离是"<<min<<"它的路径是: ";
	num = high - 1;
	while (num != 0)
	{
		cout<<data[num][index]<<" ";
		index = pre[num][index];
		num--;
	}
	cout<<data[0][0]<<"\n";
}

//最长递增子序列
void program_Dynamic::maxLen()
{
	int len, *data, i, j, *dp, max;
	cout<<"输入你的数组长度: ";
	cin>>len;
	data = new int[len];
	dp = new int[len];
	for (i = 0; i < len; i++)
	{
		cin>>data[i];
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
	cout<< max;
}

//0-1背包
void program_Dynamic::package()
{
	int w[] = { 2,2,6,5,4 };
	int v[] = { 6,3,5,4,6 };
	int len = 5, maxWeight = 10, i, j, weight;//dp数组存储结果
	int dp[MAX][MAX];
	weight = maxWeight;//weight存储当前背包剩余容量
	for (i = 0; i < len; i++)
	{
		dp[i][0] = 0;
	}
	for (i = 0; i <= weight; i++)
	{
		if (w[0] <= i)
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
	len = len - 1;
	//cout << "最大价值" << dp[4][10];
	printf_s("背包最大价值是: %d", dp[4][10]);
	while (len > 0)
	{
		if (dp[len][weight] != dp[len - 1][weight])
		{
			cout<<"物品被选中"<<(len + 1)<<endl;
			weight -= w[len];
		}
		len--;
	}
	if (weight != 0)
	{
		cout << "物品被选中" << (len + 1) << endl;
	}
}

//完全背包
void program_Dynamic::full_Pack()
{
	int weight[] = { 3, 4, 2 };
	int value[] = { 4,5,3 };
	int len = 3, maxWeight = 7;
	int dp[MAX][MAX], i, j, k, max, count[MAX][MAX];
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