/*************************************************************************
 > File Name: Queue.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）顺序队列
 > 2）基本的入队列和出队列
 > 3）
 ************************************************************************/
#include "Queue.h"
#include <iostream>
using namespace std;
template<class T>
Queue<T>::Queue()
{
	this->front = 0;
	this->rear = 0;
	this->size = 1;
	this->data = new T[this->size];
}
template<class T>
Queue<T>::Queue(int size)
{
	this->front = 0;
	this->rear = 0;
	this->size = 1;
	this->data = new T[this->size];
}
template<class T>
Queue<T>::~Queue()
{
	if (this->data != NULL)
	{
		delete[] this->data;
		this->data = NULL;
		this->rear = this->front = 0;
		this->size = 0;
	}
	else {
		this->rear = this->front = 0;
		this->size = 0;
	}
}
template<class T>
void Queue<T>::inQueue(T data)
{
	if (this->rear == this->size)
	{
		int len = this->size;
		this->size = 2 * this->size;
		int *temp = new T[this->size];
		for (int i = 0; i < len; i++)
		{
			temp[i] = this->data[i];
		}
		delete[] this->data;
		this->data = temp;
		this->data[this->rear++] = data;
	}
	else {
		this->data[this->rear++] = data;
	}
}
template<class T>
T Queue<T>::outQueue()
{
	if (this->front == 0)
	{
		return NULL;
	}
	else {
		return this->data[this->front++]
	}
}
template<class T>
void Queue<T>::Queue_Print()
{
	for (int i = this->front; i < this->rear; i++)
	{
		cout << this->data[i] << " ";
	}
	cout << endl;
}