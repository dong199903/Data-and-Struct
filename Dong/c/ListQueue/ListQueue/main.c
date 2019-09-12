/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-01(建军节)
 >
 > 1）链队的实现
 > 2）基本的入队列和出队列
 > 3）
 ************************************************************************/
#include "List_Queue.h"
void main()
{
	struct Link_Queue q;
	Link_Queue_Init(&q);
	inQueue(&q, 1);
	inQueue(&q, 2);
	inQueue(&q, 3);
	inQueue(&q, 4);
	inQueue(&q, 5);
	Link_Queue_Print(&q);
	system("pause");
}