/*************************************************************************
 > File Name: List_Queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-01(建军节)
 >
 > 1）链队的实现
 > 2）基本的入队列和出队列
 > 3）
 ************************************************************************/
#include "List_Queue.h"
#include <stdio.h>
void Link_Queue_Init(struct Link_Queue *q)
{
	q->head = (struct Node*)malloc(sizeof(struct Node));
	q->head->next = NULL;
	q->front = q->head->next;
	q->rear = q->head;
}
void inQueue(struct Link_Queue *q, int data)
{
	struct Node *temp,*p;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = q->rear->next;
	q->rear->next = temp;
	q->rear = temp;
	q->front = q->head->next;
}
int outQueue(struct Link_Queue *q)
{
	if (q->front == NULL)
	{
		return 999;
	}
	else {
		struct Node *temp;
		temp = q->front;
		q->head->next = temp->next;
		free(temp);
		q->front = q->head->next;
	}
}
void Link_Queue_Print(struct Link_Queue *q)
{
	struct Node *temp;
	temp = q->front;
	while (temp != q->rear->next)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}