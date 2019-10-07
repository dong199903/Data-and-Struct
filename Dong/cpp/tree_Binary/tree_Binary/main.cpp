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
#include "tree_Binary.cpp"
void main()
{
	/*
	Tree<char> *t;
	creat_Tree(t);
	t->pre_Order();
	cout << endl;
	t->mid_Order();
	cout << endl;
	t->post_Order();
	cout << endl;
	cout << t->getCount() << endl;
	cout << t->getHigh() << endl;
	t->level_Order();
	*/
	
	Tree_Line<char> t;
	t.Creat_Tree_Line(1);
	cout << t.getCount_Line(1) << endl;
	cout << t.getHigh_Line(1) << endl;
	t.pre(1);
	t.mid(1);
	t.post(1);
	t.level();
	system("pause");
}