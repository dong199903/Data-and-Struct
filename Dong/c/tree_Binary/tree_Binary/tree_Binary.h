/*************************************************************************
 > File Name: tree_Binary.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-14
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#ifndef TREE_BINARY_H
#define TREE_BINARY_H
#define MAX 100
#define ZERO 0
struct Tree
{
	struct Tree *left;
	struct Tree *right;
	char data;
};



/*------链式存储方法-------*/

struct Tree * creat_Tree();
void pre_Order(struct Tree * t);
void mid_Order(struct Tree * t);
void post_Order(struct Tree * t);
void level_Order(struct Tree * t);
struct Tree  * destory(struct Tree * t);
int getHigh(struct Tree * t);
int getCount(struct Tree * t);
/*-------顺序存储方法-------*/


struct Tree_Line
{
	char data[MAX];
	int count;//节点个数
};
void Init_Tree(struct Tree_Line * t);
void Creat_Tree_Line(struct Tree_Line * t,int index);
void pre(struct Tree_Line * t,int index);
void mid(struct Tree_Line * t,int index);
void post(struct Tree_Line * t,int index);
void level(struct Tree_Line * t);
int getHigh_Line(struct Tree_Line * t,int index);
int getCount_Line(struct Tree_Line * t,int index);



//赋值队列进行层序遍历
struct Queue
{
	int rear;
	int front;
	char *data;
	int size;
};

void Queue_Init(struct Queue * q);
void Queue_push(struct Queue *q, char data);
char Queue_pop(struct Queue *q);
#endif // !TREE_BINARY_H

