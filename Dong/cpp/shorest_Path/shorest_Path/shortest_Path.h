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
#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H
#define MAX 99999
 //邻接矩阵
class MGraph
{
public:
	int **data;//二维数组
	int numVretexes;//顶点个数
	int numEdges;//边的个数
	char *vetex;//顶点数组
	MGraph();
	//图的创建
	void creat_Graph_Matrix();
	//迪杰斯特拉算法
	void Dijkstra(char obj);
	//贝尔曼-福特算法
	void Bellman_Ford(char obj);
	//SPFA算法
	void SPFA(char obj);
	//Floyd算法
	void Floyd();
	void print_Path(int begin, int last,int **path);
};

#endif // !SHORTEST_PATH_H

