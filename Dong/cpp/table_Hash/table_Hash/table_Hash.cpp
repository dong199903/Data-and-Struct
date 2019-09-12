/*************************************************************************
 > File Name: table_Hash.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-12
 >
 > 1）散列表初始大小为10，根据数据的增多，智能扩容，并将之前元素重新映射。
 > 2）扩容条件是数据个数大于装载因子*散列表大小，扩容系数为2
 > 3）装载因子最大为0.75(工业基本都是0.75的上限)
 > 4）为了接近散列表扩容思想，实现较为复杂。
 ************************************************************************/
#include "table_Hash.h"
#include <iostream>
using namespace std;

Hash_Table_Array::Hash_Table_Array()
{
	this->maxSize = 10;
	this->data = new int[this->maxSize];
	this->size = 0;
	for (int i = 0; i < this->maxSize; i++)
	{
		this->data[i] = 99999;//标记数组初始值(标空)
	}
}

void Hash_Table_Array::Insert(int data)
{
	int *newData,i,index;
	//1.每次插入数据前，先检测是否超过了最大装载因子
	if (this->size*1.0 >= this->maxSize*0.75)
	{
		newData = new int[this->maxSize * 2];
		for (i = 0; i < this->maxSize * 2; i++)
		{
			newData[i] = 99999;
		}
		//将原数据重新映射地址
		for (i = 0; i < this->maxSize;i++)
		{
			
			if (this->data[i] != 99999)
			{
				index = this->data[i] % (2 * this->maxSize);
				while (newData[index] != 99999)
				{
					index = (index + 1) % (2 * this->maxSize);
				}
				newData[index] = this->data[i];
			}
		}
		this->maxSize = 2 * this->maxSize;
		delete[] this->data;
		this->data = newData;
		index = data % this->maxSize;
		//开放地址法
		while (this->data[index] != 99999)
		{
			index = (index + 1) % this->maxSize;
		}
		this->data[index] = data;
		this->size++;
	}
	else {
		index = data % this->maxSize;
		//开放地址法
		while (this->data[index]!=99999)
		{
			index = (index + 1) % this->maxSize;
		}
		this->data[index] = data;
		this->size++;
	}
}


int Hash_Table_Array::isFind(int data)
{
	int index,sum=0;
	index = data % this->maxSize;
	//开放地址法
	while (this->data[index] != data)
	{
		index = (index + 1) % this->maxSize;
		sum++;
		//如果继续查找数据为空，或者回到原点，表示该数据不存在
		if (this->data[index] == 99999 || sum == this->maxSize)
		{
			return -1;
		}
	}
	return index;
}


Hash_Table_List::Hash_Table_List()
{
	int i;
	this->len = 0;
	this->length = 10;
	this->head = new Node[10];
	for (i = 0; i < 10; i++)
	{
		this->head[i].data = i;
		this->head[i].next = NULL;
	}
}
//链式法处理
void Hash_Table_List::Insert(int data)
{
	//超过装载因子，自动扩容
	Node *newHead,*p,*q;
	int i,value,index;
	if (this->len*1.0 >= this->length * 0.75)
	{
		newHead = new Node[this->length * 2];
		for (i = 0; i < this->length * 2; i++)
		{
			newHead[i].data = i;
			newHead[i].next = NULL;
		}
		//将旧数据，逐个重新映射到新的散列表上
		for (i = 0; i < this->length; i++)
		{
			p = this->head[i].next;
			while (p)
			{
				//原数据
				value = p->data;
				//映射后地址
				index = p->data % (this->length * 2);
				//根据地址，放到新散列表的后面
				q = new Node;
				q->data = value;
				q->next = newHead[index].next;
				newHead[index].next = q;
				//删除旧散列表边表结构
				this->head[i].next = p->next;
				delete p;
				p = this->head[i].next;
			}
		}
		if (this->head)
		{
			delete[] this->head;
		}
		this->head = newHead;
		this->length = this->length * 2;

		//插入数据进去
		index = data % this->length;
		q = new Node;
		q->data = data;
		q->next = this->head[index].next;
		this->head[index].next = q;
		this->len++;
	}
	//没有超过装载因子，不需要扩容
	else
	{
		index = data % this->length;
		q = new Node;
		q->data = data;
		q->next = this->head[index].next;
		this->head[index].next = q;
		this->len++;
	}
}


int Hash_Table_List::isFind(int data)
{
	Node *p;
	int index;
	index = data %this->length;
	p = this->head[index].next;
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