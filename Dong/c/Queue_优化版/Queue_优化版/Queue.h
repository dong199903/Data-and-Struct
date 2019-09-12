/*************************************************************************
 > File Name: Queue.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）相对于队列第一种的优化-解决了顺序队列的假溢出现象
 > 2）缺点:数据搬移问题(时间复杂度提高了)
 > 3）优点：解决队列空间利用不足问题，还实现了空间满额利用下的自动扩容
 ************************************************************************/
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
struct Queue
{
	int rear;
	int front;
	int *data;
	int size;
};

void Queue_Init(struct Queue *q);
void Queue_push(struct Queue *q,int data);
int Queue_pop(struct Queue *q);
void Queue_Print(struct Queue *q);

#endif // !QUEUE_H
