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
#ifndef TREE_BINARY_SEARCH_H
#define TREE_BINARY_SEARCH_H
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	int count;
	Node(int data);
	
};

class Tree
{
public:
	Node *root;
	Tree();
	Node* Insert_Tree(Node* node, int data);
	bool Find_Tree(int data);
	void mid_Order(Node* temp);
	Node* Del(Node* n);
	Node* Del_Tree(Node* n, int data);
};
#endif // !TREE_BINARY_SEARCH_H

