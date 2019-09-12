/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）在队列版本二基础上进一步完善，解决了队列搬移数据问题
 > 2）在此基础上，增加了自动扩容
 > 3）循环队列空:fornt==rear
 > 3）循环队列满:(rear+1)%size = front
 > 3）循环队列元素个数:(rear-front+size)%size
 ************************************************************************/
#include "Queue.h"
void main()
{
	struct Queue q;
	Queue_Init(&q);
	Queue_push(&q, 1);
	Queue_push(&q, 2);
	Queue_push(&q, 3);
	Queue_push(&q, 4);
	Queue_push(&q, 5);
	Queue_Print(&q);
	printf("%d\n", Queue_pop(&q));
	system("pause");
}