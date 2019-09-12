/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-29
 >
 > 1）双链表
 > 2）支持简单的增删改查
 > 3）支持逆序输出
 ************************************************************************/
#include "Double_List.cpp"
void main()
{
	Double_List<int> dlist;
	dlist.Double_List_Append(1);
	dlist.Double_List_Append(2);
	dlist.Double_List_Append(3);
	dlist.Double_List_Append(4);
	dlist.Double_List_Append(5);
	dlist.Double_List_Front(22);
	dlist.Double_List_Append(6);
	dlist.Double_List_Front(11);
	dlist.Double_List_Print();
	system("pause");
}