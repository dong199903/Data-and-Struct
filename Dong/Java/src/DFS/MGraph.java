package DFS;

import java.util.Scanner;
import java.util.Stack;

public class MGraph {
	private int [][]data;//二维数组
	private int numVretexes;//顶点个数
	private int numEdges;//边的个数
	private char []vetex;//顶点数组
	public MGraph()
	{
		this.numVretexes = this.numEdges = 0;
	}
	public void creat_Graph_Matrix()
	{
		int x1, x2;
		System.out.print("请输入图的顶点个数和边的个数:  ");
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
			System.out.print("请输入第"+(i+1)+"个顶点信息:");
			this.vetex[i] = sc.next().charAt(0);
		}

		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("请输入第"+(i+1)+"条边信息:");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			this.data[x1][x2] = 1;//代表两点相连接构成边
			this.data[x2][x1] = 1;
		}
	}
	public void print_Graph_Matrix()
	{
		System.out.print("图的顶点信息是:");
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print(this.vetex[i]+" ");
		}
		for (int i = 0; i < this.numVretexes; i++)
		{
			for (int j = 0; j < this.numVretexes; j++)
			{
				System.out.print(this.data[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	//图的深度遍历-邻接矩阵-递归
	public void DFS_Matrix()
	{
		int []visit;
		visit = new int[this.numVretexes];
		for (int i = 0; i < this.numVretexes; i++)
		{
			visit[i] = 0;
		}
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (visit[i] == 0)//该顶点未遍历到，开启深度搜索
			{
				DFS(i, visit);
			}
		}
		System.out.println();
	}
	public void DFS(int index, int [] visit)
	{
		System.out.print(this.vetex[index]+" ");
		visit[index] = 1;//标记走过了
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (visit[i] == 0 && this.data[index][i] != 0)
			{
				DFS(i, visit);
			}
		}
	}
	//图的深度遍历-邻接矩阵-非递归
	public void DFS_Matrix_Stack(int index)
	{
		//定义标记顶点是否访问
		int []temp = new int[this.numVretexes];
		int i, j;
		//定义临时存储栈
		Stack<Integer> s = new Stack();
		for (i = 0; i < this.numVretexes; i++)
		{
			temp[i] = 0;
		}
		s.push(index);
		System.out.print(this.vetex[index]+" ");
		temp[index] = 1;
		while (!s.isEmpty())
		{
			int num =s.peek();//取栈顶元素
			for (j = 0; j < this.numVretexes; j++)
			{
				if (temp[j] == 0 && this.data[num][j] != 0)
				{
					System.out.print(this.vetex[j]+" ");
					temp[j] = 1;
					s.push(j);
					break;
				}
			}
			if (j == this.numVretexes)
			{
				s.pop();
			}
		}
		System.out.println();
	}
	//图的深度优先搜索-邻接矩阵(搜索两个点之间的路径)
	public void DFS_Search(Array arr, int []temp, int obj1, int obj2)
	{
		Array newarr = new Array();
		newarr.len = arr.len;
		for(int i=0;i<arr.len;i++)
		{
			newarr.data[i] = arr.data[i];
		}
		temp[obj1] = 1;
		newarr.data[newarr.len++] = obj1;
		if (obj1 == obj2)//找到了路径，输出路径
		{
			for (int i = 0; i < newarr.len; i++)
			{
				System.out.print(this.vetex[i]+" ");
			}
			System.out.println();
		}
		for (int j = 0; j < this.numVretexes; j++)
		{
			if (this.data[obj1][j] != 0 && temp[j] == 0)//有关联的点
			{
				DFS_Search(newarr, temp, j, obj2);
			}
		}
	}
	public void Find_Path(char obj1, char obj2)
	{
		int index1=0, index2=0;
		int[] temp;
		Array arr = new Array();
		arr.len = 0;
		temp = new int[this.numVretexes];
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (this.vetex[i] == obj1)
			{
				index1 = i;
			}
			if (this.vetex[i] == obj2)
			{
				index2 = i;
			}
			temp[i] = 0;
		}
		DFS_Search(arr, temp, index1, index2);
	}
}
