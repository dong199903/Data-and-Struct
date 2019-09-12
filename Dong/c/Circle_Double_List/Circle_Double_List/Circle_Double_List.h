/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）循环双链表
 > 2）支持增删该查基本功能
 > 3）支持逆序
 ************************************************************************/
#pragma once
#ifndef CIRCLE_DOUBLE_LIST
#define CIRCLE_DOUBLE_LIST
struct Node
{
	int data;
	struct Node* next;
	struct Node* pre;
};

struct CDouble_List
{
	struct Node* head;
	int size;
};


void CDouble_List_Init(struct CDouble_List* list);
void CDouble_List_Append(struct CDouble_List* list,int data);
void CDouble_List_Front(struct CDouble_List* list,int data);
void CDouble_List_Insert(struct CDouble_List* list,int index,int data);
void CDouble_List_Del(struct CDouble_List* list,int index);
void CDouble_List_Print(struct CDouble_List* list);
void CDouble_List_Print_Reverse(struct CDouble_List* list);
void CDouble_List_Destroy(struct CDouble_List* list);
#endif // !CIRCLE_DOUBLE_LIST

