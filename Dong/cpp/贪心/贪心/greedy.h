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
#ifndef GREEDY_H
#define GREEDY_H

void back_Pack();

struct plan
{
	int begin;
	int last;
};
void plan_Acivity();

void load();
class myRole
{
public:
	bool operator()(struct plan& p1, struct plan& p2);
};

#endif // !GREEDY_H

