/*************************************************************************
 > File Name: Stack.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）栈的实现
 > 2）空间不足时，自动扩容，系数为2
 > 3）支持基本的增删改查等功能
 ************************************************************************/
#include "Stack.h"
#include <stdio.h>
void Stack_Init(struct Stack *stack)
{
	stack->top = -1;
	stack->size = 1;
	stack->data = (int *)malloc(sizeof(int)*stack->size);
}
void push(struct Stack *stack,int data)
{
	if (stack->top + 1 == stack->size)
	{
		int temp,*p;
		temp = stack->size;
		stack->size = stack->size * 2;
		p = (int *)malloc(sizeof(int)*stack->size);
		for (int i = 0; i < temp; i++)
		{
			p[i] = stack->data[i];
		}
		free(stack->data);
		stack->data = NULL;
		stack->data = p;
		stack->data[++stack->top] = data;
	}
	else {
		stack->data[++stack->top] = data;
	}
}
int pop(struct Stack *stack)
{
	if (stack->top == -1)
	{
		return -999;
	}
	else {
		return stack->data[stack->top--];
	}
}
void Destory(struct Stack *stack)
{
	if (stack->data != NULL)
	{
		free(stack->data);
		stack->data = NULL;
		stack->top = -1;
		stack->size = 0;
	}
}
void IsEmpty(struct Stack *stack)
{
	return stack->top == -1;
}
void Stack_Print(struct Stack *stack)
{
	for (int i = 0; i <= stack->top; i++)
	{
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}