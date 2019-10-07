/*************************************************************************
 > File Name: Sort.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-11
 >
 > 1）计数排序
 > 2）桶排序
 > 3）基数排序
 > 4）按f9设置断点-->点击本地windows调试器-->点击调式栏的逐语句或逐过程-->查找错误
 ************************************************************************/
#include "Sort.h"
#include <iostream>
using namespace std;
template<class T>
Sort<T>::Sort(int len)
{
	this->len = len;
	this->arr = new T[this->len];
}

//计数排序
/*
1.找出待排序数组arr1的最大和最小值
2.根据最小值到最大值创建数组arr2，按下标存储盖下标出现的次数
3.将数组arr2进行前缀相加
4.创建数组arr3,逆序遍历原数组arr1，按照其值找到对应的arr2下标，找到对应值，存放在arr3中
5.对应arr2位置的数字-1
6.arr3中的数字就是最终结果
*/
template<class T>
void Sort<T>::sort_Count()
{
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
}


//桶排序
/*
1.确定桶的映射关系hash = (e*length)/(max + 1)）
2.遍历待排序数组，逐个按照映射关系入桶
3.逐个取出桶数据，排序完成
*/
template<class T>
void Sort<T>::sort_Bucket()
{
	int i,j;
	T max, hash;
	Node<T> *table,*p, *q, *temp;
	max = arr[0];
	table = new Node<T>[this->len];//桶
	for (i = 1; i < this->len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		table[i].next = NULL;//初始化桶
	}
	table[0].next = NULL;
	//遍历数组，分别入桶
	for (i = 0; i < this->len; i++)
	{
		hash = (arr[i] * this->len) / (max + 1);
		if (table[hash].next == NULL)
		{
			temp = new Node<T>;
			temp->data = this->arr[i];
			temp->next = table[hash].next;
			table[hash].next = temp;
		}
		else
		{
			temp = new Node<T>;
			temp->data = this->arr[i];
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
	for (i = 0; i < this->len; i++)
	{
		p = table[i].next;
		while (p != NULL)
		{
			this->arr[j++] = p->data;
			p = p->next;
		}
	}
}



//基数排序
/*
1.找出待排序数据的最大值，确定其位数
2.从最低位个位开始到最高位数，逐个按照对应数字入队，再取出，重复
3.最后一次取出的数据就是有序的
*/
template<class T>
void Sort<T>::sort_Radix()
{
	//1.找出最大数
	T max,temp;
	int i,count,j,index,num,biaoji;
	max = this->arr[0];
	for (i = 0; i < this->len; i++)
	{
		if (this->arr[i] > max)
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
	Array<T> * array = new Array<T>[10];//存放0--9的桶
	for (i = 0; i < 10; i++)
	{
		array[i].data = new T[this->len];//每个桶的最大容量就是待排序数据
		array[i].len = 0;//每个桶里面数据暂时为空
	}
	
	for (i = 1; i <= count; i++)
	{
		//数据逐个放入对应的桶
		for (j = 0; j < this->len; j++)
		{
			index = 0;//标记第i位
			temp = this->arr[j];
			while (temp != 0 && index < i)
			{
				num = temp % 10;//保存第i位数据
				temp = temp / 10;
				index++;
			}
			if (temp == 0)
			{
				num = 0;//第i位的数据是0
			}
			//放在对应下标的桶里面
			array[num].data[array[num].len++] = this->arr[j];
		}
		//取出逐个桶数据，归位
		this->len = 0;
		
		for (j = 0; j < 10; j++)
		{
			biaoji = 0;
			while (array[j].len != 0)
			{
				this->arr[this->len++] = array[j].data[biaoji++];
				array[j].len--;
			}
		}
	}
	for (i = 0; i < this->len; i++)
	{
		cout << this->arr[i] << " ";
	}
}




template<class T>
void Sort<T>::print()
{
	for (int j = 0; j < this->len; j++)
	{
		cout << this->arr[j] << " ";
	}
	cout << "\n";
}


template<class T>
istream &operator >> (istream &os, Sort<T> &s)
{
	for (int i = 0; i < s.len; i++)
	{
		os >> s.arr[i];
	}
	return os;
}