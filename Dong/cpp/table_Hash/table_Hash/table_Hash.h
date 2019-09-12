/*************************************************************************
 > File Name: table_Hash.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-12
 >
 > 1）散列表初始大小为10，根据数据的增多，智能扩容。
 > 2）扩容条件是数据个数大于装载因子*散列表大小，扩容系数为2
 > 3）装载因子最大为0.75(工业基本都是0.75的上限)
 ************************************************************************/
#ifndef TABLE_HAHS_H
#define TABLE_HAHS_H
class Hash_Table_Array
{
public:
	int maxSize;//最大存储量
	int *data;
	int size;//当前存储数据个数
	Hash_Table_Array();
	void Insert(int data);//插入数据
	int isFind(int data);//查找数据是否存在
};


class Node
{
public:
	int data;
	Node* next;
};
class Hash_Table_List
{
public:
	Node *head;//边表数组
	int length;//边表的长度
	int len;//当前总共存储的数据量
	Hash_Table_List();
	void Insert(int data);
	int isFind(int data);
};
#endif // !TABLE_HAHS_H

