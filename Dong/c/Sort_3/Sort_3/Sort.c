/*************************************************************************
 > File Name: Sort.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-02
 >
 > 1）计数排序
 > 2）桶排序
 > 3）基数排序
 ************************************************************************/
#include "Sort_3.h"
#include <stdio.h>
/*
桶排序
1.确定桶的映射关系hash = (e*length)/(max + 1)）,桶个数就是数据个数
2.遍历待排序数组，逐个按照映射关系入桶
3.逐个取出桶数据，排序完成
*/
void sort_Bucket(int *arr, int len)
{
	int i, j;
	int max, hash;
	struct Node *table, *p, *q, *temp;
	max = arr[0];
	table = (struct Node *)malloc(sizeof(struct Node) * len);
	for (i = 1; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		table[i].next = NULL;//初始化桶
	}
	table[0].next = NULL;
	//遍历数组，分别入桶
	for (i = 0; i < len; i++)
	{
		hash = (arr[i] * len) / (max + 1);
		if (table[hash].next == NULL)
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			temp->data = arr[i];
			temp->next = table[hash].next;
			table[hash].next = temp;
		}
		else
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			temp->data = arr[i];
			q = &table[hash];
			p = table[hash].next;
			while (p != NULL && p->data <= temp->data)
			{
				q = q->next;
				p = p->next;
			}
			if (p == NULL)
			{
				temp->next = p;
				q->next = temp;
			}
			else {
				temp->next = p;
				q->next = temp;
			}
		}
	}
	//遍历桶，取出数据
	j = 0;
	for (i = 0; i < len; i++)
	{
		p = table[i].next;
		while (p != NULL)
		{
			arr[j++] = p->data;
			p = p->next;
		}
	}
}
/*
计数排序

1.找出待排序的数组中最大和最小的元素；

2.统计数组中每个值为i的元素出现的次数，存入数组C的第i项；

3.对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；

4.反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1

*/
void sort_Count(int *arr, int len)
{
	/*
	T min, max;
	int i;
	min = this->arr[0];
	max = this->arr[0];
	//找最小和最大值
	for (i = 1; i < this->len; i++)
	{

	if (arr[i] < min)
	{
	min = arr[i];
	}
	if (arr[i] > max)
	{
	max = arr[i];
	}
	}
	//按最小值和最大值创建数组
	T *arr2 = new T[max - min + 1];
	T num = 0 - min;//关键的一个数字
	for (i = 0; i < max - min + 1; i++)
	{
	arr2[i] = 0;
	}
	for (i = 0; i < this->len; i++)
	{
	arr2[this->arr[i] + num]++;
	}
	//将数组前缀相加
	for (i = 1; i < max - min + 1; i++)
	{
	arr2[i] = arr2[i] + arr2[i - 1];
	}
	//创建arr3,逆序遍历原数组，按值找到temp数组位置
	T *arr3 = new T[this->len];
	for (i = this->len - 1; i >= 0; i--)
	{
	T index;//标记arr2数组下标
	index = this->arr[i] + num;
	arr3[arr2[index] - 1] = this->arr[i];
	arr2[index]--;
	}
	delete [] this->arr;
	this->arr = NULL;
	this->arr = arr3;
	*/
	int min, max;
	int i;
	min = arr[0];
	max = arr[0];
	//找最小和最大值
	for (i = 1; i < len; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//按最小值和最大值创建数组
	int *arr2 = (int *)malloc(sizeof(int)*(max - min + 1));
	int num = 0 - min;//关键的一个数字
	for (i = 0; i < max - min + 1; i++)
	{
		arr2[i] = 0;
	}
	for (i = 0; i < len; i++)
	{
		arr2[arr[i] + num]++;
	}
	//将数组前缀相加
	for (i = 1; i < max - min + 1; i++)
	{
		arr2[i] = arr2[i] + arr2[i - 1];
	}
	//创建arr3,逆序遍历原数组，按值找到temp数组位置
	int *arr3 = (int *)malloc(sizeof(int) *len);
	for (i = len - 1; i >= 0; i--)
	{
		int index;//标记arr2数组下标
		index = arr[i] + num;
		arr3[arr2[index] - 1] = arr[i];
		arr2[index]--;
	}
	//arr = arr3;
	for (i = 0; i < len; i++)
	{
		arr[i] = arr3[i];
	}
	free(arr3);
	arr3 = NULL;
}



/*
基数排序
*/
void sort_Radix(int *arr, int len)
{
	//1.找出最大数
	int max, temp;
	int i, count, j, index, num, biaoji;
	max = arr[0];
	for (i = 0; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//2.确定最大数的位数
	count = 0;
	while (max != 0)
	{
		max = max / 10;
		count++;
	}
	//3.从最低位开始逐个放数据，取数据
	struct Array  * array = (struct Array *)malloc(sizeof(struct Array) * 10);//存放0--9的桶
	for (i = 0; i < 10; i++)
	{
		array[i].data = (int *)malloc(sizeof(int)*len); //每个桶的最大容量就是待排序数据
		array[i].len = 0;//每个桶里面数据暂时为空
	}

	for (i = 1; i <= count; i++)
	{
		//数据逐个放入对应的桶
		for (j = 0; j < len; j++)
		{
			index = 0;//标记第i位
			temp = arr[j];
			while (temp != 0 && index < i)
			{
				num = temp % 10;//保存第i位数据
				temp = temp / 10;
				index++;
			}
			if (temp == 0)
			{
				num = 0;
			}
			//放在对应下标的桶里面
			array[num].data[array[num].len++] = arr[j];
		}
		//取出逐个桶数据，归位
		len = 0;
		for (j = 0; j < 10; j++)
		{
			biaoji = 0;
			while (array[j].len != 0)
			{
				arr[len++] = array[j].data[biaoji++];
				array[j].len--;
			}
		}
	}
}


//输出数组
void arr_Print(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}