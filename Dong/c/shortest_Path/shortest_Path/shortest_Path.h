/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-8
 >
 > 1）迪杰斯特拉算法Dijkstra---------------不能处理带负权的图
 > 2）贝尔曼-福特算法Bellman-Ford----------可以处理带负权的图
 > 3）
 ************************************************************************/
#ifndef SHORTEST_H
#define SHORTEST_H

 //邻接矩阵
struct MGraph
{
	int **data;//二维数组
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	char *vetex;//顶点数组
};
#define MAX 99999
//图的创建
void creat_Graph_Matrix(struct MGraph *g);
//迪杰斯特拉算法
void Dijkstra(struct MGraph *g, char obj);
//贝尔曼-福特算法
void Bellman_Ford(struct MGraph *g,char obj);
#endif // !SHORTEST_H

