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
#include <iostream>
using namespace std;
#include "Queue.h"


template<class T>
Queue<T>::Queue()
{
	this->size = 1;
	this->front = this->rear = 0;
	this->data = new T[this->size];
}


template<class T>
Queue<T>::Queue(int size)
{
	this->size = size;
	this->front = this->rear = 0;
	this->data = new T[this->size];
}


template<class T>
Queue<T>::~Queue()
{

}


template<class T>
void Queue<T>::inQueue(T data)
{
	//队列满额,自动扩容
	if ((this->rear + 1) % this->size == this->front)
	{
		//队列元素个数
		int count = 0;
		int len = (this->rear - this->front) % this->size;
		this->size = 2 * this->size;
		T *p = new T[this->size];
		for (int i = this->front; i < this->rear; i++)
		{
			p[count++] = this->data[i];
		}
		delete[] this->data;
		this->data = p;
		this->front = 0;
		this->rear = count;
		this->data[this->rear] = data;
		this->rear = (this->rear + 1) % this->size;
	}//队列未满，正常入队
	else {
		this->data[this->rear] = data;
		this->rear = (this->rear + 1) % this->size;
	}
}


template<class T>
T Queue<T>::outQueue()
{
	if (this->front == this->rear)
	{
		return 999;
	}
	else {
		int data = this->data[this->front];
		this->front = (this->front + 1) % this->size;
		return data;
	}
}


template<class T>
void Queue<T>::Queue_Print()
{
	for (int i = this->front; i < this->rear; i++)
	{
		cout << this->data[i] << " ";
	}
	cout << "\n";
}