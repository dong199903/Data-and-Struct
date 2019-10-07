/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#include <iostream>
using namespace std;
#include "DAG.h"
#include <stack>
LGraph_List::LGraph_List()
{
	this->numVretexes = this->numEdges = 0;
}
//图的创建
void LGraph_List::creat_Graph_List()
{
	int x1, x2;
	cout<<"请输入图的顶点个数和边个数 ";
	cin>>this->numVretexes>>this->numEdges;
	this->list = new LGraph[this->numVretexes];
	printf("请输入图的顶点信息 ");
	for (int i = 0; i < this->numVretexes; i++)
	{
		getchar();
		cin>>this->list[i].data;
		this->list[i].head = NULL;
		this->list[i].degree = 0;//每个点的入度为0
	}
	printf("请输入图的边信息\n ");
	for (int i = 0; i < this->numEdges; i++)
	{
		cout<<"请输入第"<<i+1<<"条边的端点下标: ";
		cin>>x1>>x2;
		Node *s1;
		s1 = new Node;
		s1->index = x1;
		s1->next = this->list[x2].head;
		this->list[x2].head = s1;
		this->list[x2].degree++;//入度增加1
	}
}
//输出测试
void LGraph_List::print()
{
	for (int i = 0; i < this->numVretexes; i++)
	{
		Node *p;
		cout<<this->list[i].data<<this->list[i].degree;
		p = this->list[i].head;
		while (p != NULL)
		{
			cout<<this->list[p->index].data<<" ";
			p = p->next;
		}
		cout << endl;
	}
}
//KaHn算法
void LGraph_List::KaHn()
{
	//辅助栈存储入度为0的点
	stack<int> s;
	int i, temp, count = 0;
	for (i = 0; i < this->numVretexes; i++)
	{
		if (this->list[i].degree == 0)
		{
			s.push(i);//存储的是点的下标
		}
	}
	//栈空退出
	while (!s.empty())
	{
		//出栈栈顶元素，并输出栈顶元素
		temp = s.top();
		s.pop();
		cout<<this->list[temp].data<<" ";
		count++;
		//与该点有关联的都度数减一,当度数为0，继续入栈。
		for (i = 0; i < this->numVretexes; i++)
		{
			if (temp != i && this->list[i].degree != 0)
			{
				Node *p;
				p = this->list[i].head;
				while (p != NULL)
				{
					if (p->index == temp)
					{
						this->list[i].degree--;
					}
					p = p->next;
				}
				if (this->list[i].degree == 0)
				{
					s.push(i);
				}
			}
		}
	}
	//如果输出的顶点个数不等与总顶点个数,证明当前存在环。
	if (this->numVretexes != count)
	{
		cout<<"有向图存在回路!\n";
	}
}
//基于DFS的拓扑排序算法
void LGraph_List::DAG_DFS_Init()
{
	int *visit, count = 0;
	visit = new int[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < this->numVretexes; i++)
	{
		if (visit[i] == 0)
		{
			DAG_DFS( visit, i, &count);
		}
	}
}
void LGraph_List::DAG_DFS(int *visit, int num, int*count)
{
	Node *p;
	p = this->list[num].head;
	visit[num] = 1;
	while (p != NULL && visit[p->index] == 0)
	{
		DAG_DFS(visit, p->index, count);
		p = p->next;
	}
	cout<<this->list[num].data<<" ";
}