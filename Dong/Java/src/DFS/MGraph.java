package DFS;

import java.util.Scanner;
import java.util.Stack;

public class MGraph {
	private int [][]data;//��ά����
	private int numVretexes;//�������
	private int numEdges;//�ߵĸ���
	private char []vetex;//��������
	public MGraph()
	{
		this.numVretexes = this.numEdges = 0;
	}
	public void creat_Graph_Matrix()
	{
		int x1, x2;
		System.out.print("������ͼ�Ķ�������ͱߵĸ���:  ");
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
			System.out.print("�������"+(i+1)+"��������Ϣ:");
			this.vetex[i] = sc.next().charAt(0);
		}

		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("�������"+(i+1)+"������Ϣ:");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			this.data[x1][x2] = 1;//�������������ӹ��ɱ�
			this.data[x2][x1] = 1;
		}
	}
	public void print_Graph_Matrix()
	{
		System.out.print("ͼ�Ķ�����Ϣ��:");
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
	
	//ͼ����ȱ���-�ڽӾ���-�ݹ�
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
			if (visit[i] == 0)//�ö���δ�������������������
			{
				DFS(i, visit);
			}
		}
		System.out.println();
	}
	public void DFS(int index, int [] visit)
	{
		System.out.print(this.vetex[index]+" ");
		visit[index] = 1;//����߹���
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (visit[i] == 0 && this.data[index][i] != 0)
			{
				DFS(i, visit);
			}
		}
	}
	//ͼ����ȱ���-�ڽӾ���-�ǵݹ�
	public void DFS_Matrix_Stack(int index)
	{
		//�����Ƕ����Ƿ����
		int []temp = new int[this.numVretexes];
		int i, j;
		//������ʱ�洢ջ
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
			int num =s.peek();//ȡջ��Ԫ��
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
	//ͼ�������������-�ڽӾ���(����������֮���·��)
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
		if (obj1 == obj2)//�ҵ���·�������·��
		{
			for (int i = 0; i < newarr.len; i++)
			{
				System.out.print(this.vetex[i]+" ");
			}
			System.out.println();
		}
		for (int j = 0; j < this.numVretexes; j++)
		{
			if (this.data[obj1][j] != 0 && temp[j] == 0)//�й����ĵ�
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
