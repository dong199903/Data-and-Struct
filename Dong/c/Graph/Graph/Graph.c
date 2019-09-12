/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1��
 > 2��
 > 3��
 ************************************************************************/
#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
 //ͼ�ĳ�ʼ��--�ڽӾ���
void Init_Graph_Matrix(struct MGraph *g)
{
	g->numEdges = g->numVretexes = 0;
}

//ͼ�Ĵ���--�ڽӾ���
void creat_Graph_Matrix(struct MGraph *g)
{
	int x1, x2;
	printf("������ͼ�Ķ�������ͱߵĸ���: ");
	scanf_s("%d%d", &g->numVretexes, &g->numEdges);
	g->vetex = (char*)malloc(sizeof(char)*g->numVretexes);
	g->data = (int**)malloc(sizeof(int*)*g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		g->data[i] = (int*)malloc(sizeof(int)*g->numVretexes);
	}
	for (int i = 0; i < g->numVretexes; i++)
	{
		for (int j = 0; j < g->numVretexes; j++)
		{
			g->data[i][j] = 0;//��ʼ��Ϊ������
		}
	}
	for (int i = 0; i < g->numEdges; i++)
	{
		getchar();//���տո�
		printf("�������%d��������Ϣ: ", i + 1);
		scanf_s("%c", &g->vetex[i]);
	}
	
	for (int i = 0; i < g->numEdges; i++)
	{
		printf("�������%d���������˵���±� ",i+1);
		scanf_s("%d%d", &x1, &x2);
		g->data[x1][x2] = 1;//�������������ӹ��ɱ�
		g->data[x2][x1] = 1;
	}
}

//ͼ�Ĵ�ӡ--�ڽӾ���
void print_Graph_Matrix(struct MGraph *g)
{
	printf("ͼ�Ķ�����: ");
	for (int i = 0; i < g->numVretexes; i++)
	{
		printf("%c ", g->vetex[i]);
	}
	printf("\nͼ���ڽӾ�����\n");
	for (int i = 0; i < g->numVretexes; i++)
	{
		for (int j = 0; j < g->numVretexes; j++)
		{
			printf("%d ", g->data[i][j]);
		}
		printf("\n");
	}
}




//ͼ�Ĵ���--�ڽӱ�
void creat_Graph_List(struct LGraph_List *g)
{
	int x1, x2;
	printf("������ͼ�Ķ�������ͱ߸��� ");
	scanf_s("%d%d", &g->numVretexes, &g->numEdges);
	g->list = (struct LGraph*)malloc(sizeof(struct LGraph)*g->numVretexes);
	printf("������ͼ�Ķ�����Ϣ ");
	for (int i = 0; i < g->numVretexes; i++)
	{
		getchar();
		scanf_s("%c", &g->list[i].data);
		printf("%c", g->list[i].data);
		g->list[i].head = NULL;
	}
	printf("������ͼ�ı���Ϣ\n ");
	for (int i = 0; i < g->numEdges; i++)
	{
		printf("�������%d���ߵĶ˵��±�: ", i + 1);
		scanf_s("%d%d", &x1, &x2);
		struct Node *s1, *s2;
		s1 = (struct Node*)malloc(sizeof(struct Node));
		s2 = (struct Node*)malloc(sizeof(struct Node));
		s1->index = x1;
		s2->index = x2;
		s1->next = g->list[x2].head;
		g->list[x2].head = s1;
		s2->next = g->list[x1].head;
		g->list[x1].head = s2;
	}
}

//ͼ�Ĵ�ӡ--�ڽӱ�
void print_Graph_List(struct LGraph_List *g)
{
	printf("ͼ��������Ϣ��\n");
	for (int i = 0; i < g->numVretexes; i++)
	{
		printf("%c--->", g->list[i].data);
		struct Node *s = g->list[i].head;
		while (s != NULL)
		{
			printf("%c--->", g->list[s->index].data);
			s = s->next;
		}
		printf("\n");
	}
}
