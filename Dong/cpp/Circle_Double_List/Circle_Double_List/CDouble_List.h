/*************************************************************************
 > File Name: CDouble_List.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）循环双链表-支持模板类操作
 > 2）支持增删改查等基本操作
 > 3）支持逆序输出
 ************************************************************************/
#pragma once
#ifndef CDOUBLE_LIST
#define CDOUBLE_LIST
template<class T>
class Node 
{
public:
	Node* next;
	Node* pre;
	T data;
	Node()
	{

	}
};

template<class T>
class CDouble_List
{
public:
	Node<T> *head;
	int size;
	CDouble_List();
	~CDouble_List();
	void CDouble_List_Append(T data);
	void CDouble_List_Front(T data);
	void CDouble_List_Insert(int index,T data);
	void CDouble_List_Del(int index);
	void CDouble_List_Print();
	void CDouble_List_Print_Reverse();
};
#endif // !CDOUBLE_LIST
