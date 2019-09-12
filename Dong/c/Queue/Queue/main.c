/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）顺序队列--存在假溢出现象
 > 2）支持入队和出队访问
 > 3）其它功能
 ************************************************************************/
#include "Queue.h"
void main()
{
	struct Queue queue;
	Queue_Init(&queue);
	inQueue(&queue, 1);
	inQueue(&queue, 2);
	inQueue(&queue, 3);
	inQueue(&queue, 4);
	inQueue(&queue, 5);
	Queue_Print(&queue);
	system("pause");
}