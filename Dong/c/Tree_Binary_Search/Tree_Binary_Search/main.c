/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）二叉搜索树的增，删，查
 > 2）支持重复数据的添加
 ************************************************************************/
#include "tree_Search.h"
#include <stdio.h>
void main()
{
	struct Tree *t = 0;//初始化指针指向
	Insert_Tree(&t, 7);
	Insert_Tree(&t, 2);
	Insert_Tree(&t, 9);
	Insert_Tree(&t, 15);
	Insert_Tree(&t, 1);
	Insert_Tree(&t, 1);
	Insert_Tree(&t, 7);
	Find_Tree(t, 7);
	Find_Tree(t, 3);
	mid_Order(t);
	printf("\n");
	Del_Tree(&t, 2);
	mid_Order(t);
	system("pause");
}