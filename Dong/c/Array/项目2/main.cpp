/*************************************************************************
> File Name: Array.h
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-07-27
>
> 1��֧��������Զ����ݣ�����ϵ����2
> 2��֧����ɾ�Ĳ�Ȼ�������
************************************************************************/
#include "../��Ŀ2/Array.h"
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