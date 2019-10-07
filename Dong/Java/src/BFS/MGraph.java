package BFS;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class MGraph {
	private int [][]data;//二维数组
	private int numVretexes;//顶点个数
	private int numEdges;//边的个数
	private char []vetex;//顶点数组
	public MGraph()
	{
		this.numEdges = this.numVretexes = 0;
	}
	//图的创建-邻接矩阵
	void creat_Graph_Matrix()
	{
		int x1, x2;
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
				this.data[i][j] = 0;//初始化为无连接
			}
		}
		for (int i = 0; i < this.numEdges; i++)
		{
	
			System.out.print("请输入第" + (i + 1) + "个点信息 ");
			this.vetex[i] = sc.next().charAt(0);
		}

		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("请输入第" + (i + 1) + "个边信息 ");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			this.data[x1][x2] = 1;//代表两点相连接构成边
			this.data[x2][x1] = 1;
		}
	}

	//图的广度遍历-邻接矩阵
	void BFS_Matrix()
	{
		int []temp;
		Queue<Integer> q = new LinkedList<Integer>();
		temp = new int[this.numVretexes];
		for (int i = 0; i < this.numVretexes; i++)
		{
			temp[i] = 0;
		}
		q.offer(0);
		System.out.print(this.vetex[0]+" ");
		temp[0] = 1;
		while (!q.isEmpty())
		{
			int num = q.poll();
			for (int i = 0; i < this.numVretexes; i++)
			{
				if (temp[i] == 0 && this.data[num][i] != 0)
				{
					q.offer(i);
					System.out.print(this.vetex[i]+" ");
					temp[i] = 1;
				}
			}
		}
		System.out.println();
	}

	//图的广度搜索-找路径
	void Find_Path(char obj1, char obj2)
	{
		int index1=-1, index2=-1,num; 
		int [] temp,pre;
		temp = new int[this.numVretexes];
		Queue<Integer> q = new LinkedList<Integer>();
		pre = new int[this.numVretexes];
		for (int i = 0; i < this.numVretexes; i++)
		{
			temp[i] = 0;
			pre[i] = -1;//前驱顶点
			if (obj1 == this.vetex[i])
			{
				index1 = i;
			}
			if (obj2 == this.vetex[i])
			{
				index2 = i;
			}
		}
		//点信息错误，退出
		if (index1 == -1 || index2 == -1)
		{
			return;
		}
		q.offer(index1);
		temp[index1] = 1;
		while (!q.isEmpty())
		{
			num = q.poll();
			if (num == index2)//找到了目标点，逆序打印路径
			{
				while (pre[num] != -1)
				{
					System.out.print(this.vetex[num]);
					num = pre[num];
				}
				System.out.print(this.vetex[num]+" ");
				System.out.println();
			}
			//出队列时，将所有有关联的点入队列
			for (int i = 0; i < this.numVretexes; i++)
			{
				if (this.data[num][i] != 0 && temp[i] == 0)
				{
					temp[i] = 1;
					q.offer(i);
					pre[i] = num;//设置顶点的前驱
				}
			}
		}
	}
}
