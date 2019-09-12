/*************************************************************************
 > File Name: Queue.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）顺序队列--存在假溢出现象
 > 2）支持入队和出队访问
 > 3）其它功能
 ************************************************************************/
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
struct Queue 
{
	int front;
	int rear;
	int *data;
	int size;
};

void Queue_Init(struct Queue * queue);
void inQueue(struct Queue * queue,int data);
int outQueue(struct Queue * queue);
void Queue_Print(struct Queue * queue);

#define getFront(queue)  (queue->data[queue->front])
#define getRear(queue) (queue->data[queue->front])
#endif // !QUEUE_H
