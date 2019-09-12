/*************************************************************************
 > File Name: Double_List.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-29
 >
 > 1）双链表
 > 2）支持简单的增删改查
 > 3）支持逆序输出
 ************************************************************************/
#pragma once
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H
template<class T>
class Node
{
public:
	T data;
	Node* next;
	Node* pre;
};

template<class T>
class Double_List
{
public:
	Node<T> *head;
	int size;
	Double_List();
	~Double_List();
	void Double_List_Append(T data);
	void Double_List_Front(T data);
	void Double_List_Insert(int index,T data);
	void Double_List_Del(int index);
	void Double_List_Print();
	void Double_List_Print_Reverse();
};
#endif // !DOUBLE_LIST_H
