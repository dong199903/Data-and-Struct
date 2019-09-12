/*************************************************************************
 > File Name: Stack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）栈的实现
 > 2）空间不足时，自动扩容，系数为2
 > 3）支持基本的增删改查等功能
 ************************************************************************/
#pragma once
#ifndef STACK_H
struct Stack
{
	int top;
	int size;
	int *data;
};

void Stack_Init(struct Stack *stack);
void push(struct Stack *stack,int data);
int pop(struct Stack *stack);
void Destory(struct Stack *stack);
void IsEmpty(struct Stack *stack);
void Stack_Print(struct Stack *stack);

#define STACK_H
#endif // !STACK_H
