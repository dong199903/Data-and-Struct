package DFS;

import java.util.Scanner;
import java.util.Stack;

public class LGraph_List {
	private LGraph [] list;
	private int numVretexes;//�������
	private int numEdges;//�ߵĸ���
	public LGraph_List()
	{
		this.numEdges = this.numVretexes = 0;
	}
	 //ͼ�Ĵ���-�ڽӱ�
	public void creat_Graph_List()
	{
		int x1, x2;
		System.out.print("������ͼ�Ķ�������ͱ߸��� ");
		Scanner sc = new Scanner(System.in);
		this.numVretexes = sc.nextInt();
		this.numEdges = sc.nextInt();
		this.list = new LGraph[this.numVretexes];
		System.out.print("������ͼ�Ķ�����Ϣ ");
		for (int i = 0; i < this.numVretexes; i++)
		{
			this.list[i] = new LGraph();
			this.list[i].data = sc.next().charAt(0);
			System.out.print(this.list[i].data+"");
			this.list[i].head = null;
		}
		System.out.println("������ͼ�ı���Ϣ");
		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("�������" + (i + 1)+"������Ϣ");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			Node s1, s2;
			s1 = new Node();
			s2 = new Node();
			s1.index = x1;
			s2.index = x2;
			s1.next = this.list[x2].head;
			this.list[x2].head = s1;
			s2.next = this.list[x1].head;
			this.list[x1].head = s2;
		}
	}
	//ͼ����ȱ���-�ڽӱ�-�ݹ�
	public void DFS_List()
	{
		int []visit;
		visit = new int[this.numVretexes];
		for (int i = 0; i < this.numVretexes; i++)
		{
			visit[i] = 0;
		}
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (visit[i] == 0)
				DFS_DG(visit, i);
		}
		System.out.println();
	}
	public void DFS_DG( int []visit, int index)
	{
		System.out.print(this.list[index].data+" ");
		visit[index] = 1;
		Node s = this.list[index].head;
		while (s != null)
		{
			if (visit[s.index] == 0)
			{
				DFS_DG(visit, s.index);
			}
			s = s.next;
		}
	}
	//ͼ����ȱ���-�ڽӱ�-�ǵݹ�
	public void DFS_List_Stack()
	{
		int []visit;
		int num;
		Stack<Integer> s = new Stack();
		visit = new int[this.numVretexes];
		for (int i = 0; i < this.numVretexes; i++)
		{
			visit[i] = 0;
		}
		s.push(0);
		visit[0] = 1;
		System.out.print(this.list[0].data+" ");
		while (!s.isEmpty())
		{
			num = s.peek();
			Node n;
			n = this.list[num].head;
			while (n != null)
			{
				if (visit[n.index] == 0)
				{
					System.out.print(this.list[n.index].data+" ");
					s.push(n.index);
					visit[n.index] = 1;
					break;
				}
				n = n.next;
			}
			if (n == null)
			{
				s.pop();
			}
		}
		System.out.println();
	}
}
