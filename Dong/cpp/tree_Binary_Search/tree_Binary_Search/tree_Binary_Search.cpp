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
#include <iostream>
using namespace std;
#include "tree_Binary_Search.h"
Node::Node(int data)
{
	this->data = data;
	this->left = this->right = NULL;
	this->count = 0;
}
Tree::Tree()
{
	root = NULL;
}
Node* Tree::Insert_Tree(Node* node, int data)
{
	if (node == NULL)
	{
		node = new Node(data);
		node->count++;
		return node;
	}
	else {
		if (data<node->data)
		{
			node->left = Insert_Tree(node->left, data);
		}
		else if (data>node->data)
		{
			node->right = Insert_Tree(node->right, data);
		}
		else {
			node->count++;
		}
		return node;
	}
}
bool Tree::Find_Tree(int data)
{
	Node* temp;
	temp = this->root;
	while (temp != NULL)
	{
		if (data < temp->data)
		{
			temp = temp->left;
		}
		else if (data>temp->data) {
			temp = temp->right;
		}
		else
		{
			return true;
		}
	}
	return false;
}
void Tree::mid_Order(Node* temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{
		mid_Order(temp->left);
		for (int i = 0; i < temp->count; i++)
		{
			cout<<temp->data <<" ";
		}
		mid_Order(temp->right);
	}
}
Node* Tree::Del(Node* n)
{
	//左子树空，右不空
	if (n->left == NULL && n->right != NULL)
	{
		Node* p;
		p = n;
		n = n->right;
		p = NULL;
		return n;

	}
	//右子树空，左不空
	if (n->right == NULL && n->left != NULL)
	{
		Node* p;
		p = n;
		n = n->left;
		p = NULL;
		return n;

	}
	//左右都空
	if (n->right == NULL && n->left == NULL)
	{
		n = NULL;
		return n;

	}
	//左右都不空
	if (n->right != NULL && n->left != NULL)
	{

		//采用左枝法，先向左走一步，一直向右边走
		Node* p, *q;
		p = n->left;
		while (p->right != NULL)
		{
			p = p->right;
		}
		//该节点右子树一定是空，左边不确定
		n->data = p->data;
		if (p->left == NULL)
		{
			p = NULL;
		}
		else
		{
			q = p;
			p = q->left;
			q = NULL;
		}
		return n;
	}
	return n;
}
Node* Tree::Del_Tree(Node* n, int data)
{
	if (n == NULL)
	{
		return n;
	}
	if (n->data == data)
	{
		n = Del(n);
	}
	else if (n->data > data)
	{
		n->left = Del_Tree(n->left, data);
	}
	else
	{
		n->right = Del_Tree(n->right, data);
	}
	return n;
}