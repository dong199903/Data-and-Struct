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
#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H
struct Node
{
	int data;
	int *next;
};
struct LinkStack
{
	struct Node *head;//头节点
	int size;
};

void LinkStack_Init(struct LinkStack * s);
void LinkStack_push(struct LinkStack * s,int data);
int LinkStack_pop(struct LinkStack * s);
void LinkStack_Print(struct LinkStack * s);
#endif // !LINKSTACK_H
