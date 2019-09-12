/*************************************************************************
 > File Name: Double_List.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-29
 >
 > 1）双链表
 > 2）支持简单的增删改查
 > 3）支持逆序输出
 ************************************************************************/
#include "Double_List.h"
#include <iostream>
using namespace std;
template<class T>
Double_List<T>::Double_List()
{
	this->size = 0;
	this->head = new Node<T>;
	this->head->next = NULL;
	this->head->pre = NULL;
}

template<class T>
Double_List<T>::~Double_List()
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
void Double_List<T>::Double_List_Append(T data)
{
	Node<T> *p, *q;
	p = this->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	q = new Node<T>;
	q->data = data;
	q->next = p->next;
	q->pre = p;
	p->next = q;
	this->size++;
}

template<class T>
void Double_List<T>::Double_List_Front(T data)
{
	Node<T> *p = this->head;
	Node<T> *temp = new Node<T>;
	temp->data = data;
	temp->pre = p;
	temp->next = p->next;
	p->next->pre = temp;
	p->next = temp;
	this->size++;
}


template<class T>
void Double_List<T>::Double_List_Insert(int index, T data)
{
	if (index >= 0 || index > (this->size + 1))
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
		temp->pre = p;
		p->next->pre = temp;
		p->next = temp;
		this->size++;
	}
}


template<class T>
void Double_List<T>::Double_List_Del(int index)
{
	if (index >= 0 || index > this->size)
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
		temp = p->next;
		p->next = temp->next;
		temp->next->pre = p;
		delete temp;
		this->size--;
	}
}


template<class T>
void Double_List<T>::Double_List_Print()
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


template<class T>
void Double_List<T>::Double_List_Print_Reverse()
{
	Node<T> *p;
	p = this->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p != this->head)
	{
		cout << p->data << " ";
		p = p->pre;
	}
	cout << endl;
}