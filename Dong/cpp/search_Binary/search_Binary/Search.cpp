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
 /*************************************************************************
 > File Name: Search.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-03
 >
 > 1）二分查找（找到一个目标数）
 > 2）二分查找（找到第一个等于目标的数）
 > 3）二分查找（找到最后一个等于目标的数）
 > 4）二分查找（找到第一个大于等于目标的数）
 > 5）二分查找（找到最后一个小于等于目标的数）
 ************************************************************************/
#include "Search.h"
#include <iostream>
using namespace std;

Array::Array()
{
	cout << "输入数据个数: ";
	cin >> this->len;
	this->data = new int[len];
	cout << "输入你的数据: ";
	for (int i = 0; i < len; i++)
	{
		cin >> this->data[i];
	}
}
void Array::print()
{
	for (int i = 0; i < len; i++)
	{
		cout << this->data[i] <<" ";
	}
	cout << endl;
}
int Array::Search_Binary1(int num)
{
	int low, high, mid;
	low = 0, high = this->len - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (data[mid] == num)
		{
			return mid;
		}
		else if (data[mid] < num)
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

/*二分查找（找到第一个等于目标的数）*/
int Array::Search_Binary2(int num)
{
	int low, high, mid;
	low = 0, high = len - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (data[mid] == num)
		{
			if (mid == 0 || data[mid - 1] != num)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		else if (data[mid] < num)
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

/*二分查找（找到最后一个等于目标的数）*/
int Array::Search_Binary3(int num)
{
	int low, high, mid;
	low = 0, high = len - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (data[mid] == num)
		{
			if (mid == len - 1 || data[mid + 1] != num)
			{
				return mid;
			}
			else {
				low = mid + 1;
			}
		}
		else if (data[mid] < num)
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
/*二分查找（找到第一个大于等于目标的数)*/
int Array::Search_Binary4(int num)
{
	int low, high, mid;
	low = 0, high = len - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;

		if (data[mid] >= num)
		{
			if (mid == 0 || data[mid - 1] < num)
			{
				return mid;
			}
			else {
				high = mid - 1;
			}
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

/*二分查找（找到最后一个小于等于目标的数）*/
int Array::Search_Binary5(int num)
{
	int low, high, mid;
	low = 0, high = len - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;

		if (data[mid] <= num)
		{
			if (mid == len - 1 || data[mid + 1] > num)
			{
				return mid;
			}
			else {
				low = mid + 1;
			}
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}