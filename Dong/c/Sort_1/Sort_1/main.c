/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-02
 >
 > 1）冒泡排序
 > 2）插入排序
 > 3）选择排序
 ************************************************************************/
#include "Sort_1.h"
void main()
{
	int arr[10] = { 3,5,2,1,9,10,55,2,3,8 };
	sort_Bubble(arr, 10);
	arr_Print(arr, 10);
	sort_Chocie(arr, 10);
	arr_Print(arr, 10);
	sort_Insert(arr, 10);
	arr_Print(arr, 10);
	system("pause");
}