/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-29
 >
 > 1）双链表
 > 2）支持简单增删改查
 > 3）支持逆序输出(双链表的特点)
 ************************************************************************/
#include "Double_List.h"
void main()
{
	struct Double_List dlist;
	Double_List_Init(&dlist);
	Double_List_Append(&dlist, 1);
	Double_List_Append(&dlist, 2);
	Double_List_Append(&dlist, 3);
	Double_List_Append(&dlist, 4);
	Double_List_Append(&dlist, 5);
	Double_List_Print(&dlist);
	Double_List_Front(&dlist, 22);
	Double_List_Front(&dlist, 11);
	Double_List_Print(&dlist);
	Double_List_Insert(&dlist, 4, 44);
	Double_List_Del(&dlist, 5);
	Double_List_Print(&dlist);
	Double_List_Print_Reverse(&dlist);
	system("pause");
}