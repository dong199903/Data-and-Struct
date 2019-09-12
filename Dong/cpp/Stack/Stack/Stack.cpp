/*************************************************************************
 > File Name: Stack.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）栈的实现
 > 2）支持入栈和出栈等基本操作
 > 3）实现了模板类，添加自己的类时,注意浅拷贝和深拷贝问题
 ************************************************************************/
#include "Stack.h"
#include <iostream>
using namespace std;

template<class T>
Stack<T>::Stack()
{
	this->top = -1;
	this->size = 1;
	this->data = new T[this->size];
}

template<class T>
Stack<T>::Stack(int size)
{
	this->top = -1;
	this->size = size;
	this->data = new T[this->size];
}


template<class T>
Stack<T>::~Stack()
{
	if (this->data != NULL)
	{
		delete[] this->data;
		this->size = 0;
		this->top = -1;
	}
}


template<class T>
void Stack<T>::push(T data)
{
	//满了，自动扩容
	if (this->top + 1 == this->size)
	{
		int len = this->size;
		this->size = 2 * this->size;
		T* temp = new T[this->size];
		for (int i = 0; i < len; i++)
		{
			temp[i] = this->data[i];
		}
		delete[] this->data;
		this->data = temp;
		this->data[++this->top] = data;
	}
	else {
		this->data[++this->top] = data;
	}
}


template<class T>
T Stack<T>::pop()
{
	if (this->top == -1)
	{
		return -999;
	}
	else {
		return this->data[this->top--];
	}
}


template<class T>
void Stack<T>::Stack_Print()
{
	for (int i = 0; i <= this->top; i++)
	{
		cout << this->data[i] << " ";
	}
	cout << "\n";
}