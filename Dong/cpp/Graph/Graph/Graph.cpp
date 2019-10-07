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
#include "Graph.h"

template<class T>
MGraph<T>::MGraph()
{
	this->numEdges = this->numVretexes = 0;
}

template<class T>
void MGraph<T>::creat_Graph_Matrix()
{
	int x1, x2;
	cout<<"请输入图的顶点个数和边的个数: ";
	cin >> this->numVretexes >> this->numEdges;
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
	for (int i = 0; i < this->numVretexes; i++)
	{
		getchar();//吸收空格
		cout << "请输入第" << i + 1 << "个顶点的信息";
		cin >> this->vetex[i];
	}

	for (int i = 0; i <this->numEdges; i++)
	{
		cout << "请输入第" << i + 1 << "边的下标";
		cin >> x1 >> x2;
		this->data[x1][x2] = 1;//代表两点相连接构成边
		this->data[x2][x1] = 1;
	}
}


template<class T>
void MGraph<T>::print_Graph_Matrix()
{
	cout << "图中点信息是: ";
	for (int i = 0; i < this->numVretexes; i++)
	{
		cout << this->vetex[i];
	}
	cout << "\n邻接矩阵如下" << endl;
	for (int i = 0; i < this->numVretexes; i++)
	{
		for (int j = 0; j < this->numVretexes; j++)
		{
			cout << this->data[i][j]<<" ";
		}
		cout<<endl;
	}
}


//邻接表
template<class T>
LGraph_List<T>::LGraph_List()
{
	this->numVretexes = this->numEdges = 0;
}

//加入数据
template<class T>
void LGraph_List<T>::creat_Graph_List()
{
	int x1, x2;
	cout<<"请输入图的顶点个数和边个数 ";
	cin >> this->numVretexes >> this->numEdges;
	this->list = new LGraph<T>[this->numVretexes];
	cout<<"请输入图的顶点信息 ";
	for (int i = 0; i < this->numVretexes; i++)
	{
		getchar();
		cin >> this->list[i].data;
		this->list[i].head = NULL;
	}
	cout<<"请输入图的边信息\n ";
	for (int i = 0; i < this->numEdges; i++)
	{
		cout << "请输入第" << i + 1 << "条边的顶点下标 ";
		cin >> x1 >> x2;
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
//输出图
template<class T>
void LGraph_List<T>::print_Graph_List()
{
	cout<<"图的邻接表如下: \n";
	for (int i = 0; i < this->numVretexes; i++)
	{
		cout << this->list[i].data << "-->";
		Node *s = this->list[i].head;
		while (s != NULL)
		{
			cout << this->list[s->index].data << "-->";
			s = s->next;
		}
		printf("\n");
	}
}



