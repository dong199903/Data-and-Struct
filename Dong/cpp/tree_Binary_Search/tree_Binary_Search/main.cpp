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
#include "tree_Binary_Search.h"
#include <iostream>
void main()
{
	Tree t1;
	t1.root = t1.Insert_Tree(t1.root, 1);
	t1.root = t1.Insert_Tree(t1.root, 2);
	t1.root = t1.Insert_Tree(t1.root, 3);
	t1.root = t1.Insert_Tree(t1.root, 4);
	t1.root = t1.Insert_Tree(t1.root, 5);
	t1.root = t1.Del_Tree(t1.root, 5);
	t1.mid_Order(t1.root);
	system("pause");
}