package DAG;

import java.util.Scanner;
import java.util.Stack;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019年10月3日 下午4:41:50
 >
 > 1）链栈的基本实现
 > 2）入栈和出栈等基本操作
 > 3）
 ************************************************************************/
public class LGraph_List {
	private LGraph [] list;
	private int numVretexes;//顶点个数
	private int numEdges;//边的个数
	public LGraph_List()
	{
		this.numVretexes = this.numEdges = 0;
	}
	//图的创建
	public void creat_Graph_List()
	{
		int x1, x2;
		System.out.print("请输入图的顶点个数和边个数 ");
		Scanner sc = new Scanner(System.in);
		this.numVretexes = sc.nextInt();
		this.numEdges = sc.nextInt();
		this.list = new LGraph[this.numVretexes];
		System.out.print("请输入图的顶点信息 ");
		for (int i = 0; i < this.numVretexes; i++)
		{
			this.list[i] = new 	LGraph();
			this.list[i].data = sc.next().charAt(0);
			this.list[i].head = null;
			this.list[i].degree = 0;//每个点的入度为0
		}
		System.out.print("请输入图边信息 ");
		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("请输入第"+(i+1)+"条边的端点下标: ");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			Node s1;
			s1 = new Node();
			s1.index = x1;
			s1.next = this.list[x2].head;
			this.list[x2].head = s1;
			this.list[x2].degree++;//入度增加1
		}
	}
	
	//KaHn算法
	public void KaHn()
	{
		//辅助栈存储入度为0的点

        Stack<Integer> s=new Stack<Integer>();
		int i, temp, count = 0;
		for (i = 0; i < this.numVretexes; i++)
		{
			if (this.list[i].degree == 0)
			{
				s.push(i);//存储的是点的下标
			}
		}
		//栈空退出
		while (!s.isEmpty())
		{
			//出栈栈顶元素，并输出栈顶元素
			temp = s.pop();
			System.out.print(this.list[temp].data+" ");
			count++;
			//与该点有关联的都度数减一,当度数为0，继续入栈。
			for (i = 0; i < this.numVretexes; i++)
			{
				if (temp != i && this.list[i].degree != 0)
				{
					Node p;
					p = this.list[i].head;
					while (p != null)
					{
						if (p.index == temp)
						{
							this.list[i].degree--;
						}
						p = p.next;
					}
					if (this.list[i].degree == 0)
					{
						s.push(i);
					}
				}
			}
		}
		//如果输出的顶点个数不等与总顶点个数,证明当前存在环。
		if (this.numVretexes != count)
		{
			System.out.print("有向图存在回路!\n");
		}
	}
	//基于DFS的拓扑排序算法
	public void DAG_DFS_Init()
	{
		int []visit;
		int count = 0;
		visit = new int[this.numVretexes];
		for (int i = 0; i < this.numVretexes; i++)
		{
			visit[i] = 0;
		}
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (visit[i] == 0)
			{
				DAG_DFS( visit, i, count);
			}
		}
	}
	public void DAG_DFS(int []visit, int num, int count)
	{
		Node p;
		p = this.list[num].head;
		visit[num] = 1;
		while (p != null && visit[p.index] == 0)
		{
			DAG_DFS(visit, p.index, count);
			p = p.next;
		}
		System.out.print(this.list[num].data+" ");
	}
}
