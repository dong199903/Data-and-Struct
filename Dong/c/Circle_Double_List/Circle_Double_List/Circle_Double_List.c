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
#include "Circle_Double_List.h"
#include <stdio.h>
void CDouble_List_Init(struct CDouble_List* list)
{
	list->size = 0;
	list->head = (struct Node*)malloc(sizeof(struct Node));
	list->head->next = list->head;
	list->head->pre = list->head;
}
void CDouble_List_Append(struct CDouble_List* list, int data)
{
	struct Node *p, *temp;
	p = list->head->next;
	while (p->next != list->head)
	{
		p = p->next;
	}
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = p->next;
	temp->pre = p;
	p->next = temp;
	list->head->pre = temp;
	list->size++;
}
void CDouble_List_Front(struct CDouble_List* list, int data)
{
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = data;
	p->next = list->head->next;
	p->pre = list->head;
	list->head->next->pre = p;
	list->head->next = p;
	list->size++;
}
void CDouble_List_Insert(struct CDouble_List* list, int index, int data)
{
	if (index <= 0 || index > (list->size + 1))
	{
		return;
	}
	else {
		struct Node *p,*temp;
		p = list->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		temp->next = p->next;
		temp->pre = p;
		p->next->pre = temp;
		p->next = temp;
		list->size++;
	}
}
void CDouble_List_Del(struct CDouble_List* list, int index)
{
	if (index <= 0 || index > list->size)
	{
		return;
	}
	else {
		struct Node *p,*temp;
		p = list->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = temp->next;
		temp->next->pre = p;
		free(temp);
		list->size--;
	}

}
void CDouble_List_Print(struct CDouble_List* list)
{
	struct Node *p;
	p = list->head->next;
	while (p != list->head)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

}
void CDouble_List_Print_Reverse(struct CDouble_List* list)
{
	struct Node *p;
	p = list->head->pre;
	while (p != list->head)
	{
		printf("%d ", p->data);
		p = p->pre;
	}
	printf("\n");
}
void CDouble_List_Destroy(struct CDouble_List* list)
{
	struct Node *p, *q;
	q = list->head->next;
	while (q != list->head)
	{
		list->head->next = q->next;
		q->next->pre = list->head;
		free(q);
		q = list->head->next;
	}
	free(q);
	q = NULL;
	
}