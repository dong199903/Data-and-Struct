/*************************************************************************
 > File Name: CDouble_List.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30

 > 1）循环双链表-支持模板类操作
 > 2）支持增删改查等基本操作
 > 3）支持逆序输出
 ************************************************************************/
#include "CDouble_List.h"
#include <iostream>
using namespace std;

template<class T>
CDouble_List<T>::CDouble_List()
{
	this->size = 0;
	this->head = new Node<T>;
	this->head->next = head;
	this->head->pre = head;
}

template<class T>
CDouble_List<T>::~CDouble_List()
{
	Node<T> *p, *q;
	p = this->head;
	q = p->next;
	while (q != this->head)
	{
		p->next = q->next;
		q->next->pre = p;
		delete q;
		q = p->next;
	}
	delete p;
	p = NULL;
	this->size = 0;
}

template<class T>
void CDouble_List<T>::CDouble_List_Append(T data)
{
	Node<T> *p,*temp;
	p = this->head->pre;
	temp = new Node<T>;
	temp->data = data;
	temp->next = this->head;
	temp->pre = p;
	p->next = temp;
	this->head->pre = temp;
	this->size++;

}

template<class T>
void CDouble_List<T>::CDouble_List_Front(T data)
{
	Node<T> *p;
	p = new Node<T>;
	p->data = data;
	p->next = this->head->next;
	p->pre = this->head;
	this->head->next->pre = p;
	this->head->next = p;
	this->size++;
}

template<class T>
void CDouble_List<T>::CDouble_List_Insert(int index,T data)
{
	if (index <= 0 || index > (this->size + 1))
	{
		return;
	}
	else {
		Node<T> *p,*temp;
		p = this->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = new Node<T>;
		temp->data = data;
		temp->next = p->next;
		temp->pre = p;
		p->next->pre = temp;
		p->next = temp;
		this->size++;
	}
}

template<class T>
void CDouble_List<T>::CDouble_List_Del(int index)
{
	if (index <= 0 || index > this->size)
	{
		return;
	}
	else {
		Node<T> *p,*temp;
		p = this->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = temp->next;
		temp->next->pre = p;
		delete temp;
		temp = NULL;
		this->size--;
	}
}

template<class T>
void CDouble_List<T>::CDouble_List_Print()
{
	Node<T> *p;
	p = this->head->next;
	while (p != this->head)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}

template<class T>
void CDouble_List<T>::CDouble_List_Print_Reverse()
{
	Node<T> *p;
	p = this->head->pre;
	while (p != this->head)
	{
		cout << p->data << " ";
		p = p->pre;
	}
	cout << "\n";
}