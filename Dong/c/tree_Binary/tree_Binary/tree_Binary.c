/*************************************************************************
 > File Name: tree_Binary.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-14
 >
 > 1）二叉树的链式存储
 > 2）二叉树的顺序存储
 > 3）二叉树的前序，中序，后续，层序遍历
 > 4）二叉树高度，节点个数
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
	struct Tree* q[MAX];//队列
	struct Tree* temp;
	int front, rear;
	front = rear = 0;
	if (t != NULL)
	{
		q[rear++] = t;
	}
	while (front != rear)
	{
		temp = q[front];
		front++;//模拟出队列
		printf("%c ", temp->data);
		if (temp->left != NULL)
		{
			q[rear++] = temp->left;
		}
		if (temp->right != NULL)
		{
			q[rear++] = temp->right;
		}
	}
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
		Creat_Tree_Line(t, 2 * index);
		//printf("请输入右孩子信息: ");
		Creat_Tree_Line(t, 2 * index + 1);
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
//层序遍历
void level(struct Tree_Line * t)
{
	int queue[MAX],front,rear,temp;
	front = rear = 0;
	if (t->data[1] != '0')
	{
		queue[rear++] = 1;
	}
	while (rear != front)
	{
		temp = queue[front];
		printf("%c ", t->data[temp]);
		front++;
		if (t->data[temp * 2] != '0')
		{
			queue[rear++] = temp * 2;
		}
		if (t->data[temp * 2 + 1] != '0')
		{
			queue[rear++] = temp * 2 + 1;
		}
	}

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