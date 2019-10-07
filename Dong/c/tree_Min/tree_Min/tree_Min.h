/*************************************************************************
 > File Name: tree_Min.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-20
 >
 > 1）普利姆算法
 > 2）克鲁斯卡尔算法
 ************************************************************************/
#ifndef TREE_MIN_H
#define TREE_MIN_H
struct MGraph
{
	int numVertes;//顶点个数
	int numEdges;//边个数
	int **data;//二维数组存储边信息-权值
	char *vetes;//顶点信息
};

//边权值排序
struct Edge
{
	int begin;
	int end;
	int w;
};
//并查级结构
struct UFStree
{
	int index;//节点下标
	int high;//对应树的高度
	int parent;//对应树的父亲点
};
//图的创建
void creat_Graph_Matrix(struct MGraph *g);
//最下生成树-Prime
void Prim(struct MGraph *g,char obj);
//最小生成树-Kruskal
void Kruskal(struct MGraph *g);
//并查集的查找
int find_Tree(struct UFStree *tree,int num);
//并查集节点的合并
void union_Tree(struct UFStree *tree, int x, int y);
#define MAX 99999
#endif // !TREE_MIN_H

