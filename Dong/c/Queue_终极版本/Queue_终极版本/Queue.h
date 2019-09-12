/*************************************************************************
 > File Name: Queue.h
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

void Queue_Init(struct Queue * q);
void Queue_push(struct Queue *q,int data);
int Queue_pop(struct Queue *q);
void Queue_Print(struct Queue *q);
#endif // !QUEUE_H
