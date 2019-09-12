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
#include "LinkQueue.h"
#include <iostream>
using namespace std;


template<class T>
LinkQueue<T>::LinkQueue()
{
	this->size = 0;
	this->head = new Node<T>;
	this->head->next = NULL;
}


template<class T>
LinkQueue<T>::~LinkQueue()
{
	Node<T> *p, *q;
	p = this->head;
	q = p->next;
	while (q != NULL)
	{
		delete p;
		p = q;
		q = q->next;
	}
	delete p;
	p = NULL;
}


template<class T>
void LinkQueue<T>::inQueue(T data)
{
	Node<T> *p = this->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	Node<T> *temp = new Node<T>;
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
	this->size++;
}
template<class T>
T LinkQueue<T>::outQueue()
{
	T data;
	Node<T> *p;
	p = this->head->next;
	if (p == NULL)
	{
		return NULL;
	}
	else {
		data = p->data;
		this->head->next = p->next;
		delete p;
		p = NULL;
		return data;
	}
}
template<class T>
void LinkQueue<T>::print_Queue()
{
	Node<T> *p = this->head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}