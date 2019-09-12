/*************************************************************************
 > File Name: List.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）支持简单的增删改查
 > 2）支持模板泛型编程
 > 3）支持添加第三方类成员(Tip:有指针的需要实现深拷贝构造)
 ************************************************************************/
#pragma once
#ifndef LIST_H
#define LIST_H
#include "Node.h"
template<class T>
class List
{
public:
	int size;
	Node<T> *head;
	List();
	~List();
	void List_Append(T data);
	void List_Front(T data);
	void List_Insrt(int index, T data);
	void List_Del(int index);
	void List_Print();
};
#endif 

