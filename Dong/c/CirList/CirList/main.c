/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）首尾相连的循环单链表
 > 2）支持增删改查等基本操作
 ************************************************************************/
#include "CirList.h"
void main()
{
	struct CirList clist;
	CirList_Init(&clist);
	CirList_Append(&clist, 1);
	CirList_Append(&clist, 2);
	CirList_Append(&clist, 3);
	CirList_Append(&clist, 4);
	CirList_Append(&clist, 5);
	CirList_Print(&clist);
	CirList_Front(&clist, 22);
	CirList_Front(&clist, 11);
	CirList_Insert(&clist, 4, 44);
	CirList_Print(&clist);
	system("pause");
}