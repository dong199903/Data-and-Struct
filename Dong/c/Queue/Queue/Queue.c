/*************************************************************************
 > File Name: Queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）顺序队列--存在假溢出现象
 > 2）支持入队和出队访问
 > 3）其它功能
 ************************************************************************/
#include "Queue.h"
#include <stdio.h>
void Queue_Init(struct Queue * queue)
{
	queue->front = 0;
	queue->rear = 0;
	queue->size = 1;
	queue->data = (int*)malloc(sizeof(int)*queue->size);
}
void inQueue(struct Queue * queue, int data)
{
	//队列满了,自动扩容
	if (queue->rear == queue->size)
	{
		int temp;
		temp = queue->size;
		queue->size = queue->size * 2;
		int *q = (int*)malloc(sizeof(int)*queue->size);
		for (int i = queue->front; i < queue->rear; i++)
		{
			q[i] = queue->data[i];
		}
		free(queue->data);
		queue->data = NULL;
		queue->data = q;
		queue->data[queue->rear++] = data;
	}
	else {
		queue->data[queue->rear++] = data;
	}
}
int outQueue(struct Queue * queue)
{
	if (queue->front == queue->rear)
	{
		return 999;
	}
	else {
		return queue->data[queue->front++];
	}
}
void Queue_Print(struct Queue * queue)
{
	for (int i = queue->front; i < queue->rear; i++)
	{
		printf("%d ", queue->data[i]);
	}
	printf("\n");
}