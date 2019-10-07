package BFS;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class LGraph_List {
	private LGraph [] list;
	private int numVretexes;//�������
	private int numEdges;//�ߵĸ���
	public LGraph_List()
	{
		this.numVretexes = this.numEdges = 0;
	}
	//ͼ�Ĵ���-�ڽӱ�
	public void creat_Graph_List()
	{
		int x1, x2;
		Scanner sc = new Scanner(System.in);
		System.out.print("������ͼ�Ķ�������ͱ߸��� ");
		this.numVretexes = sc.nextInt();
		this.numEdges = sc.nextInt();
		this.list = new LGraph[this.numVretexes];
		System.out.print("������ͼ������Ϣ ");
		for (int i = 0; i < this.numVretexes; i++)
		{
			this.list[i] = new LGraph();
			this.list[i].data = sc.next().charAt(0);
			this.list[i].head =null;
		}
		System.out.print("������ͼ����Ϣ ");
		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("������ͼ�� "+(i+1)+"������Ϣ");
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
	//ͼ�Ĺ�ȱ���-�ڽӱ�
	public void BFS_List_Queue()
	{
		int []visit;
		Queue<Integer> q = new LinkedList<Integer>();
		visit = new int[this.numVretexes];
		for (int i = 0; i < this.numVretexes; i++)
		{
			visit[i] = 0;
		}
		//��ʼ�õ�һ��Ԫ�����
		q.offer(0);
		System.out.print(this.list[0].data+" ");
		visit[0] = 1;
		while (!q.isEmpty())
		{
			Node s = this.list[q.poll()].head;
			while (s != null)
			{
				if (visit[s.index] == 0)
				{
					q.offer(s.index);
					visit[s.index] = 1;
					System.out.print(this.list[s.index].data+" ");
				}
				s = s.next;
			}
		}
		System.out.println();
	}
}
