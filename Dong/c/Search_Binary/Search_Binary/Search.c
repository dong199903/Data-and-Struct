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
#include <stdio.h>
/*二分查找（找到一个目标数）*/
int Search_Binary1(int *arr,int len, int num)
{
	int low, high ,mid;
	low = 0, high = len - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		if (arr[mid] == num)
		{
			return mid;
		}
		else if (arr[mid] < num)
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
int Search_Binary2(int *arr, int len, int num)
{
	int low, high, mid;
	low = 0, high = len - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		if (arr[mid] == num)
		{
			if (mid == 0 || arr[mid - 1] != num)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		else if (arr[mid] < num)
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
int Search_Binary3(int *arr, int len, int num)
{
	int low, high, mid;
	low = 0, high = len - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		if (arr[mid] == num)
		{
			if (mid == len - 1 || arr[mid + 1] != num)
			{
				return mid;
			}
			else {
				low = mid + 1;
			}
		}
		else if (arr[mid] < num)
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
/*二分查找（找到第一个大于等于目标的数*/
int Search_Binary4(int *arr, int len, int num)
{
	int low, high, mid;
	low = 0, high = len - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		
		if (arr[mid] >= num)
		{
			if (mid == 0 || arr[mid - 1] < num)
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
int Search_Binary5(int *arr, int len, int num)
{
	int low, high, mid;
	low = 0, high = len - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{

		if (arr[mid] <= num)
		{
			if (mid == len-1 || arr[mid +1] > num)
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