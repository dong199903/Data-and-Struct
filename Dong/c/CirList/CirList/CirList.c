/*************************************************************************
 > File Name: CirList.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）首尾相连的循环单链表
 > 2）支持增删改查等基本操作
 ************************************************************************/
#include "CirList.h"
#include <stdio.h>
#include <stdlib.h>
//初始化
void CirList_Init(struct CirList* clist)
{
	clist->size = 0;
	clist->head = (struct Node*)malloc(sizeof(struct Node));
	clist->head->next = clist->head;
}
//尾插---修改中
void CirList_Append(struct CirList* clist, int data)
{
	struct Node* p, *temp;
	p = clist->head->next;
	while (p -> next != clist->head)
	{
		p = p->next;
	}
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = clist->head;
	p->next = temp;
	clist->size++;
}
//头插
void CirList_Front(struct CirList* clist, int data)
{
	struct Node* p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = data;
	p->next = clist->head->next;
	clist->head->next = p;
	clist->size++;
}
//指定位置插
void CirList_Insert(struct CirList* clist, int index, int data)
{
	if (index <= 0 || index > (clist->size + 1))
	{
		return;
	}
	else {
		struct Node *p, *temp;
		p = clist->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		temp->next = p->next;
		p->next = temp;
		clist->size++;
	}
}
//指定位置删除
void CirList_Del(struct CirList* clist, int index)
{
	if (index <= 0 || index > clist->size)
	{
		return;
	}
	else {
		//先找到目标位置的前一个位置p
		struct Node *p, *temp;
		p = clist->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = p->next->next;
		free(temp);
		temp = NULL;
		clist->size--;
	}
}
//遍历
void CirList_Print(struct CirList* clist)
{
	struct Node *p = clist->head->next;
	while (p != clist->head)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//销毁
void CirList_Destory(struct CirList* clist)
{
	struct Node *p, *q;
	p = clist->head;
	q = p->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
	p = NULL;
}