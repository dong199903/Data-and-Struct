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
#include "BFS.h"
#include <queue>
template<class T>
MGraph<T>::MGraph()
{
	this->numEdges = this->numVretexes = 0;
}
//图的创建-邻接矩阵
template<class T>
void MGraph<T>::creat_Graph_Matrix()
{
	int x1, x2;
	cout<<"请输入图的顶点个数和边的个数: ";
	cin>>this->numVretexes>>this->numEdges;
	this->vetex = new T[this->numVretexes];
	this->data = new int*[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		this->data[i] = new int[this->numVretexes];
	}
	for (int i = 0; i < this->numVretexes; i++)
	{
		for (int j = 0; j < this->numVretexes; j++)
		{
			this->data[i][j] = 0;//初始化为无连接
		}
	}
	for (int i = 0; i < this->numEdges; i++)
	{
		getchar();//吸收空格
		cout << "请输入第" << i + 1 << "个点信息 ";
		cin>>this->vetex[i];
	}

	for (int i = 0; i < this->numEdges; i++)
	{
		cout << "请输入第" << i + 1 << "边信息 ";
		cin>>x1>>x2;
		this->data[x1][x2] = 1;//代表两点相连接构成边
		this->data[x2][x1] = 1;
	}
}
//图的广度遍历-邻接矩阵
template<class T>
void MGraph<T>::BFS_Matrix()
{
	int *temp;
	queue<int> q;
	temp = new int[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		temp[i] = 0;
	}
	q.push(0);
	cout<<this->vetex[0]<<" ";
	temp[0] = 1;
	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		for (int i = 0; i < this->numVretexes; i++)
		{
			if (temp[i] == 0 && this->data[num][i] != 0)
			{
				q.push(i);
				cout<<this->vetex[i]<<" ";
				temp[i] = 1;
			}
		}
	}
	cout << endl;
}

//图的广度搜索-找路径
template<class T>
void MGraph<T>::Find_Path(char obj1, char obj2)
{
	int index1=-1, index2=-1, *temp, *pre,num;
	temp = new int[this->numVretexes];
	queue<int> q;
	pre = new int[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		temp[i] = 0;
		pre[i] = -1;//前驱顶点
		if (obj1 == this->vetex[i])
		{
			index1 = i;
		}
		if (obj2 == this->vetex[i])
		{
			index2 = i;
		}
	}
	//点信息错误，退出
	if (index1 == -1 || index2 == -1)
	{
		return;
	}
	q.push(index1);
	temp[index1] = 1;
	while (!q.empty())
	{
		num = q.front();
		q.pop();
		if (num == index2)//找到了目标点，逆序打印路径
		{
			while (pre[num] != -1)
			{
				cout<<this->vetex[num];
				num = pre[num];
			}
			cout<<this->vetex[num]<<" ";
			cout << endl;
		}
		//出队列时，将所有有关联的点入队列
		for (int i = 0; i < this->numVretexes; i++)
		{
			if (this->data[num][i] != 0 && temp[i] == 0)
			{
				temp[i] = 1;
				q.push(i);
				pre[i] = num;//设置顶点的前驱
			}
		}
	}
}


template<class T>
LGraph_List<T>::LGraph_List()
{
	this->numVretexes = this->numEdges = 0;
}


//图的创建-邻接表
template<class T>
void LGraph_List<T>::creat_Graph_List()
{
	int x1, x2;
	cout<<"请输入图的顶点个数和边个数 ";
	cin>>this->numVretexes>>this->numEdges;
	this->list = new LGraph<T>[this->numVretexes];
	cout << "输入图的顶点信息";
	for (int i = 0; i < this->numVretexes; i++)
	{
		getchar();
		cin>>this->list[i].data;
		this->list[i].head = NULL;
	}
	cout <<"输入图的边信息 ";
	for (int i = 0; i < this->numEdges; i++)
	{
		cout << "输入图第" <<i + 1<< "条边信息 ";
		cin>>x1>>x2;
		Node *s1, *s2;
		s1 = new Node;
		s2 = new Node;
		s1->index = x1;
		s2->index = x2;
		s1->next = this->list[x2].head;
		this->list[x2].head = s1;
		s2->next = this->list[x1].head;
		this->list[x1].head = s2;
	}
}


//图的广度遍历-邻接表
template<class T>
void LGraph_List<T>::BFS_List_Queue()
{
	int *visit;
	queue<int> q;
	visit = new int[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		visit[i] = 0;
	}
	//初始让第一个元素入队
	q.push(0);
	cout<<this->list[0].data<<" ";
	visit[0] = 1;
	while (!q.empty())
	{
		Node *s = this->list[q.front()].head;
		q.pop();
		while (s != NULL)
		{
			if (visit[s->index] == 0)
			{
				q.push(s->index);
				visit[s->index] = 1;
				cout<<this->list[s->index].data<<" ";
			}
			s = s->next;
		}
	}
	cout << endl;
}