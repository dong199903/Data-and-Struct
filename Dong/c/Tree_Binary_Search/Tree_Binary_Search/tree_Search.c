/*************************************************************************
 > File Name: tree_Search.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-23
 >
 > 1）二叉搜索树的增，删，查
 > 2）支持重复数据的添加
 > 3）支持数据的中序遍历
 ************************************************************************/
#include "tree_Search.h"
#include <stdio.h>
void Insert_Tree(struct Tree ** t, int data)
{
	if ((*t) == NULL)
	{
		(*t) = (struct Tree*)malloc(sizeof(struct Tree));
		(*t)->data = data;
		(*t)->count = 1;
		(*t)->left = NULL;
		(*t)->right = NULL;
	}
	else
	{
		if (data < (*t)->data)
		{
			Insert_Tree(&((*t)->left), data);
		}
		else if (data > (*t)->data)
		{
			Insert_Tree(&((*t)->right), data);
		}
		else
		{
			(*t)->count++;
		}
	}
}

//0---没找到
//1---找到
void Find_Tree(struct Tree * t, int data)
{
	struct Tree * p = t;
	while (p != NULL)
	{
		if(data < p->data)
		{
			p = p->left;
		}
		else if(data>p->data){
			p = p->right;
		}
		else
		{
			printf("1\n");
			return;
		}
	}
	printf("0\n");
}

/*
删除操作分三种情况

第一类：该元素无左右孩子，直接删除
第二类：该元素有左孩子或者右孩子(有一个孩子),直接将该孩子节点与其父节点连接
第三类：该元素左右孩子都在
3.1：先向左走一步，一直向右走，直到走到一个叶子节点，将该叶子节点的赋给待删除节点元素。
3.2：先向右走一步，一直向左走，直到走到一个叶子节点，将该叶子节点的赋给待删除节点元素。
*/
void Del(struct Tree ** t)
{
	//左子树空，右不空
	if ((*t)->left == NULL && (*t)->right!=NULL)
	{
		struct Tree *p;
		p = (*t);
		(*t) = (*t)->right;
		free(p);
	}
	//右子树空，左不空
	if ((*t)->right == NULL && (*t)->left != NULL)
	{
		struct Tree *p;
		p = (*t);
		(*t) = (*t)->left;
		free(p);
	}
	//左右都空
	if ((*t)->right == NULL && (*t)->left != NULL)
	{
		free((*t));
	}
	//左右都不空
	if ((*t)->right != NULL && (*t)->left != NULL)
	{
		//采用左枝法，先向左走一步，一直向右边走
		struct Tree *p,*q;
		p = (*t)->left;
		while (p->right != NULL)
		{
			p = p->right;
		}
		//该节点右子树一定是空，左边不确定
		(*t)->data = p->data;
		if (p->left == NULL)
		{
			free(p);
		}
		else
		{
			q = p;
			p = q->left;
			free(q);
		}
	}
}
void Del_Tree(struct Tree ** t, int data)
{
	if ((*t) == NULL)
	{
		return;
	}
	if ((*t)->data == data)
	{
		Del(t);
	}
	else if ((*t)->data > data)
	{
		Del_Tree(&((*t)->left), data);
	}
	else
	{
		Del_Tree(&((*t)->right), data);
	}
}

void mid_Order(struct Tree * t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		mid_Order(t->left);
		for (int i = 0; i < t->count; i++)
		{
			printf("%d ", t->data);
		}
		mid_Order(t->right);
	}
}