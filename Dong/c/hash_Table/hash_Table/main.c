/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）散列表初始大小为10，根据数据的增多，智能扩容。
 > 2）扩容条件是数据个数大于装载因子*散列表大小，扩容系数为2
 > 3）装载因子最大为0.75(工业基本都是0.75的上限)
 ************************************************************************/
#include "hash_Table.h"
#include <stdio.h>
void main()
{
	struct Hash_Table_Array t1;
	Init_Hash_Table_Array(&t1);
	Insert_Array_Hash(&t1, 1);
	Insert_Array_Hash(&t1, 2);
	Insert_Array_Hash(&t1, 4);
	Insert_Array_Hash(&t1, 8);
	Insert_Array_Hash(&t1, 9);
	Insert_Array_Hash(&t1, 10);
	Insert_Array_Hash(&t1, 11);
	Insert_Array_Hash(&t1, 50);
	Insert_Array_Hash(&t1, 90);
	printf("%d\n", isFind_Array_Hash(&t1,90));
	struct Hash_Table_List t2;
	Init_Hash_Table_List(&t2);
	Insert_List_Hash(&t2, 1);
	Insert_List_Hash(&t2, 2);
	Insert_List_Hash(&t2, 3);
	Insert_List_Hash(&t2, 2);
	Insert_List_Hash(&t2, 4);
	Insert_List_Hash(&t2, 8);
	Insert_List_Hash(&t2, 9);
	Insert_List_Hash(&t2, 10);
	Insert_List_Hash(&t2, 11);
	Insert_List_Hash(&t2, 50);
	printf("%d", isFind_List_Hash(&t2, 51));
	system("pause");
}