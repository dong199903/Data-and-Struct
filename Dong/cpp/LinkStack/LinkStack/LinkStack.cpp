/*************************************************************************
 > File Name: LinkStack.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-09
 >
 > 1）链栈的基本实现
 > 2）入栈和出栈等基本操作
 > 3）
 ************************************************************************/
#include "LinkStack.h"
#include <iostream>
using namespace std;
template<class T>
LinkStack<T>::LinkStack()
{
	this->head = new Node<T>;
	this->head->next = NULL;
	this->size = 0;
}


template<class T>
LinkStack<T>::~LinkStack()
{
	Node<T> *p,*q;
	p = this->head;
	q = p->next;
	while (q!=NULL)
	{
		delete p;
		p = q;
		q = q->next;
	}
	delete p;
	p = NULL;
}

template<class T>
void LinkStack<T>::push(T data)
{
	Node<T> *temp = new Node<T>;
	temp->data = data;
	temp->next = this->head->next;
	this->head->next = temp;
	this->size++;
}

template<class T>
T LinkStack<T>::pop()
{
	if (this->head->next == NULL)
	{
		return NULL;
	}
	else {
		Node<T> *p;
		T data;
		data = this->head->next->data;
		p = this->head->next;
		this->head->next = p->next;
		delete p;
		p = NULL;
		this->size--;
		return data;
	}
}

template<class T>
void LinkStack<T>::printStack()
{
	Node<T> *p;
	p = this->head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}