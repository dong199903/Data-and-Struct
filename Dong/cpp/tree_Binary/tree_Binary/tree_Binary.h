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
#ifndef TREE_BINARY_H
#define TREE_BINARY_H
#define MAX 100
#define ZERO 0

template<class T>
class Tree
{
public:
	Tree *left;
	Tree *right;
	T data;
	Tree();
	
	void pre_Order();
	void mid_Order();
	void post_Order();
	void level_Order();
	void destory();
	int getHigh();
	int getCount();
};

template<class T>
void creat_Tree(Tree<T>* & t);


/*------链式存储方法-------*/


/*-------顺序存储方法-------*/

template<class T>
class Tree_Line
{
public:
	T data[MAX];
	int count;//节点个数
	Tree_Line();
	void Creat_Tree_Line(int index);
	void pre( int index);
	void mid(int index);
	void post(int index);
	void level();
	int getHigh_Line(int index);
	int getCount_Line(int index);
};


#endif // !TREE_BINARY_H

