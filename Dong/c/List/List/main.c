/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）单链表的头插法和尾插法
 > 2）单链表任意位置插入和删除
 > 3）单链表基本操作
 ************************************************************************/
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct List list;
	List_Init(&list);
	List_Append(&list, 1);
	List_Append(&list, 2);
	List_Append(&list, 3);
	List_Append(&list, 4);
	List_Append(&list, 5);
	List_Print(&list);
	List_Front(&list, 22);
	List_Front(&list, 11);
	List_Print(&list);
	List_Insert(&list, 3, 333);
	List_Del(&list, 4);
	List_Print(&list);
	List_Destory(&list);
	system("pause");
}