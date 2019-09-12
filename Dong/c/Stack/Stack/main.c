/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）栈的实现
 > 2）空间不足时，自动扩容，系数为2
 > 3）支持基本的增删改查等功能
 ************************************************************************/
#include "Stack.h"
void main()
{
	struct Stack stack;
	Stack_Init(&stack);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	Stack_Print(&stack);
	printf("%d\n", pop(&stack));
	Stack_Print(&stack);
	system("pause");
}