/*************************************************************************
> File Name: DFS.c
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-08-23
>
> 1）基于图的邻接矩阵的深度优先遍历(递归实现)
> 2）基于图的邻接矩阵的深度优先遍历(非递归实现)
> 3）基于图的邻接表的深度优先遍历(递归实现)
> 4）基于图的邻接表的深度优先遍历(非递归实现)
************************************************************************/
#include "DFS.h"
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
//深度遍历--递归
void DFS(struct MGraph *g, int index, int *visit)
{
	printf("%c ", g->vetex[index]);
	visit[index] = 1;//标记走过了
	for (int i = 0; i < g->numVretexes; i++)
	{
		if (visit[i] == 0 && g->data[index][i] != 0)
		{
			DFS(g, i, visit);
		}
	}
}
//图的深度遍历--邻接矩阵
void DFS_Matrix(struct MGraph *g)
{
	int *visit;
	visit = (int*)malloc(sizeof(int)*g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < g->numVretexes; i++)
	{
		if (visit[i] == 0)//该顶点未遍历到，开启深度搜索
		{
			DFS(g, i, visit);
		}
	}
	printf("\n");
}

//深度遍历-邻接矩阵-非递归(栈实现)
void DFS_Matrix_Stack(struct MGraph *g, int index)
{
	//定义标记顶点是否访问
	int *temp = (int *)malloc(sizeof(int)*g->numVretexes);
	int i, j;
	//定义临时存储栈
	int *stack = (int *)malloc(sizeof(int)*g->numVretexes);
	int top = -1;
	for (i = 0; i < g->numVretexes; i++)
	{
		temp[i] = 0;
	}
	stack[++top] = index;
	printf("%c ", g->vetex[index]);
	temp[index] = 1;
	while (top != -1)
	{
		int num = stack[top];//取栈顶元素
		for (j = 0; j < g->numVretexes; j++)
		{
			if (temp[j] == 0 && g->data[num][j] != 0)
			{
				printf("%c ", g->vetex[j]);
				temp[j] = 1;
				stack[++top] = j;
				break;
			}
		}
		if (j == g->numVretexes)
		{
			top--;
		}
	}
	printf("\n");
}

void Find_Path(struct MGraph *g, char obj1, char obj2)
{
	int index1, index2,*temp;
	struct Array arr;
	arr.len = 0;
	temp = (int*)malloc(sizeof(int) * g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		if (g->vetex[i] == obj1)
		{
			index1 = i;
		}
		if (g->vetex[i] == obj2)
		{
			index2 = i;
		}
		temp[i] = 0;
	}
	DFS_Search(g, arr, temp, index1, index2);

}
void DFS_Search(struct MGraph *g, struct Array arr,int *temp, int obj1, int obj2)
{
	temp[obj1] = 1;
	arr.data[arr.len++] = obj1;
	if (obj1 == obj2)//找到了路径，输出路径
	{
		for (int i = 0; i < arr.len; i++)
		{
			printf("%c ", g->vetex[i]);
		}
		printf("\n");
	}
	for (int j = 0; j < g->numVretexes; j++)
	{
		if (g->data[obj1][j] != 0 && temp[j]==0)//有关联的点
		{
			DFS_Search(g, arr,temp, j, obj2);
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

void DFS_List(struct LGraph_List *g)
{
	int *visit;
	visit = (int*)malloc(sizeof(int)*g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < g->numVretexes; i++)
	{
		if (visit[i] == 0)
			DFS_DG(g, visit, i);
	}
	printf("\n");
}
//邻接表深度-递归
void DFS_DG(struct LGraph_List *g, int *visit, int index)
{
	printf("%c ", g->list[index].data);
	visit[index] = 1;
	struct Node *s = g->list[index].head;
	while (s != NULL)
	{
		if (visit[s->index] == 0)
		{
			DFS_DG(g, visit, s->index);
		}
		s = s->next;
	}
}

//邻接表的深度--非递归
void DFS_List_Stack(struct LGraph_List *g)
{
	int *visit;
	int * stack;//构造临时存储队列
	int top = -1, num;
	stack = (int*)malloc(sizeof(int)*g->numVretexes);
	visit = (int*)malloc(sizeof(int)*g->numVretexes);
	for (int i = 0; i < g->numVretexes; i++)
	{
		visit[i] = 0;
	}
	stack[++top] = 0;
	visit[0] = 1;
	printf("%c ", g->list[0].data);
	while (top != -1)
	{
		num = stack[top];
		struct Node *s;
		s = g->list[num].head;
		while (s != NULL)
		{
			if (visit[s->index] == 0)
			{
				printf("%c ", g->list[s->index].data);
				stack[++top] = s->index;
				visit[s->index] = 1;
				break;
			}
			s = s->next;
		}
		if (s == NULL)
		{
			top--;
		}
	}
	printf("\n");
}


