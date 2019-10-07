/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）链栈的入栈
 > 2）链栈的出栈
 > 3）链栈的打印
 ************************************************************************/
#include "LinkStack.h"
void main()
{
	struct LinkStack s;
	LinkStack_Init(&s);
	LinkStack_push(&s, 1);
	LinkStack_push(&s, 2);
	LinkStack_push(&s, 3);
	LinkStack_push(&s, 4);
	LinkStack_Print(&s);
	system("pause");
}