/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）散列表初始大小为10，根据数据的增多，智能扩容。
 > 2）扩容条件是数据个数大于装载因子*散列表大小，扩容系数为2
 > 3）装载因子最大为0.75(工业基本都是0.75的上限)
 ************************************************************************/
#include "hash_Table.h"
#include <stdio.h>
#include <stdlib.h>
//初始化--哈希表数组
void Init_Hash_Table_Array(struct Hash_Table_Array * h)
{
	h->maxSize = 10;
	h->data = (int *)malloc(sizeof(int)*h->maxSize);
	h->size = 0;
	for (int i = 0; i < h->maxSize; i++)
	{
		h->data[i] = 99999;//标记数组初始值(标空)
	}
}
 //插入数据--哈希表数组
void Insert_Array_Hash(struct Hash_Table_Array * h, int data)
{
	int *newData, i, index;
	//1.每次插入数据前，先检测是否超过了最大装载因子
	if (h->size*1.0 >= h->maxSize*0.75)
	{
		newData = (int *)malloc(sizeof(int)* (h->maxSize*2));
		for (i = 0; i < h->maxSize * 2; i++)
		{
			newData[i] = 99999;
		}
		//将原数据重新映射地址
		for (i = 0; i < h->maxSize; i++)
		{

			if (h->data[i] != 99999)
			{
				index = h->data[i] % (2 * h->maxSize);
				while (newData[index] != 99999)
				{
					index = (index + 1) % (2 * h->maxSize);
				}
				newData[index] = h->data[i];
			}
		}
		h->maxSize = 2 * h->maxSize;
		free(h->data);//释放调旧内存
		h->data = newData;
		index = data % h->maxSize;
		//开放地址法
		while (h->data[index] != 99999)
		{
			index = (index + 1) % h->maxSize;
		}
		h->data[index] = data;
		h->size++;
	}
	else {
		index = data % h->maxSize;
		//开放地址法
		while (h->data[index] != 99999)
		{
			index = (index + 1) % h->maxSize;
		}
		h->data[index] = data;
		h->size++;
	}
}
//查找数据是否存在--哈希表数组
int isFind_Array_Hash(struct Hash_Table_Array * h, int data)
{
	int index, sum = 0;
	index = data % h->maxSize;
	//开放地址法
	while (h->data[index] != data)
	{
		index = (index + 1) % h->maxSize;
		sum++;
		//如果继续查找数据为空，或者回到原点，表示该数据不存在
		if (h->data[index] == 99999 || sum == h->maxSize)
		{
			return -1;
		}
	}
	return index;
}

//初始化--哈希表边表
void Init_Hash_Table_List(struct Hash_Table_List * h)
{
	int i;
	h->len = 0;
	h->length = 10;
	h->head = (struct Node *)malloc(sizeof(struct Node) * h->length);
	for (i = 0; i < 10; i++)
	{
		h->head[i].data = i;
		h->head[i].next = NULL;
	}
}
//插入数据--哈希表边表
void Insert_List_Hash(struct Hash_Table_List * h, int data)
{
	struct Node *newHead, *p, *q;
	int i, value, index;
	if (h->len*1.0 >= h->length * 0.75)
	{
		newHead = (struct Node *)malloc(sizeof(struct Node) * (h->length*2));
		for (i = 0; i < h->length * 2; i++)
		{
			newHead[i].data = i;
			newHead[i].next = NULL;
		}
		//将旧数据，逐个重新映射到新的散列表上
		for (i = 0; i < h->length; i++)
		{
			p = h->head[i].next;
			while (p)
			{
				//原数据
				value = p->data;
				//映射后地址
				index = p->data % (h->length * 2);
				//根据地址，放到新散列表的后面
				q = (struct Node *)malloc(sizeof(struct Node));
				q->data = value;
				q->next = newHead[index].next;
				newHead[index].next = q;
				//删除旧散列表边表结构
				h->head[i].next = p->next;
				free(p);
				p = h->head[i].next;
			}
		}
		if (h->head)
		{
			free(h->head);
		}
		h->head = newHead;
		h->length = h->length * 2;

		//插入数据进去
		index = data % h->length;
		q = (struct Node *)malloc(sizeof(struct Node));
		q->data = data;
		q->next = h->head[index].next;
		h->head[index].next = q;
		h->len++;
	}
	//没有超过装载因子，不需要扩容
	else
	{
		index = data % h->length;
		q = (struct Node *)malloc(sizeof(struct Node));
		q->data = data;
		q->next = h->head[index].next;
		h->head[index].next = q;
		h->len++;
	}
}
//查找数据是否存在--哈希表边表
int isFind_List_Hash(struct Hash_Table_List * h, int data)
{
	struct Node *p;
	int index;
	index = data %h->length;
	p = h->head[index].next;
	while (p != NULL && p->data != data)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return -1;//没找到
	}
	//返回链表的下标
	else {
		return index;
	}
}