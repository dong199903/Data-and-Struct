/*************************************************************************
 > File Name: Sort.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-10
 >
 > 1）实现了冒泡排序
 > 2）实现了选择排序
 > 3）实现了插入排序
 >
 > 4）发现重大模板类输出输入运算符重载编译问题
 > 5）解决办法：
 > 6）一：在上面加上一行模板头即可
 > 7）二：声明时使用  friend ostream& operator<< <>(ostream& os, const Stack<T>&) 可以解决。
 ************************************************************************/
#include "Sort.h"
template<class T>
Sort<T>::Sort(int len)
{
	this->len = len;
	this->arr = new T[this->len];
}

template<class T>
void Sort<T>::sort_Bubble()
{
	int  flag;
	T temp;
	for (int i = 0; i < this->len; i++)
	{
		flag = 1;
		for (int j = 0; j < this->len - i - 1; j++)
		{
			if (this->arr[j] > this->arr[j + 1])
			{
				temp = this->arr[j];
				this->arr[j] = this->arr[j + 1];
				this->arr[j + 1] = temp;
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


template<class T>
void Sort<T>::sort_Choice()
{
	int index;
	T min;
	for (int i = 0; i < this->len; i++)
	{
		min = arr[i];
		index = i;
		for (int j = i + 1; j < this->len; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				index = j;
			}
		}
		if (index != i)
		{
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
}


template<class T>
void Sort<T>::sort_Insert()
{
	int  index;
	T data;
	for (int i = 1; i < this->len; i++)
	{
		data = arr[i];
		index = i - 1;
		while (index >= 0 && data < arr[index])
		{

			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = data;
	}
}


template<class T>
void Sort<T>::print()
{
	for (int j = 0; j < this->len; j++)
	{
		cout << this->arr[j] << " ";
	}
	cout<<"\n";
}


template<class T>
istream &operator >> (istream &os,Sort<T> &s)
{
	for (int i = 0; i < s.len; i++)
	{
		os >> s.arr[i];
	}
	return os;
}