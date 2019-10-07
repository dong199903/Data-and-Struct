/*************************************************************************
 > File Name: hash_Table.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）散列表初始大小为10，根据数据的增多，智能扩容。
 > 2）扩容条件是数据个数大于装载因子*散列表大小，扩容系数为2
 > 3）装载因子最大为0.75(工业基本都是0.75的上限)
 ************************************************************************/
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

//哈希表的数组存储法
struct Hash_Table_Array
{
	int maxSize;//最大存储量
	int *data;
	int size;//当前存储数据个数
};
void Init_Hash_Table_Array(struct Hash_Table_Array * h);
void Insert_Array_Hash(struct Hash_Table_Array * h,int data);//插入数据
int isFind_Array_Hash(struct Hash_Table_Array * h,int data);//查找数据是否存在


//哈希表的边表存储法
struct Node
{
	int data;
	struct Node* next;
};
struct Hash_Table_List
{
	struct Node *head;//边表数组
	int length;//边表的长度
	int len;//当前总共存储的数据量
};

void Init_Hash_Table_List(struct Hash_Table_List * h);
void Insert_List_Hash(struct Hash_Table_List * h,int data);
int isFind_List_Hash(struct Hash_Table_List * h, int data);
#endif // !HASH_TABLE_H

