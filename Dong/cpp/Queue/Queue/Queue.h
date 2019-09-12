/*************************************************************************
 > File Name: Queue.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）顺序队列
 > 2）基本的入队列和出队列
 > 3）
 ************************************************************************/
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
template<class T>
class Queue
{
public:
	int front;
	int rear;
	int size;
	T *data;
	Queue();
	Queue(int size);
	~Queue();
	void inQueue(T data);
	T outQueue();
	void Queue_Print();
};
#endif // !QUEUE_H
