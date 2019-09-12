/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）相对于队列第一种的优化-解决了顺序队列的假溢出现象
 > 2）缺点:数据搬移问题(时间复杂度提高了)
 > 3）优点：解决队列空间利用不足问题，还实现了空间满额利用下的自动扩容
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
	system("pause");
}