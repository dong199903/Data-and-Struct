/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-09
 >
 > 1）链栈的基本实现
 > 2）入栈和出栈等基本操作
 > 3）
 ************************************************************************/
#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H
template<class T>
class Node
{
public:
	Node *next;
	T data;
};

template<class T>
class LinkStack
{
public:
	Node<T> *head;
	int size;
	LinkStack();
	~LinkStack();
	void push(T data);
	T pop();
	void printStack();
};
#endif // !LINKSTACK_H

