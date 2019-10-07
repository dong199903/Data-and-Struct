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
#ifndef TREE_MIN_H
#define TREE_MIN_H
#define MAX 99999
class MGraph
{
public:
	int numVertes;//顶点个数
	int numEdges;//边个数
	int **data;//二维数组存储边信息-权值
	char *vetes;//顶点信息
	MGraph();
	//图的创建
	void creat_Graph_Matrix();
	//最下生成树-Prime
	void Prim(char obj);
	//最小生成树-Kruskal
	void Kruskal();
};


//边权值排序
class Edge
{
public:
	int begin;
	int end;
	int w;
};
//并查级结构
class UFStree
{
public:
	int index;//节点下标
	int high;//对应树的高度
	int parent;//对应树的父亲点
};

//并查集的查找
int find_Tree(UFStree *tree, int num);
//并查集节点的合并
void union_Tree(UFStree *tree, int x, int y);
#endif // !TREE_MIN_H

