/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-13
 >
 > 1）归并排序
 > 2）快速排序
 > 3）希尔排序
 ************************************************************************/
#include "sort.h"
#include <iostream>
using namespace std;
void main()
{
	int arr[] = { 4,8,1,1,9,45,3,99,10,5 };
	sort_Heap(arr, 10);
	print(arr,10);
	system("pause");
}