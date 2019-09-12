/*************************************************************************
 > File Name: tree_Binary.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-14
 >
 > 1）二叉树的链式存储
 > 2）二叉树的顺序存储
 > 3）实现了二叉树的基本操作(遍历，高度，节点个数)
 ************************************************************************/
#include "tree_Binary.h"
#include <stdio.h>
 /************** 递归创建 ********************/

struct Tree * creat_Tree()
{
	struct Tree *t;
	char ch;
	scanf_s("%c", &ch);
	getchar();
	if (ch == '#')//标记空
	{
		t = NULL;
		return t;
	}
	t = (struct Tree *)malloc(sizeof(struct Tree));
	t->data = ch;
	//printf("输入左孩子节点: ");
	t->left = creat_Tree();
	//printf("输入右孩子节点: ");
	t->right = creat_Tree();
	return t;
}

/************** 先序遍历 ********************/
void pre_Order(struct Tree * t)
{
	if (t == NULL)
	{
		return;
	}
	printf("%c", t->data);
	pre_Order(t->left);
	pre_Order(t->right);
}

/************** 中序遍历 ********************/
void mid_Order(struct Tree * t)
{
	if (t == NULL)
	{
		return;
	}
	mid_Order(t->left);
	printf("%c", t->data);
	mid_Order(t->right);
}

/************** 后序遍历 ********************/
void post_Order(struct Tree * t)
{
	if (t == NULL)
	{
		return;
	}
	mid_Order(t->left);
	mid_Order(t->right);
	printf("%c", t->data);
}

/************** 层序遍历 ********************/
void level_Order(struct Tree * t)
{
	//层序遍历，借助队列实现
	struct Queue q;
	Queue_Init(&q);

}

/************** 销毁树 ********************/
struct Tree  * destory(struct Tree  *t)
{
	if (t != NULL)
	{
		destory(t->left);
		destory(t->right);
		free(t);
		t = NULL;
		return t;
	}
	else {
		return t;
	}
}

/************** 求高度 ********************/
int getHigh(struct Tree * t)
{
	if (t == NULL)
	{
		return 0;
	}
	return getHigh(t->left) > getHigh(t->right) ? getHigh(t->left) + 1 : getHigh(t->right) + 1;
}
/************** 求节点个数 ********************/
int getCount(struct Tree * t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return getCount(t->left) + getCount(t->right) + 1;
	}
}

void Queue_Init(struct Queue * q)
{
	q->size = 1;
	q->front = q->rear = 0;
	q->data = (char*)malloc(sizeof(char) * q->size);
}
void Queue_push(struct Queue *q, char data)
{
	//队列满额,自动扩容
	if ((q->rear + 1) % q->size == q->front)
	{
		//队列元素个数
		int count = 0;
		int len = (q->rear - q->front) % q->size;
		q->size = 2 * q->size;
		char *p = (char*)malloc(sizeof(char)*q->size);
		for (int i = q->front; i < q->rear; i++)
		{
			p[count++] = q->data[i];
		}
		free(q->data);
		q->data = p;
		q->front = 0;
		q->rear = count;
		q->data[q->rear] = data;
		q->rear = (q->rear + 1) % q->size;
	}//队列未满，正常入队
	else {
		q->data[q->rear] = data;
		q->rear = (q->rear + 1) % q->size;
	}
}
char Queue_pop(struct Queue *q)
{
	if (q->front == q->rear)
	{
		return -1;
	}
	else {
		char data = q->data[q->front];
		q->front = (q->front + 1) % q->size;
		return data;
	}
}


/*--------------------------顺序存储方法---------------------------------*/
void Creat_Tree_Line(struct Tree_Line * t, int index)
{
	char ch;
	scanf_s("%c", &ch, 1);
	getchar();
	if (ch == '#')
	{
		return;
	}
	else
	{
		t->data[index] = ch;
		t->count++;
		//printf("请输入左孩子信息: ");
		Init_Tree(t, 2 * index);
		//printf("请输入右孩子信息: ");
		Init_Tree(t, 2 * index + 1);
	}
}
void Init_Tree(struct Tree_Line * t)
{
	t->count = 0;
	for (int i = 0; i < MAX; i++)
	{
		t->data[i] = '0';
	}
}
void pre(struct Tree_Line * t,int index)
{
	if (t->data[index] == '0')
	{
		return;
	}
	else
	{
		pre(t, 2 * index);
		printf("%c ", t->data[index]);
		pre(t, 2 * index +1);
	}
}
void mid(struct Tree_Line * t,int index)
{
	if (t->data[index] == '0')
	{
		return;
	}
	else
	{
		printf("%c ", t->data[index]);
		mid(t, 2 * index);
		mid(t, 2 * index + 1);
	}
}
void post(struct Tree_Line * t,int index)
{
	if (t->data[index] == '0')
	{
		return;
	}
	else
	{
		post(t, 2 * index);
		post(t, 2 * index + 1);
		printf("%c ", t->data[index]);
	}
}
void level(struct Tree_Line * t)
{

}
int getHigh_Line(struct Tree_Line * t,int index)
{
	if (t->data[index] == '0')
	{
		return 0;
	}
	else
	{
		return getHigh_Line(t, 2 * index) > getHigh_Line(t, 2 * index + 1) ? getHigh_Line(t, 2 * index) + 1 : getHigh_Line(t, 2 * index + 1);
	}
}
int getCount_Line(struct Tree_Line * t,int index)
{
	if (t->data[index] == '0')
	{
		return 0;
	}
	else
	{
		return getCount_Line(t, 2 * index) + getCount_Line(t, 2 * index + 1) + 1;
	}
}