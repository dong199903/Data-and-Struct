/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-12
 >
 > 1）散列表初始大小为10，根据数据的增多，智能扩容。
 > 2）扩容条件是数据个数大于装载因子*散列表大小，扩容系数为2
 > 3）装载因子最大为0.75(工业基本都是0.75的上限)
 ************************************************************************/
#include "table_Hash.h"
#include <iostream>
using namespace std;
void main()
{
	Hash_Table_Array t1;
	t1.Insert(3);
	t1.Insert(2);
	t1.Insert(1);
	t1.Insert(4);
	t1.Insert(8);
	t1.Insert(9);
	t1.Insert(10);
	t1.Insert(11);
	t1.Insert(50);
	cout << t1.isFind(11) << endl;
	Hash_Table_List t2;
	t2.Insert(3);
	t2.Insert(2);
	t2.Insert(1);
	t2.Insert(4);
	t2.Insert(8);
	t2.Insert(9);
	t2.Insert(10);
	t2.Insert(11);
	t2.Insert(50);
	cout << t2.isFind(11) << endl;
	system("pause");
}