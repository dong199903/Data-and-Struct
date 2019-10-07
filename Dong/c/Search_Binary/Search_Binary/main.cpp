/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-03
 >
 > 1）二分查找（找到一个目标数）
 > 2）二分查找（找到第一个等于目标的数）
 > 3）二分查找（找到最后一个等于目标的数）
 > 4）二分查找（找到第一个大于等于目标的数）
 > 5）二分查找（找到最后一个小于等于目标的数）
 ************************************************************************/
#include "Search.cpp"
#include <iostream>
using namespace std;
void main()
{
	Array a1;
	cout<<  a1.Search_Binary1(1);
	cout << a1.Search_Binary2(1);
	cout << a1.Search_Binary3(1);
	cout << a1.Search_Binary4(1);
	cout << a1.Search_Binary5(1);
	system("pause");
}