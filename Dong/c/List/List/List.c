/*************************************************************************
 > File Name: List.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#include"List.h"
//初始化头节点
void List_Init(struct List* list)
{
	list->size = 0;
	list->head = (struct Node*)malloc(sizeof(struct Node));
	list->head->next = NULL;
}
//尾插法
void List_Append(struct List* list,int data)
{
	struct Node* temp,*p;
	p = list->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
	list->size++;
}
//头插法
void List_Front(struct List* list,int data)
{
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->data = data;
	p->next = list->head->next;
	list->head->next = p;
	list->size++;
}
//指定位置插入
void List_Insert(struct List* list, int index, int data)
{
	if (index <= 0 || index > (list->size + 1))
	{
		return;
	}
	else {
		//先找到目标位置的前一个位置p
		struct Node *p,*temp;
		p = list->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		temp->next = p->next;
		p->next = temp;
		list->size++;
	}
}
//删除指定位置节点
void List_Del(struct List* list, int index)
{
	if (index <= 0 || index > list->size)
	{
		return;
	}
	else {
		//先找到目标位置的前一个位置p
		struct Node *p, *temp;
		p = list->head;
		for (int i = 1; i < index; i++)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = p->next->next;
		free(temp);
		temp = NULL;
		list->size--;
	}
	
}
//销毁单链表(都在堆区，手动逐个释放)
void List_Destory(struct List* list)
{
	struct Node *p, *q;
	p = list->head;
	q = p->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
	p = NULL;
}
void List_Print(struct List* list)//遍历单链表
{
	struct Node *p = list->head->next;
	while (p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}