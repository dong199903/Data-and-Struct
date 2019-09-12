/*************************************************************************
 > File Name: DAG.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-24
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#include "DAG.h"
#include <stdio.h>
#include <stdlib.h>
//逆邻接表
void creat_Graph_List(struct LGraph_List *g)
{
	int x1, x2;
	printf("请输入图的顶点个数和边个数 ");
	scanf_s("%d%d", &g->numVretexes, &g->numEdges);
	g->list = (struct LGraph*)malloc(sizeof(struct LGraph)*g->numVretexes);
	printf("请输入图的顶点信息 ");
	for (int i = 0; i < g->numVretexes; i++)
	{
		getchar();
		scanf_s("%c", &g->list[i].data);
		printf("%c", g->list[i].data);
		g->list[i].head = NULL;
		g->list[i].degree = 0;//每个点的入度为0
	}
	printf("请输入图的边信息\n ");
	for (int i = 0; i < g->numEdges; i++)
	{
		printf("请输入第%d条边的端点下标: ", i + 1);
		scanf_s("%d%d", &x1, &x2);//x1指向了x2,x2边表后面添加x1
		struct Node *s1;
		s1 = (struct Node*)malloc(sizeof(struct Node));
		s1->index = x1;
		s1->next = g->list[x2].head;
		g->list[x2].head = s1;
		g->list[x2].degree++;//入度增加1
	}
}
//拓扑排序的KaHn算法
void KaHn(struct LGraph_List *g)
{
	//辅助栈存储入度为0的点
	int *stack, top=-1,i,temp,count=0;
	stack = (int*)malloc(sizeof(int)*g->numVretexes);
	for (i = 0; i < g->numVretexes; i++)
	{
		if (g->list[i].degree == 0)
		{
			stack[++top] = i;//存储的是点的下标
		}
	}
	//栈空退出
	while (top != -1)
	{
		//出栈栈顶元素，并输出栈顶元素
		temp = stack[top--];
		printf_s("%c ", g->list[temp].data);
		count++;
		//与该点有关联的都度数减一,当度数为0，继续入栈。
		for (i = 0; i < g->numVretexes; i++)
		{
			if (temp != i && g->list[i].degree!=0)
			{
				struct Node *p;
				p = g->list[i].head;
				while (p != NULL)
				{
					if (p->index == temp)
					{
						g->list[i].degree--;
					}
					p = p->next;
				}
				if (g->list[i].degree == 0)
				{
					stack[++top] = i;
				}
			}
		}
	}
	//如果输出的顶点个数不等与总顶点个数,证明当前存在环。
	if (g->numVretexes != count)
	{
		printf_s("有向图存在回路!\n");
	}
}

void print(struct LGraph_List *g)
{
	for (int i = 0; i < g->numVretexes; i++)
	{
		struct Node *p;
		printf_s("%c(%d) ", g->list[i].data,g->list[i].degree);
		p = g->list[i].head;
		while (p != NULL)
		{
			printf_s("%c ", g->list[p->index].data);
			p = p->next;
		}
		printf("\n");
	}
}

//基于DFS的拓扑排序算法
void DAG_DFS_Init(struct LGraph_List *g)
{
	int *visit,count=0;
	visit = (int*)malloc(sizeof(int) * g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < g->numVretexes; i++)
	{
		if (visit[i] == 0)
		{
			DAG_DFS(g, visit, i,&count);
		}
	}
}
void DAG_DFS(struct LGraph_List *g, int *visit, int num,int *count)
{
	struct Node *p;
	p = g->list[num].head;
	visit[num] = 1;
	while (p != NULL && visit[p->index]==0)
	{
			DAG_DFS(g, visit, p->index, count);
			p = p->next;
	}
	printf_s("%c ", g->list[num].data);
}
