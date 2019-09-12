/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）循环双链表
 > 2）支持增删该查基本功能
 > 3）支持逆序
 ************************************************************************/
#include "Circle_Double_List.h"
void main()
{
	struct CDouble_List list;
	CDouble_List_Init(&list);
	CDouble_List_Append(&list, 1);
	CDouble_List_Append(&list, 2);
	CDouble_List_Append(&list, 3);
	CDouble_List_Append(&list, 4);
	CDouble_List_Append(&list, 5);
	CDouble_List_Print(&list);
	CDouble_List_Print_Reverse(&list);
	CDouble_List_Front(&list, 22);
	CDouble_List_Front(&list, 11);
	CDouble_List_Insert(&list, 3, 33);
	CDouble_List_Del(&list, 6);
	CDouble_List_Print(&list);
	CDouble_List_Print_Reverse(&list);
	CDouble_List_Destroy(&list);
	printf("%d", &list==0);
	system("pause");
}