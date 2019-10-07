package Graph;

import java.util.Scanner;

public class MGraph {
	private int [][]data;//二维数组
	private int numVretexes;//顶点个数
	private int numEdges;//边的个数
	private char []vetex;//顶点数
	public MGraph()
	{
		this.numEdges = this.numVretexes = 0;
	}
	//图的创建
	public void creat_Graph_Matrix()
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
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print("请输入第"+(i+1)+ "个顶点的信息");
			this.vetex[i] = sc.next().charAt(0);
		}

		for (int i = 0; i <this.numEdges; i++)
		{
			System.out.print("请输入第"+(i+1)+ "个边的信息");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			this.data[x1][x2] = 1;//代表两点相连接构成边
			this.data[x2][x1] = 1;
		}
	}

	//图的打印
	public void print_Graph_Matrix()
	{
		System.out.print("图中点信息是: ");
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print(this.vetex[i]+" ");
		}
		System.out.print("\n邻接矩阵如下\n");
		for (int i = 0; i < this.numVretexes; i++)
		{
			for (int j = 0; j < this.numVretexes; j++)
			{
				System.out.print(this.data[i][j]+" ");
			}
			System.out.println();
		}
	}
}
