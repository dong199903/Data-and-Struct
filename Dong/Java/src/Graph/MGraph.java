package Graph;

import java.util.Scanner;

public class MGraph {
	private int [][]data;//��ά����
	private int numVretexes;//�������
	private int numEdges;//�ߵĸ���
	private char []vetex;//������
	public MGraph()
	{
		this.numEdges = this.numVretexes = 0;
	}
	//ͼ�Ĵ���
	public void creat_Graph_Matrix()
	{
		int x1, x2;
		System.out.print("������ͼ�Ķ�������ͱߵĸ���: ");
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
				this.data[i][j] = 0;//��ʼ��Ϊ������
			}
		}
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print("�������"+(i+1)+ "���������Ϣ");
			this.vetex[i] = sc.next().charAt(0);
		}

		for (int i = 0; i <this.numEdges; i++)
		{
			System.out.print("�������"+(i+1)+ "���ߵ���Ϣ");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			this.data[x1][x2] = 1;//�������������ӹ��ɱ�
			this.data[x2][x1] = 1;
		}
	}

	//ͼ�Ĵ�ӡ
	public void print_Graph_Matrix()
	{
		System.out.print("ͼ�е���Ϣ��: ");
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print(this.vetex[i]+" ");
		}
		System.out.print("\n�ڽӾ�������\n");
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
