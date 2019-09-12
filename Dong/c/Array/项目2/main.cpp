/*************************************************************************
> File Name: Array.h
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-07-27
>
> 1）支持数组的自动扩容，扩容系数是2
> 2）支持增删改查等基本操作
************************************************************************/
#include "../项目2/Array.h"
void main()
{
	struct Array arr;
	Array_Init(&arr);
	Array_Append(&arr, 1);
	Array_Append(&arr, 2);
	Array_Append(&arr, 3);
	Array_Append(&arr, 4);
	Array_Append(&arr, 5);
	Array_Append(&arr, 6);
	Array_Show(&arr);
	Array_Insert(&arr, 2, 22);
	Array_Insert(&arr, 1, 11);
	Array_Insert(&arr, arr.index+1, 999);
	Array_Show(&arr);
	Array_Delete(&arr,1);
	Array_Delete(&arr, arr.index);
	Array_Show(&arr);
	system("pause");
}