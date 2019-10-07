package Graph;

import java.util.Scanner;

public class LGraph_List {
	
	private LGraph [] list;
	private int numVretexes;//�������
	private int numEdges;//�ߵĸ���
	public LGraph_List()
	{
		this.numEdges = this.numVretexes = 0;
	}
	 //ͼ�Ĵ���
	public void creat_Graph_List()
	{
		int x1, x2;
		System.out.print("������ͼ�Ķ�������ͱ߸��� ");
		Scanner sc=  new Scanner(System.in);
		this.numVretexes = sc.nextInt();
		this.numEdges = sc.nextInt();
		this.list = new LGraph[this.numVretexes];
		System.out.print("������ͼ�Ķ�����Ϣ ");
		for (int i = 0; i < this.numVretexes; i++)
		{
			this.list[i] = new LGraph();
			this.list[i].data = sc.next().charAt(0);
			this.list[i].head = null;
		}
		System.out.print("������ͼ�ı���Ϣ\n");
		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("�������"+(i+1)+"���ߵĶ����±� "); 
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
	//ͼ�Ĵ�ӡ
	public void print_Graph_List()
	{
		System.out.println("ͼ���ڽӱ�����: ");
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print(this.list[i].data+" ");
			Node s = this.list[i].head;
			while (s != null)
			{
				System.out.print(this.list[s.index].data + "-->");
				s = s.next;
			}
			System.out.println();
		}
	}
	
}
