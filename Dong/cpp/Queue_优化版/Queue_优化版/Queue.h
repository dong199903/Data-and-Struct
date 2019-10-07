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

