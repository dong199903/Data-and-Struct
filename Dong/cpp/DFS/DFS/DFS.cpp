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
#include "DFS.H"
#include <stack>

template<class T>
MGraph<T>::MGraph()
{
	this->numVretexes = this->numEdges = 0;
}


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
		cout<<"请输入第"<<i+1<<"个顶点信息: ";
		cin>>this->vetex[i];
	}

	for (int i = 0; i < this->numEdges; i++)
	{
		cout<<"请输入第"<<i+1<<"条边两个端点的下标 ";
		cin>>x1>>x2;
		this->data[x1][x2] = 1;//代表两点相连接构成边
		this->data[x2][x1] = 1;
	}
}


template<class T>
void MGraph<T>::print_Graph_Matrix()
{
	cout << "图的顶点信息是: ";
	for (int i = 0; i < this->numVretexes; i++)
	{
		cout << this->vetex[i] << " ";
	}
	cout << "邻接矩阵如下: \n";
	for (int i = 0; i < this->numVretexes; i++)
	{
		for (int j = 0; j < this->numVretexes; j++)
		{
			cout<<this->data[i][j]<<" ";
		}
		cout << endl;
	}
}


//图的深度遍历-邻接矩阵-递归
template<class T>
void MGraph<T>::DFS_Matrix()
{
	int *visit;
	visit = new int[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < this->numVretexes; i++)
	{
		if (visit[i] == 0)//该顶点未遍历到，开启深度搜索
		{
			DFS(i, visit);
		}
	}
	cout << endl;
}


template<class T>
void MGraph<T>::DFS(int index, int *visit)
{
	cout<<this->vetex[index]<<" ";
	visit[index] = 1;//标记走过了
	for (int i = 0; i < this->numVretexes; i++)
	{
		if (visit[i] == 0 && this->data[index][i] != 0)
		{
			DFS(i, visit);
		}
	}
}


//图的深度遍历-邻接矩阵-非递归
template<class T>
void MGraph<T>::DFS_Matrix_Stack(int index)
{
	//定义标记顶点是否访问
	int *temp = new int[this->numVretexes];
	int i, j;
	//定义临时存储栈
	stack<int> s;
	for (i = 0; i < this->numVretexes; i++)
	{
		temp[i] = 0;
	}
	s.push(index);
	cout<<this->vetex[index]<<" ";
	temp[index] = 1;
	while (!s.empty())
	{
		int num =s.top();//取栈顶元素
		for (j = 0; j < this->numVretexes; j++)
		{
			if (temp[j] == 0 && this->data[num][j] != 0)
			{
				cout<<this->vetex[j]<<" ";
				temp[j] = 1;
				s.push(j);
				break;
			}
		}
		if (j == this->numVretexes)
		{
			s.pop();
		}
	}
	cout << endl;
}

//图的深度优先搜索-邻接矩阵(搜索两个点之间的路径)
template<class T>
void MGraph<T>::DFS_Search(Array arr, int *temp, int obj1, int obj2)
{
	temp[obj1] = 1;
	arr.data[arr.len++] = obj1;
	if (obj1 == obj2)//找到了路径，输出路径
	{
		for (int i = 0; i < arr.len; i++)
		{
			cout<<this->vetex[i]<<" ";
		}
		cout << endl;
	}
	for (int j = 0; j < this->numVretexes; j++)
	{
		if (this->data[obj1][j] != 0 && temp[j] == 0)//有关联的点
		{
			DFS_Search(arr, temp, j, obj2);
		}
	}
}

template<class T>
void MGraph<T>::Find_Path(char obj1, char obj2)
{
	int index1, index2, *temp;
	Array arr;
	arr.len = 0;
	temp = new int[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		if (this->vetex[i] == obj1)
		{
			index1 = i;
		}
		if (this->vetex[i] == obj2)
		{
			index2 = i;
		}
		temp[i] = 0;
	}
	DFS_Search(arr, temp, index1, index2);
}



template<class T>
LGraph_List<T>::LGraph_List()
{
	this->numEdges = this->numVretexes = 0;
}



//图的创建-邻接表
template<class T>
void LGraph_List<T>::creat_Graph_List()
{
	int x1, x2;
	cout<<"请输入图的顶点个数和边个数 ";
	cin>>this->numVretexes>>this->numEdges;
	this->list = new LGraph<T>[this->numVretexes];
	cout<<"请输入图的顶点信息 ";
	for (int i = 0; i < this->numVretexes; i++)
	{
		getchar();
		cin>>this->list[i].data;
		cout<<this->list[i].data;
		this->list[i].head = NULL;
	}
	cout<<"请输入图的边信息\n ";
	for (int i = 0; i < this->numEdges; i++)
	{
		cout << "请输入第" << i + 1 << "条边信息";
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



//图的深度遍历-邻接表-递归
template<class T>
void LGraph_List<T>::DFS_List()
{
	int *visit;
	visit = new int[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < this->numVretexes; i++)
	{
		if (visit[i] == 0)
			DFS_DG(visit, i);
	}
	cout << endl;
}


template<class T>
void LGraph_List<T>::DFS_DG(int *visit, int index)
{
	cout<<this->list[index].data<<" ";
	visit[index] = 1;
	Node *s = this->list[index].head;
	while (s != NULL)
	{
		if (visit[s->index] == 0)
		{
			DFS_DG(visit, s->index);
		}
		s = s->next;
	}
}


//图的深度遍历-邻接表-非递归
template<class T>
void LGraph_List<T>::DFS_List_Stack()
{
	int *visit,num;
	stack<int> s;
	visit = new int[this->numVretexes];
	for (int i = 0; i < this->numVretexes; i++)
	{
		visit[i] = 0;
	}
	s.push(0);
	visit[0] = 1;
	cout<<this->list[0].data<<" ";
	while (!s.empty())
	{
		num = s.top();
		Node *n;
		n = this->list[num].head;
		while (n != NULL)
		{
			if (visit[n->index] == 0)
			{
				cout<<this->list[n->index].data<<" ";
				s.push(n->index);
				visit[n->index] = 1;
				break;
			}
			n = n->next;
		}
		if (n == NULL)
		{
			s.pop();
		}
	}
	cout << endl;
}