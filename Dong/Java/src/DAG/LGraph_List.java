package DAG;

import java.util.Scanner;
import java.util.Stack;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019��10��3�� ����4:41:50
 >
 > 1����ջ�Ļ���ʵ��
 > 2����ջ�ͳ�ջ�Ȼ�������
 > 3��
 ************************************************************************/
public class LGraph_List {
	private LGraph [] list;
	private int numVretexes;//�������
	private int numEdges;//�ߵĸ���
	public LGraph_List()
	{
		this.numVretexes = this.numEdges = 0;
	}
	//ͼ�Ĵ���
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
			this.list[i] = new 	LGraph();
			this.list[i].data = sc.next().charAt(0);
			this.list[i].head = null;
			this.list[i].degree = 0;//ÿ��������Ϊ0
		}
		System.out.print("������ͼ����Ϣ ");
		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("�������"+(i+1)+"���ߵĶ˵��±�: ");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			Node s1;
			s1 = new Node();
			s1.index = x1;
			s1.next = this.list[x2].head;
			this.list[x2].head = s1;
			this.list[x2].degree++;//�������1
		}
	}
	
	//KaHn�㷨
	public void KaHn()
	{
		//����ջ�洢���Ϊ0�ĵ�

        Stack<Integer> s=new Stack<Integer>();
		int i, temp, count = 0;
		for (i = 0; i < this.numVretexes; i++)
		{
			if (this.list[i].degree == 0)
			{
				s.push(i);//�洢���ǵ���±�
			}
		}
		//ջ���˳�
		while (!s.isEmpty())
		{
			//��ջջ��Ԫ�أ������ջ��Ԫ��
			temp = s.pop();
			System.out.print(this.list[temp].data+" ");
			count++;
			//��õ��й����Ķ�������һ,������Ϊ0��������ջ��
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
		//�������Ķ�������������ܶ������,֤����ǰ���ڻ���
		if (this.numVretexes != count)
		{
			System.out.print("����ͼ���ڻ�·!\n");
		}
	}
	//����DFS�����������㷨
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
