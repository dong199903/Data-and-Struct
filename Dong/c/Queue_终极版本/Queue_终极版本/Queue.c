/*************************************************************************
 > File Name: Queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）在队列版本二基础上进一步完善，解决了队列搬移数据问题
 > 2）在此基础上，增加了自动扩容
 > 3）循环队列空:fornt==rear
 > 3）循环队列满:(rear+1)%size = front
 > 3）循环队列元素个数:(rear-front+size)%size
 ************************************************************************/
#include "Queue.h"
#include <stdio.h>
void Queue_Init(struct Queue * q)
{
	q->size = 1;
	q->front = q->rear = 0;
	q->data = (int*)malloc(sizeof(int) * q->size);
}
void Queue_push(struct Queue *q,int data)
{
	//队列满额,自动扩容
	if ((q->rear + 1) % q->size == q->front)
	{
		//队列元素个数
		int count = 0;
		int len = (q->rear - q->front) % q->size;
		q->size = 2 * q->size;
		int *p = (int*)malloc(sizeof(int)*q->size);
		for (int i = q->front; i < q->rear; i++)
		{
			p[count++] = q->data[i];
		}
		free(q->data);
		q->data = p;
		q->front = 0;
		q->rear = count;
		q->data[q->rear] = data;
		q->rear = (q->rear + 1)%q->size;
	}//队列未满，正常入队
	else {
		q->data[q->rear] = data;
		q->rear = (q->rear + 1)%q->size;
	}
}
int Queue_pop(struct Queue *q)
{
	if (q->front == q->rear)
	{
		return 999;
	}
	else {
		int data = q->data[q->front];
		q->front = (q->front + 1) % q->size;
		return data;
	}
}
void Queue_Print(struct Queue *q)
{
	for (int i = q->front; i < q->rear; i++) 
	{
		printf("%d ", q->data[i]);
	}
	printf("\n");
}