/*************************************************************************
 > File Name: CirList.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）循环单链表
 > 2）支持模板泛型编程
 > 3）支持增删该查基本操作
 ************************************************************************/
#pragma once
#ifndef CIRLIST_H
#define CIRLIST_H
template<class T>
class Node
{
public:
	Node()
	{

	}
	T data;
	Node* next;
};

template<class T>
class CirList
{
public:
	Node<T>* head;
	int size;
	CirList();
	~CirList();
	void CList_Append(T data);
	void CList_Front(T data);
	void CList_Insrt(int index, T data);
	void CList_Del(int index);
	void CList_Print();
};
#endif // !CIRLIST_H

