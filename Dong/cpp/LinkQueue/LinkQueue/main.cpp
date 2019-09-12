/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#include "LinkQueue.cpp"
void main()
{
	LinkQueue<int> q;
	q.inQueue(1);
	q.inQueue(2);
	q.inQueue(3);
	q.inQueue(4);
	q.inQueue(5);
	q.print_Queue();
	system("pause");
}