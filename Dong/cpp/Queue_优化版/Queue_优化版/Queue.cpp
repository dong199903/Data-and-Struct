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
	this-size= size;
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
	if (this->rear == this->size)
	{
		//队列空间全利用--自动扩容
		if (this->front == 0)
		{
			this->size = 2 * this->size;
			int temp = this->size;
			T *p = new T[this->size * 2];
			for (int i = 0; i < temp; i++)
			{
				p[i] = this->data[i];
			}
			delete[] this->data;
			this->data = p;
			this->data[this->rear++] = data;
		}
		//队列空间出现假溢出，数据搬迁至前面
		else {
			int count = 0;
			for (int i = 0; i < (this->rear - this->front); i++)
			{
				this->data[i] = this->data[this->front++];
				count++;
			}
			this->front = 0;
			this->rear = count;
		}
	}
	else 
	{
		this->data[this->rear++] = data;
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
		return this->data[this->front++];
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