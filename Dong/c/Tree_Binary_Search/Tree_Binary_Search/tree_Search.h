/*************************************************************************
 > File Name: tree_Search.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-23
 >
 > 1）二叉搜索树的增，删，查
 > 2）支持重复数据的添加
 > 3）支持数据的中序遍历
 ************************************************************************/
#ifndef TREE_SEARCH_H
#define TREE_SEARCH_H
struct Tree
{
	struct Tree *left;
	struct Tree *right;
	int data;
	int count;//为了统计相同数据出现的次数
};
void Insert_Tree(struct Tree ** t,int data);
void Find_Tree(struct Tree * t, int data);
void Del_Tree(struct Tree ** t, int data);
void Del(struct Tree ** t);
void mid_Order(struct Tree * t);
#endif // !TREE_SEARCH_H

