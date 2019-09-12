/*************************************************************************
 > File Name: Link_Queue.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-01(建军节)
 >
 > 1）链队的实现
 > 2）基本的入队列和出队列
 > 3）
 ************************************************************************/
#pragma once
#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

struct Node
{
	int data;
	struct Node *next;
};
struct Link_Queue
{
	struct Node *head;
	struct Node *front;
	struct Node *rear;
};

void Link_Queue_Init(struct Link_Queue *q);
void inQueue(struct Link_Queue *q, int data);
int outQueue(struct Link_Queue *q);
void Link_Queue_Print(struct Link_Queue *q);
#endif // !LIST_QUEUE_H
