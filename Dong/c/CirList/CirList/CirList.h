/*************************************************************************
 > File Name: CirList.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）首尾相连的循环单链表
 > 2）支持增删改查等基本操作
 ************************************************************************/
#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
struct Node
{
	int data;
	struct Node* next;
};

struct CirList
{
	struct Node* head;
	int size;
};

void CirList_Init(struct CirList* clist);
void CirList_Append(struct CirList* clist, int data);
void CirList_Front(struct CirList* clist, int data);
void CirList_Insert(struct CirList* clist, int index, int data);
void CirList_Del(struct CirList* clist, int index );
void CirList_Print(struct CirList* clist);
void CirList_Destory(struct CirList* clist);

#endif // !CIRCLE_H

