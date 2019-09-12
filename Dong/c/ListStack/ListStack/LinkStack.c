/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#include "LinkStack.h"
#include <stdio.h>
void LinkStack_Init(struct LinkStack * s)
{
	s->size = 0;
	s->head = (struct Node*)malloc(sizeof(struct Node));
	s->head->next = NULL;
}
void LinkStack_push(struct LinkStack * s, int data)
{
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = s->head->next;
	s->head->next = temp;
	s->size++;
}
int LinkStack_pop(struct LinkStack * s)
{
	if (s->head->next == NULL)
	{
		return -999;
	}
	else {
		struct Node *temp = s->head->next;
		int data = temp->data;
		s->head->next = temp->next;
		free(temp);
		temp = NULL;
		return data;
	}
}
void LinkStack_Print(struct LinkStack * s)
{
	struct Node *temp = s->head->next;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}