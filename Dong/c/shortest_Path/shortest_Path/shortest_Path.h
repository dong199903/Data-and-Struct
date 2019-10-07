/*************************************************************************
 > File Name: shortest_Path.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-8
 >
 > 1）迪杰斯特拉算法Dijkstra---------------不能处理带负权的图
 > 2）贝尔曼-福特算法Bellman-Ford----------可以处理带负权的图
 > 3）SPFA算法
 > 4）Flody算法
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
//贝尔曼-福特算法检验负回路
//*******
//SPFA算法
void SPFA(struct MGraph *g,char obj);
//Floyd算法
void Floyd(struct MGraph *g);
void print_Path(int begin, int last, struct MGraph *g, int **path);
#endif // !SHORTEST_H

