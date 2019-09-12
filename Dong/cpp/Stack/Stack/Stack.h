/*************************************************************************
 > File Name: Stack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）栈的实现
 > 2）支持入栈和出栈等基本操作
 > 3）实现了模板类，添加自己的类时,注意浅拷贝和深拷贝问题
 ************************************************************************/
#pragma once
#ifndef STACK_H
#define STACK_H
template<class T>
class Stack
{
public:
	int top;//栈顶指针
	T* data;
	int size;//最大存储空间(满了自动扩容)
	Stack();
	Stack(int size);
	~Stack();
	void push(T data);
	T pop();
	void Stack_Print();
};
#endif // !STACK_H

