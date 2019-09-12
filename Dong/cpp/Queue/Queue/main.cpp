/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）顺序队列
 > 2）基本的入队列和出队列
 > 3）
 ************************************************************************/
#include "Queue.cpp"
void main()
{
	Queue<int> q;
	q.inQueue(1);
	q.inQueue(2);
	q.inQueue(3);
	q.inQueue(4);
	q.inQueue(5);
	q.Queue_Print();
	system("pause");
}