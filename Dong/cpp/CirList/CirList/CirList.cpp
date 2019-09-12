/*************************************************************************
 > File Name: CirList.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）循环单链表
 > 2）支持模板泛型编程
 > 3）支持增删该查基本操作
 ************************************************************************/
#include "CirList.h"
#include <iostream>
using namespace std;


template<class T>
CirList<T>::CirList()
{
	this->size = 0;
	this->head = new Node<T>;
	this->head->next = this->head;
}

//销毁--(先从第一个节点开始销毁，非头节点开始)
template<class T>
CirList<T>::~CirList()
{
	Node<T>* p, *q;
	p = this->head->next;
	q = p->next;
	while (p != this->head)
	{
		this->head->next = p->next;
		delete p;
		p = q;
		q = q->next;
	}
	delete this->head;
	this->head = NULL;
	this->size = 0;
}


template<class T>
void CirList<T>::CList_Append(T data)
{
	Node<T>* p, *temp;
	p = this->head->next;
	while (p->next != this->head)
	{
		p = p->next;
	}
	temp = new Node<T>;
	temp->data = data;
	temp->next = this->head;
	p->next = temp;
	this->size++;
}

template<class T>
void CirList<T>::CList_Front(T data)
{
	Node<T>* p;
	p = new Node<T>;
	p->data = data;
	p->next =this->head->next;
	this->head->next = p;
	this->size++;
}

template<class T>
void CirList<T>::CList_Insrt(int index, T data)
{
	if (index <= 0 || index > (this->size + 1))
	{
		return;
	}
	else {
		Node<T> *p, *temp;
		p = this->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = new Node<T>;
		temp->data = data;
		temp->next = p->next;
		p->next = temp;
		this->size++;
	}
}

template<class T>
void CirList<T>::CList_Del(int index)
{
	if(index <= 0 || index > this->size)
	{
		return;
	}
	else {
		//先找到目标位置的前一个位置p
		Node<T> *p, *temp;
		p = clist->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = p->next->next;
		delete temp;
		temp = NULL;
		this->size--;
	}
}

template<class T>
void CirList<T>::CList_Print()
{
	Node<T> *p = this->head->next;
	while (p != this->head)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}