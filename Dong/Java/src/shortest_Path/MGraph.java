package shortest_Path;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019��10��3�� ����5:11:20
 >
 > 1����ջ�Ļ���ʵ��
 > 2����ջ�ͳ�ջ�Ȼ�������
 > 3��
 ************************************************************************/
public class MGraph {
	private int [][]data;//��ά����
	private int numVretexes;//�������
	private int numEdges;//�ߵĸ���
	private char []vetex;//��������
	private static int MAX = 9999;
	public MGraph()
	{
		this.numEdges = this.numVretexes = 0;
	}
	//ͼ�Ĵ���
	public void creat_Graph_Matrix()
	{
		int x1, x2, w;
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
				if (i == j)
				{
					this.data[i][j] = 0;
				}
				else
				{
					this.data[i][j] = MAX;
				}

			}
		}
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print("�������" +(i + 1) + "��������Ϣ: ");
			this.vetex[i] = sc.next().charAt(0);
		}
		for (int i = 0; i < this.numEdges; i++)
		{
			System.out.print("�������" +(i + 1) + "������Ϣ: ");
			x1 = sc.nextInt();
			x2 = sc.nextInt();
			w = sc.nextInt();
			this.data[x1][x2] = w;//�������������ӹ��ɱ�
			this.data[x2][x1] = w;
		}
	}
	//�Ͻ�˹�����㷨
	public void Dijkstra(char obj)
	{
		int []temp, dis, pre;
		int index=0, min=0, k=0;
		temp = new int[this.numVretexes];
		dis = new int[this.numVretexes];
		pre = new int[this.numVretexes];
		//�ҳ�Դ�ڵ��λ��
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (this.vetex[i] == obj)
			{
				index = i;
				break;
			}
		}
		//��ʼ����������
		for (int i = 0; i < this.numVretexes; i++)
		{
			temp[i] = 0;
			pre[i] = -1;
			dis[i] = this.data[index][i];
		}
		temp[index] = 1;
		for (int i = 1; i < this.numVretexes; i++)
		{
			min = MAX;
			//�ҳ���ǰdis�洢��С���±�
			for (int j = 0; j < this.numVretexes; j++)
			{
				if (temp[j] == 0 && this.data[index][j] < min)
				{
					min = this.data[index][j];
					k = j;//�����Сֵ��λ��
				}
			}
			temp[k] = 1;
			index = k;
			//�Ӹõ㿪ʼ������жϲ��޸�dis����
			for (int j = 0; j < this.numVretexes; j++)
			{
				if (temp[j] == 0 && (this.data[k][j] + dis[k]) < dis[j])
				{
					dis[j] = this.data[k][j] + dis[k];
					pre[j] = k;
				}
			}
		}

		//dis�������Դ�㵽����������·��
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print(obj + "-->" + this.vetex[i] + "("+dis[i]+")");
		}
		System.out.println();
	}
	//������-�����㷨
	public void Bellman_Ford(char obj)
	{
		int []dis, pre;
		int index=0, temp;
		dis = new int[this.numVretexes];
		pre = new int[this.numVretexes];
		//�ҳ�Ŀ���λ��
		for (int i = 0; i < this.numVretexes; i++)
		{
			if (this.vetex[i] == obj) {
				index = i;
				break;
			}
		}
		//��ʼ��dis����
		for (int i = 0; i < this.numVretexes; i++)
		{
			dis[i] = MAX;
			pre[i] = -1;
		}
		dis[index] = 0;
		for (int k = 1; k < this.numVretexes; k++)
		{
			for (int i = 0; i < this.numVretexes; i++)
			{
				for (int j = 0; j < this.numVretexes; j++)
				{
					if (j != index && i != j && this.data[i][j] != MAX)
					{
						if (dis[i] + this.data[i][j] < dis[j])
						{
							dis[j] = dis[i] + this.data[i][j];
							pre[j] = i;
						}
					}
				}
			}
		}
		//�����ɳں�����������ɳڣ���ʾͼ�д��ڸ���Ȩ��·
		temp = 0;
		for (int i = 0; i < this.numVretexes; i++)
		{
			for (int j = 0; j < this.numVretexes; j++)
			{
				if (j != index && i != j && this.data[i][j] != MAX)
				{
					if (dis[i] + this.data[i][j] < dis[j])
					{
						temp = 1;
						System.out.print("ͼ�д��ڸ�Ȩ��·\n");
						return;
					}
				}
			}

		}
		//���dis����
		for (int i = 0; i < this.numVretexes; i++)
		{
			System.out.print(dis[i] +" ");
		}
		System.out.println();
	}
	//SPFA�㷨
	public void SPFA(char obj)
	{
		int index=0, i,top;
		int []visit, dis, path;
		Queue<Integer> q = new LinkedList<Integer>();
		visit = new int[this.numVretexes];
		dis = new int[this.numVretexes];
		path = new int[this.numVretexes];
		//1.�ҳ�Դ��
		for (i = 0; i < this.numVretexes; i++)
		{
			if (this.vetex[i] == obj)
			{
				index = i;
			}
		}
		//2:��ʼ������,��������
		for (i = 0; i < this.numVretexes; i++)
		{
			visit[i] = 0;
			dis[i] = MAX;
			path[i] = -1;
		}
		q.offer(index);
		visit[index] = 1;
		dis[index] = 0;
		while (!q.isEmpty())//���пս���
		{
			top = q.poll();
			visit[top] = 0;
			for (i = 0; i < this.numVretexes; i++)
			{
				if (i != top)
				{
					if (dis[i] >(dis[top] + this.data[top][i]))
					{
						dis[i] = dis[top] + this.data[top][i];
						path[i] = top;
						if (visit[i] == 0)//û�ڶ�����,���
						{
							q.offer(i);
							visit[i] = 1;
						}
					}
				}
			}
		}
		//�����˾����·��
		for (i = 0; i < this.numVretexes; i++)
		{
			if (i != index)
			{
				System.out.print(this.vetex[index] + "-->" + this.vetex[i] + dis[i]);
			}
		}
		System.out.println();
	}
	//Floyd�㷨
	public void Floyd()
	{
		int i, j, k, temp = 0;
		int [][]dis,path;
		dis = new int[this.numVretexes][];
		path = new int[this.numVretexes][];
		for (i = 0; i < this.numVretexes; i++)
		{
			dis[i] = new int[this.numVretexes];
			path[i] = new int[this.numVretexes];
		}
		//��ʼ��dis��path����
		for (i = 0; i < this.numVretexes; i++)
		{
			for (j = 0; j < this.numVretexes; j++)
			{
				dis[i][j] = this.data[i][j];
				path[i][j] = -1;
			}
		}
		//��ʼ�����p���ж�
		for (i = 0; i < this.numVretexes; i++)
		{
			//���ȡ��ÿ������x,y���ж�dis[x][y] > dis[x][p]+dis[p][y]
			for (j = 0; j < this.numVretexes; j++)
			{
				for (k = 0; k < this.numVretexes; k++)
				{
					if (dis[j][k] > dis[j][i] + dis[i][k])
					{
						dis[j][k] = dis[j][i] + dis[i][k];
						path[j][k] = i;
					}
				}
			}
		}

		//�����̾���
		for (i = 0; i < this.numVretexes; i++)
		{
			for (j = 0; j < this.numVretexes; j++)
			{
				if (i != j)
				{
					print_Path(i, j, path);
					System.out.print(dis[i][j]+" ");
				}
			}
		}
	}
	public void print_Path(int begin, int last,int [][]path)
	{
		if (path[begin][last] == -1)
		{
			System.out.print(this.vetex[begin]+"-->"+this.vetex[last]+"-->");
		}
		else
		{
			int mid = path[begin][last];
			print_Path(begin, mid, path);
			print_Path(mid, last,  path);
		}
	}
}
