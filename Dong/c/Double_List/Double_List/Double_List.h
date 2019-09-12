/*************************************************************************
 > File Name: Double_List.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-29
 >
 > 1）双链表
 > 2）支持简单增删改查
 > 3）支持逆序输出(双链表的特点)
 ************************************************************************/
#pragma once
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H
struct Node
{
	int data;
	struct Node* next;
	struct Node* pre;
};

struct Double_List
{
	struct Node* head;
	int size;
};

void Double_List_Init(struct Double_List* dlist);
void Double_List_Append(struct Double_List* dlist,int data);
void Double_List_Front(struct Double_List* dlist,int data);
void Double_List_Insert(struct Double_List* dlist, int index,int data);
void Double_List_Del(struct Double_List* dlist,int index);
void Double_List_Destory(struct Double_List* dlist);
void Double_List_Print(struct Double_List* dlist);
void Double_List_Print_Reverse(struct Double_List* dlist);

#endif // !DOUBLE_LIST_H

