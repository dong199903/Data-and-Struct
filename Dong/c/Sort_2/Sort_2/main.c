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
#include "Sort_2.h"
void main()
{
	int arr[] = { 4,8,1,1,9,45,3,99,10,5 };
	//sort_Merge(arr, 0,9);
	//sort_Qucik(arr,0, 9);
	//sort_Shell(arr,10);
	sort_Heap(arr, 10);
	print(arr, 10);
	system("pause");
}