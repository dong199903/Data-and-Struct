/*************************************************************************
 > File Name: List.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）支持简单的增删改查
 > 2）支持模板泛型编程
 > 3）支持添加第三方类成员(Tip:有指针的需要实现深拷贝构造)
 ************************************************************************/
#include"List.h"
#include<iostream>
using namespace std;


template<class T>
List<T>::List()
{
	this->size = 0;
	this->head = new Node<T>;
	this->head->next = NULL;
}


template<class T>
List<T>::~List()
{
	Node<T> *p, *q;
	p = this->head;
	q = p->next;
	while (q != NULL)
	{
		delete p;
		p = q;
		q = p->next;
	}
	delete p;
	p = NULL;
}


template<class T>
void List<T>::List_Append(T data)
{
	Node<T> *temp, *p;
	p = this->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	temp = new Node<T>;
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
	this->size++;
}


template<class T>
void List<T>::List_Front(T data)
{
	Node<T> *p;
	p = new Node<T>;
	p->data = data;
	p->next = this->head->next;
	this->head->next = p;
	this->size++;

}


template<class T>
void List<T>::List_Insrt(int index, T data)
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
void List<T>::List_Del(int index)
{
	if (index <= 0 || index > this->size)
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
		p->next = p->next->next;
		delete temp;
		temp = NULL;
		this->size--;
	}

}


template<class T>
void List<T>::List_Print()
{
	Node<T> *p = this->head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
	
}