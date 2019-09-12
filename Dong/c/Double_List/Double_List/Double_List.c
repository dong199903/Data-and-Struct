/*************************************************************************
 > File Name: Double_List.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-29
 >
 > 1）双链表
 > 2）支持简单增删改查
 > 3）支持逆序输出(双链表的特点)
 ************************************************************************/
#include "Double_List.h"
#include <stdio.h>
#include <stdlib.h>
void Double_List_Init(struct Double_List* dlist)
{
	dlist->size = 0;
	dlist->head = (struct Node*)malloc(sizeof(struct Node));
	dlist->head->pre = NULL;
	dlist->head->next = NULL;
}
void Double_List_Append(struct Double_List* dlist, int data)
{
	struct Node *p, *temp;
	p = dlist->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = p->next;
	temp->pre = p;
	p->next = temp;
	dlist->size++;
}
void Double_List_Front(struct Double_List* dlist, int data)
{
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = data;
	p->next = dlist->head->next;
	p->pre = dlist->head;
	dlist->head->next->pre = p;
	dlist->head->next = p;
	dlist->size++;
}
void Double_List_Insert(struct Double_List* dlist, int index, int data)
{
	if (index <= 0 || index > (dlist->size + 1))
	{
		return;
	}
	else {
		struct Node *p,*temp;
		p = dlist->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		temp->pre = p;
		temp->next = p->next;
		p->next->pre = temp;
		p->next = temp;
		dlist->size++;
	}
}
void Double_List_Del(struct Double_List* dlist, int index)
{
	if (index <= 0 || index > dlist->size)
	{
		return;
	}
	else {
		struct Node *p,*temp;
		p = dlist->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = p->next;//目标节点
		p->next = temp->next;
		temp->next->pre = p;
		free(temp);
		temp = NULL;
		dlist->size--;
	}
}
void Double_List_Destory(struct Double_List* dlist)
{
	struct Node *p, *q;
	p = dlist->head;
	q = p->next;
	while (q!=NULL)
	{
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
	p = NULL;
}
void Double_List_Print(struct Double_List* dlist)
{
	struct Node *p;
	p = dlist->head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void Double_List_Print_Reverse(struct Double_List* dlist)
{
	struct Node *p;
	p = dlist->head->next;
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p != dlist->head)
	{
		printf("%d ", p->data);
		p = p->pre;
	}
	printf("\n");
}