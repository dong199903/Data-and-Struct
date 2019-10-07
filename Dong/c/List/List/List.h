/*************************************************************************
 > File Name: List.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）单链表的头插法和尾插法
 > 2）单链表任意位置插入和删除
 > 3）单链表基本操作
 ************************************************************************/

#ifndef LIST_H
#define LIST_H
#include<stdio.h>
#include<stdlib.h>
/*定义单链表的节点*/
struct Node
{
	struct Node* next;
	int data;
};
/*定义单链表总体*/
struct List
{
	struct Node* head;
	int size;
};
void List_Init(struct List* list);//初始化
void List_Append(struct List* list,int data);//尾插法
void List_Front(struct List* list,int data);//头插法
void List_Insert(struct List* list, int index,int data);//指定位置插
void List_Del(struct List* list,int index);//指定位置的删除
void List_Destory(struct List* list);//销毁单链表
void List_Print(struct List* list);//遍历单链表



#define List_Empty(list) (list->size==0)//(宏)判断链表是否为空
#define List_Size(list) (list->size)//(宏)返回链表的长度
#endif

