/*************************************************************************
 > File Name: Queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）相对于队列第一种的优化-解决了顺序队列的假溢出现象
 > 2）缺点:数据搬移问题(时间复杂度提高了)
 > 3）优点：解决队列空间利用不足问题，还实现了空间满额利用下的自动扩容
 ************************************************************************/
#include "Queue.h"
#include <stdio.h>
void Queue_Init(struct Queue *q)
{
	q->front = q->rear = 0;
	q->size = 1;
	q->data = (int*)malloc(sizeof(int)*q->size);
}
void Queue_push(struct Queue *q,int data)
{
	if (q->rear == q->size)
	{
		//队列空间全利用--自动扩容
		if (q->front == 0)
		{
			q->size = 2 * q->size;
			int temp = q->size;
			int *p = (int*)malloc(sizeof(int)*q->size);
			for (int i = 0; i < temp; i++)
			{
				p[i] = q->data[i];
			}
			free(q->data);
			q->data = p;
			q->data[q->rear++] = data;
		}
		//队列空间出现假溢出，数据搬迁至前面
		else {
			int count = 0;
			for (int i = 0; i < (q->rear - q->front); i++)
			{
				q->data[i] = q->data[q->front++];
				count++;
			}
			q->front = 0;
			q->rear = count;
		}
	}
	else {
		q->data[q->rear++] = data;
	}
}
int Queue_pop(struct Queue *q)
{
	if (q->front == q->rear)
	{
		return 999;
	}
	else {
		return q->data[q->front++];
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