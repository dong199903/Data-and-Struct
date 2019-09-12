/*************************************************************************
 > File Name: Sort.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-02
 >
 > 1）冒泡排序
 > 2）插入排序
 > 3）选择排序
 ************************************************************************/
#include "Sort_1.h"
#include <stdio.h>
void sort_Bubble(int* arr, int len)
{
	int temp,flag;
	for (int i = 0; i < len; i++)
	{
		flag = 1;
		for (int j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
			}
		}
		//一趟没发生交换，数据已经排序OK
		if (flag == 1)
		{
			return;
		}
	}
}
void sort_Insert(int* arr, int len)
{
	int data,index;
	for (int i = 1; i < len; i++)
	{
		data = arr[i];
		index = i-1;
		while (index >= 0 && data < arr[index])
		{
			
			arr[index+1] = arr[index];
			index--;
		}
		arr[index + 1] = data;
	}               
}
void sort_Chocie(int* arr, int len)
{
	int min,index;
	for (int i = 0; i < len; i++)
	{
		min = arr[i];
		index = i;
		for (int j = i +1 ; j < len; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				index = j;
			}
		}
		if (index!=i)
		{
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
}
void arr_Print(int* arr, int len)
{
	for (int j = 0; j < len; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
}