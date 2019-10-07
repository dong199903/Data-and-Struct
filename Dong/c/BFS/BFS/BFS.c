/*************************************************************************
 > File Name: BFS.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）图的广度遍历
 > 2）图的广度搜索-找路径
 > 3）
 ************************************************************************/
#include "BFS.h"
#include <stdio.h>
#include <stdlib.h>
 //图的初始化--邻接矩阵
void Init_Graph_Matrix(struct MGraph *g)
{
	g->numEdges = g->numVretexes = 0;
}

//图的创建--邻接矩阵
void creat_Graph_Matrix(struct MGraph *g)
{
	int x1, x2;
	printf("请输入图的顶点个数和边的个数: ");
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
			g->data[i][j] = 0;//初始化为无连接
		}
	}
	for (int i = 0; i < g->numEdges; i++)
	{
		getchar();//吸收空格
		printf("请输入第%d个顶点信息: ", i + 1);
		scanf_s("%c", &g->vetex[i]);
	}

	for (int i = 0; i < g->numEdges; i++)
	{
		printf("请输入第%d条边两个端点的下标 ", i + 1);
		scanf_s("%d%d", &x1, &x2);
		g->data[x1][x2] = 1;//代表两点相连接构成边
		g->data[x2][x1] = 1;
	}
}

//图的打印--邻接矩阵
void print_Graph_Matrix(struct MGraph *g)
{
	printf("图的顶点是: ");
	for (int i = 0; i < g->numVretexes; i++)
	{
		printf("%c ", g->vetex[i]);
	}
	printf("\n图的邻接矩阵是\n");
	for (int i = 0; i < g->numVretexes; i++)
	{
		for (int j = 0; j < g->numVretexes; j++)
		{
			printf("%d ", g->data[i][j]);
		}
		printf("\n");
	}
}

//图的广度-邻接矩阵
void BFS_Matrix(struct MGraph *g)
{
	int *temp, *queue, front, rear;
	front = rear = 0;
	temp = (int*)malloc(sizeof(int)*g->numVretexes);
	queue = (int*)malloc(sizeof(int)*g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		temp[i] = 0;
	}
	queue[rear++] = 0;
	printf("%c ", g->vetex[0]);
	temp[0] = 1;
	while (front != rear)
	{
		int num = queue[front];
		front++;
		for (int i = 0; i < g->numVretexes; i++)
		{
			if (temp[i] == 0 && g->data[num][i] != 0)
			{
				queue[rear++] = i;
				printf("%c ", g->vetex[i]);
				temp[i] = 1;
			}
		}
	}
}

void Find_Path(struct MGraph *g, char obj1, char obj2)
{
	int index1, index2, *temp,*pre,*queue,front,rear,num;
	temp = (int*)malloc(sizeof(int) * g->numVretexes);
	queue = (int*)malloc(sizeof(int) * g->numVretexes);//辅助队列
	pre = (int*)malloc(sizeof(int) * g->numVretexes);
	front = rear = 0;
	for (int i = 0; i < g->numVretexes; i++)
	{
		temp[i] = 0;
		pre[i] = -1;//前驱顶点
		if (obj1 == g->vetex[i])
		{
			index1 = i;
		}
		if (obj2 == g->vetex[i])
		{
			index2 = i;
		}
	}
	queue[rear++] = index1;
	temp[index1] = 1;
	while (front != rear)
	{
		num = queue[front++];
		if (num == index2)//找到了目标点，逆序打印路径
		{
			while (pre[num]!=-1)
			{
				printf("%c ", g->vetex[num]);
				num = pre[num];
			}
			printf("%c ", g->vetex[num]);
			printf("\n");
		}
		//出队列时，将所有有关联的点入队列
		for (int i = 0; i < g->numVretexes; i++)
		{
			if (g->data[num][i] != 0 && temp[i] == 0)
			{
				temp[i] = 1;
				queue[rear++] = i;
				pre[i] = num;//设置顶点的前驱
			}
		}
	}
}



//图的创建--邻接表
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
	}
	printf("请输入图的边信息\n ");
	for (int i = 0; i < g->numEdges; i++)
	{
		printf("请输入第%d条边的端点下标: ", i + 1);
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

//图的打印--邻接表
void print_Graph_List(struct LGraph_List *g)
{
	printf("图的连接信息是\n");
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


//邻接表的广度
void BFS_List_Queue(struct LGraph_List *g)
{
	int *visit;
	int * queue;//构造临时存储队列
	int front, rear;
	front = rear = 0;
	queue = (int*)malloc(sizeof(int)*g->numVretexes);
	visit = (int*)malloc(sizeof(int)*g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		visit[i] = 0;
	}
	//初始让第一个元素入队
	queue[rear++] = 0;
	printf("%c ", g->list[0].data);
	visit[0] = 1;
	while (front != rear)
	{
		struct Node *s = g->list[queue[front]].head;
		front++;//出队列
		while (s != NULL)
		{
			if (visit[s->index] == 0)
			{
				queue[rear++] = s->index;
				visit[s->index] = 1;
				printf("%c ", g->list[s->index].data);
			}
			s = s->next;
		}
	}
	printf("\n");
}