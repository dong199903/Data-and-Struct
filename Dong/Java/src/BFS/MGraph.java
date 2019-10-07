package BFS;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class MGraph {
	private int [][]data;//��ά����
	private int numVretexes;//�������
	private int numEdges;//�ߵĸ���
	private char []vetex;//��������
	public MGraph()
	{
		this.numEdges = this.numVretexes = 0;
	}
	//ͼ�Ĵ���-�ڽӾ���
	void creat_Graph_Matrix()
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
		for (int i = 0; i < this.numEdges; i++)
		{
	
			System.out.print("�������" + (i + 1) + "������Ϣ ");
			this.vetex[i] = sc.next().charAt(0);
		}

		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("�������" + (i + 1) + "������Ϣ ");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			this.data[x1][x2] = 1;//�������������ӹ��ɱ�
			this.data[x2][x1] = 1;
		}
	}

	//ͼ�Ĺ�ȱ���-�ڽӾ���
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

	//ͼ�Ĺ������-��·��
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
			pre[i] = -1;//ǰ������
			if (obj1 == this.vetex[i])
			{
				index1 = i;
			}
			if (obj2 == this.vetex[i])
			{
				index2 = i;
			}
		}
		//����Ϣ�����˳�
		if (index1 == -1 || index2 == -1)
		{
			return;
		}
		q.offer(index1);
		temp[index1] = 1;
		while (!q.isEmpty())
		{
			num = q.poll();
			if (num == index2)//�ҵ���Ŀ��㣬�����ӡ·��
			{
				while (pre[num] != -1)
				{
					System.out.print(this.vetex[num]);
					num = pre[num];
				}
				System.out.print(this.vetex[num]+" ");
				System.out.println();
			}
			//������ʱ���������й����ĵ������
			for (int i = 0; i < this.numVretexes; i++)
			{
				if (this.data[num][i] != 0 && temp[i] == 0)
				{
					temp[i] = 1;
					q.offer(i);
					pre[i] = num;//���ö����ǰ��
				}
			}
		}
	}
}
