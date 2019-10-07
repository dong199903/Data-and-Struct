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
#include "tree_Binary.h"
#include <queue>

template<class T>
void creat_Tree(Tree<T>* & t) //拿到这个二叉树指针
{
	char ch;
	cin >> ch;
	getchar();
	if (ch == '#')//标记空
	{
		t = NULL;
	}
	else
	{
		t = new Tree<T>;
		t->data = ch;
		creat_Tree(t->left);
		creat_Tree(t->right);
	}
	
}

template<class T>
Tree<T>::Tree()
{
	this->left = this->right = NULL;
}


template<class T>
void Tree<T>::pre_Order()
{
	if (this == NULL)
	{
		return;
	}
	cout<<this->data<<" ";
	this->left->post_Order();
	this->right->pre_Order();
}



template<class T>
void Tree<T>::mid_Order()
{
	if (this == NULL)
	{
		return;
	}
	this->left->mid_Order();
	cout<<this->data<<" ";
	this->right->mid_Order();
}


template<class T>
void Tree<T>::post_Order()
{
	if (this == NULL)
	{
		return;
	}
	this->left->mid_Order();
	this->right->mid_Order();
	cout<<this->data<<" ";
}

//层序遍历
template<class T>
void Tree<T>::level_Order()
{
	queue<Tree *> q;
	Tree* temp;
	if (this != NULL)
	{
		q.push(this);//根节点入队
	}
	while (!q.empty())
	{
		temp = q.front();
		cout << temp->data << " ";
		q.pop();//出去的同时，把它两个儿子入队
		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
}


template<class T>
void Tree<T>::destory()
{
	if (this != NULL)
	{
		this->left->destory();
		this->right->destory();
		delete this;
	}
}



template<class T>
int Tree<T>::getHigh()
{
	if (this == NULL)
	{
		return 0;
	}
	return this->left->getHigh() > this->right->getHigh() ? this->left->getHigh()+1 : this->right->getHigh() + 1;
}



template<class T>
int Tree<T>::getCount()
{
	if (this == NULL)
	{
		return 0;
	}
	else
	{
		return this->left->getCount() + this->right->getCount() + 1;
	}
}


/*二叉树的顺序存储*/
template<class T>
Tree_Line<T>::Tree_Line()
{
	this->count = 0;
	for (int i = 0; i < MAX; i++)
	{
		this->data[i] = '0';
	}
}




template<class T>
void Tree_Line<T>::Creat_Tree_Line(int index)
{
	char ch;
	cin >> ch;
	getchar();
	if (ch == '#')
	{
		return;
	}
	else
	{
		this->data[index] = ch;
		this->count++;
		//printf("请输入左孩子信息: ");
		Creat_Tree_Line(2 * index);
		//printf("请输入右孩子信息: ");
		Creat_Tree_Line(2 * index + 1);
	}
}


template<class T>
void Tree_Line<T>::pre(int index)
{
	if (this->data[index] == '0')
	{
		return;
	}
	else
	{
		this->pre(2 * index);
		cout<<this->data[index]<<" ";
		this->pre(2 * index + 1);
	}
}


template<class T>
void Tree_Line<T>::mid(int index)
{
	if (this->data[index] == '0')
	{
		return;
	}
	else
	{
		cout<<this->data[index]<<" ";
		mid(2 * index);
		mid(2 * index + 1);
	}
}


template<class T>
void Tree_Line<T>::post(int index)
{
	if (this->data[index] == '0')
	{
		return;
	}
	else
	{
		post(2 * index);
		post(2 * index + 1);
		cout<<this->data[index]<<" ";
	}
}


/*层序遍历*/
template<class T>
void Tree_Line<T>::level()
{
	queue<int> q;
	int temp;
	if (this->data[1] != NULL)
	{
		q.push(1);
	}
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << this->data[temp] << " ";
		if (this->data[temp * 2] != '0')
		{
			q.push(temp*2);
		}
		if (this->data[temp * 2 + 1] != '0')
		{
			q.push(temp*2+1);
		}
	}
}


template<class T>
int Tree_Line<T>::getHigh_Line(int index)
{
	if (this->data[index] == '0')
	{
		return 0;
	}
	else
	{
		return getHigh_Line(2 * index) > getHigh_Line(2 * index + 1) ? getHigh_Line( 2 * index) + 1 : getHigh_Line( 2 * index + 1);
	}
}


template<class T>
int Tree_Line<T>::getCount_Line(int index)
{
	if (this->data[index] == '0')
	{
		return 0;
	}
	else
	{
		return getCount_Line(2 * index) + getCount_Line( 2 * index + 1) + 1;
	}
}