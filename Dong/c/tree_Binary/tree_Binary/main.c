/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-14
 >
 > 1������������ʽ�洢
 > 2����������˳��洢
 > 3����������ǰ�����򣬺������������
 > 4���������߶ȣ��ڵ����
 ************************************************************************/
#include "tree_Binary.h"
void main()
{
	/*
	struct Tree *t = creat_Tree();
	pre_Order(t);
	printf("\n");
	mid_Order(t);
	printf("\n");
	post_Order(t);
	printf("\n");
	printf("%d\n", getHigh(t));
	level_Order(t);
	t = destory(t);
	printf("%d\n", t==0);
	printf("%d\n", getHigh(t));
	*/
	struct Tree_Line t1;	
	Init_Tree(&t1);
	Creat_Tree_Line(&t1, 1);
	pre(&t1, 1);
	printf("\n");
	mid(&t1, 1);
	printf("\n");
	post(&t1, 1);
	printf("\n");
	level(&t1, 1);
	system("pause");
}