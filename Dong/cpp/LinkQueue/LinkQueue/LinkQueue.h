/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

template<class T>
class Node
{
public:
	Node *next;
	T data;
};

template<class T>
class LinkQueue
{
public:
	Node<T> *head;
	int size;
	LinkQueue();
	~LinkQueue();
	void inQueue(T data);
	T outQueue();
	void print_Queue();
};
#endif // !LINKQUEUE_H
