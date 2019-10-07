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
#include "DFS.cpp"
void main()
{
	MGraph<char> m1;
	m1.creat_Graph_Matrix();
	m1.print_Graph_Matrix();
	m1.DFS_Matrix();
	m1.DFS_Matrix_Stack(0);
	m1.Find_Path('a', 'd');
	//LGraph_List<char> m2;
	//m2.creat_Graph_List();
	//m2.DFS_List_Stack();
	//m2.DFS_List();
	system("pause");
}