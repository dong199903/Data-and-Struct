package shortest_Path;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019年10月3日 下午5:11:20
 >
 > 1）链栈的基本实现
 > 2）入栈和出栈等基本操作
 > 3）
 ************************************************************************/
public class MGraph {
	private int [][]data;//二维数组
	private int numVretexes;//顶点个数
	private int numEdges;//边的个数
	private char []vetex;//顶点数组
	private static int MAX = 9999;
	public MGraph()
	{
		this.numEdges = this.numVretexes = 0;
	}
	//图的创建
	public void creat_Graph_Matrix()
	{
		int x1, x2, w;
		System.out.print("请输入图的顶点个数和边的个数: ");
		Scanner sc = new Scanner(System.in);
		this.numVretexes = sc.nextInt();
		this.numEdges = sc.nextInt();
		this.vetex = new char[this.numVretexes];
		this.data = new int[this.numVretexes][];
		for (int i = 0; i < this.numVretexes; i++)
		{
			this.data[i] = new int[this.numVretexes];
		}
		for (int i = 0; i < this.numVretexes; i++)
		{
			for (int j = 0; j < this.numVretexes; j++)
			{
				if (i == j)
				{
					this.data[i][j] = 0;
				}
				else
				{
					this.data[i][j] = MAX;
				}

			}
		}
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print("请输入第" +(i + 1) + "个顶点信息: ");
			this.vetex[i] = sc.next().charAt(0);
		}
		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("请输入第" +(i + 1) + "个边信息: ");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			w = sc.nextInt();
			this.data[x1][x2] = w;//代表两点相连接构成边
			this.data[x2][x1] = w;
		}
	}
	//迪杰斯特拉算法
	public void Dijkstra(char obj)
	{
		int []temp, dis, pre;
		int index=0, min=0, k=0;
		temp = new int[this.numVretexes];
		dis = new int[this.numVretexes];
		pre = new int[this.numVretexes];
		//找出源节点的位置
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (this.vetex[i] == obj)
			{
				index = i;
				break;
			}
		}
		//初始化辅助数组
		for (int i = 0; i < this.numVretexes; i++)
		{
			temp[i] = 0;
			pre[i] = -1;
			dis[i] = this.data[index][i];
		}
		temp[index] = 1;
		for (int i = 1; i < this.numVretexes; i++)
		{
			min = MAX;
			//找出当前dis存储最小的下标
			for (int j = 0; j < this.numVretexes; j++)
			{
				if (temp[j] == 0 && this.data[index][j] < min)
				{
					min = this.data[index][j];
					k = j;//标记最小值的位置
				}
			}
			temp[k] = 1;
			index = k;
			//从该点开始，逐个判断并修改dis数组
			for (int j = 0; j < this.numVretexes; j++)
			{
				if (temp[j] == 0 && (this.data[k][j] + dis[k]) < dis[j])
				{
					dis[j] = this.data[k][j] + dis[k];
					pre[j] = k;
				}
			}
		}

		//dis数组就是源点到各个点的最短路径
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print(obj + "-->" + this.vetex[i] + "("+dis[i]+")");
		}
		System.out.println();
	}
	//贝尔曼-福特算法
	public void Bellman_Ford(char obj)
	{
		int []dis, pre;
		int index=0, temp;
		dis = new int[this.numVretexes];
		pre = new int[this.numVretexes];
		//找出目标点位置
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (this.vetex[i] == obj) {
				index = i;
				break;
			}
		}
		//初始化dis数组
		for (int i = 0; i < this.numVretexes; i++)
		{
			dis[i] = MAX;
			pre[i] = -1;
		}
		dis[index] = 0;
		for (int k = 1; k < this.numVretexes; k++)
		{
			for (int i = 0; i < this.numVretexes; i++)
			{
				for (int j = 0; j < this.numVretexes; j++)
				{
					if (j != index && i != j && this.data[i][j] != MAX)
					{
						if (dis[i] + this.data[i][j] < dis[j])
						{
							dis[j] = dis[i] + this.data[i][j];
							pre[j] = i;
						}
					}
				}
			}
		}
		//经过松弛后，如果还可以松弛，表示图中存在负数权回路
		temp = 0;
		for (int i = 0; i < this.numVretexes; i++)
		{
			for (int j = 0; j < this.numVretexes; j++)
			{
				if (j != index && i != j && this.data[i][j] != MAX)
				{
					if (dis[i] + this.data[i][j] < dis[j])
					{
						temp = 1;
						System.out.print("图中存在负权回路\n");
						return;
					}
				}
			}

		}
		//输出dis数组
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print(dis[i] +" ");
		}
		System.out.println();
	}
	//SPFA算法
	public void SPFA(char obj)
	{
		int index=0, i,top;
		int []visit, dis, path;
		Queue<Integer> q = new LinkedList<Integer>();
		visit = new int[this.numVretexes];
		dis = new int[this.numVretexes];
		path = new int[this.numVretexes];
		//1.找出源点
		for (i = 0; i < this.numVretexes; i++)
		{
			if (this.vetex[i] == obj)
			{
				index = i;
			}
		}
		//2:初始化队列,辅助数组
		for (i = 0; i < this.numVretexes; i++)
		{
			visit[i] = 0;
			dis[i] = MAX;
			path[i] = -1;
		}
		q.offer(index);
		visit[index] = 1;
		dis[index] = 0;
		while (!q.isEmpty())//队列空结束
		{
			top = q.poll();
			visit[top] = 0;
			for (i = 0; i < this.numVretexes; i++)
			{
				if (i != top)
				{
					if (dis[i] >(dis[top] + this.data[top][i]))
					{
						dis[i] = dis[top] + this.data[top][i];
						path[i] = top;
						if (visit[i] == 0)//没在队列里,入队
						{
							q.offer(i);
							visit[i] = 1;
						}
					}
				}
			}
		}
		//输出最端距离和路径
		for (i = 0; i < this.numVretexes; i++)
		{
			if (i != index)
			{
				System.out.print(this.vetex[index] + "-->" + this.vetex[i] + dis[i]);
			}
		}
		System.out.println();
	}
	//Floyd算法
	public void Floyd()
	{
		int i, j, k, temp = 0;
		int [][]dis,path;
		dis = new int[this.numVretexes][];
		path = new int[this.numVretexes][];
		for (i = 0; i < this.numVretexes; i++)
		{
			dis[i] = new int[this.numVretexes];
			path[i] = new int[this.numVretexes];
		}
		//初始化dis和path数组
		for (i = 0; i < this.numVretexes; i++)
		{
			for (j = 0; j < this.numVretexes; j++)
			{
				dis[i][j] = this.data[i][j];
				path[i][j] = -1;
			}
		}
		//开始逐个点p的判断
		for (i = 0; i < this.numVretexes; i++)
		{
			//逐个取出每两个点x,y，判断dis[x][y] > dis[x][p]+dis[p][y]
			for (j = 0; j < this.numVretexes; j++)
			{
				for (k = 0; k < this.numVretexes; k++)
				{
					if (dis[j][k] > dis[j][i] + dis[i][k])
					{
						dis[j][k] = dis[j][i] + dis[i][k];
						path[j][k] = i;
					}
				}
			}
		}

		//输出最短距离
		for (i = 0; i < this.numVretexes; i++)
		{
			for (j = 0; j < this.numVretexes; j++)
			{
				if (i != j)
				{
					print_Path(i, j, path);
					System.out.print(dis[i][j]+" ");
				}
			}
		}
	}
	public void print_Path(int begin, int last,int [][]path)
	{
		if (path[begin][last] == -1)
		{
			System.out.print(this.vetex[begin]+"-->"+this.vetex[last]+"-->");
		}
		else
		{
			int mid = path[begin][last];
			print_Path(begin, mid, path);
			print_Path(mid, last,  path);
		}
	}
}
