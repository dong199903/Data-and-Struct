/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-02
 >
 > 1）计数排序
 > 2）桶排序
 > 3）基数排序
 ************************************************************************/
#include "Sort_3.h"
void main()
{
	int arr[10] = { 6,2,1,8,3,5,1,100,99,22 };
	//sort_Bucket(arr, 10);
	//sort_Count(arr, 10);
	//sort_Radix(arr, 10);-----排序失败
	arr_Print(arr, 10);
	system("pause");
}