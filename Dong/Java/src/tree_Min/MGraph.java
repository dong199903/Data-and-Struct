package tree_Min;

import java.util.Scanner;

public class MGraph {
	static int MAX=100;
	private int numVertes;//�������
	private int numEdges;//�߸���
	private int [][] data;//��ά����洢����Ϣ-Ȩֵ
	private char [] vetes;//������Ϣ
	public MGraph()
	{
		this.numVertes = this.numEdges = 0;
	}
	//ͼ�Ĵ���
	public void creat_Graph_Matrix()
	{
		int index1, index2, w;
		
		Scanner sc = new Scanner(System.in);
		System.out.print("������ͼ�Ķ�������ͱߵĸ���: ");
		this.numVertes = sc.nextInt();
		this.numEdges = sc.nextInt();
		this.vetes = new char[this.numVertes];
		this.data = new int[this.numVertes][];
		for (int i = 0; i < this.numVertes; i++)
		{
			this.data[i] = new int[this.numVertes];
		}
		System.out.print("����ÿ��������Ϣ: ");
		for (int i = 0; i < this.numVertes; i++)
		{
			this.vetes[i] = sc.next().charAt(0);
		}
		//��ʼ��Ȩֵ
		for (int i = 0; i < this.numVertes; i++)
		{
			for (int j = 0; j < this.numVertes; j++)
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
		System.out.print("����ߵ���ʼ�±��Ȩֵ\n");
		for (int i = 0; i < this.numEdges; i++)
		{
			index1 = sc.nextInt();
			index2 = sc.nextInt();
			w = sc.nextInt();
			this.data[index1][index2] = w;
			this.data[index2][index1] = w;
		}
	}
	//����������-Prime
	public void Prim(char obj)
	{
		int index = 0, min, k=0;
		//�������temp����¼�����Ƿ񱻷��ʣ�
		int [] temp = new int[this.numVertes];
		//��������dis����ǵ�ǰ��̾��룩
		int [] dis = new int[this.numVertes];
		//ǰ������pre�����ÿ����ǰ���ڵ㣩
		int [] pre = new int[this.numVertes];
		//Ѱ�������±�
		for (int i = 0; i < this.numVertes; i++) {
			if (this.vetes[i] == obj)
			{
				index = i;
				break;
			}
		}
		System.out.print(index+" ");
		//��ʼ������
		for (int i = 0; i < this.numVertes; i++)
		{
			dis[i] = this.data[index][i];
			temp[i] = 0;//δ����
			pre[i] = index;//ǰ���������
		}
		temp[index] = 1;
		for (int i = 1; i < this.numVertes; i++)
		{
			min = MAX;
			//�ҳ���СȨֵ�ı�,����ǵ�
			for (int j = 0; j < this.numVertes; j++)
			{
				if (temp[j] == 0 && dis[j] < min)
				{
					min = dis[j];
					k = j;
				}
			}
			//�����
			System.out.print(this.vetes[index] + "-->" + this.vetes[k] + "\n");
			//�޸�dis,temp,pre����
			temp[k] = 1;
			index = k;
			for (int j = 0; j < this.numVertes; j++)
			{
				if (temp[j] == 0 && this.data[k][j] < dis[j])
				{
					dis[j] = this.data[k][j];
					pre[j] = k;
				}
			}
		}
	}
	//��С������-Kruskal
	public void Kruskal()
	{
		int min = MAX, temp, num = 0, begin, end;
		Edge swap;
		Edge [] edge = new Edge[this.numEdges];
		UFStree [] Utree = new UFStree[this.numVertes];
		//��ʼ��edge��Utree
		for(int i=0;i<this.numEdges;i++)
		{
			edge[i] = new Edge();
		}
		for (int i = 0; i < this.numVertes; i++)
		{
			Utree[i] = new UFStree();
			Utree[i].high = 0;
			Utree[i].index = i;
			Utree[i].parent = i;
			for (int j = 0; j < this.numVertes; j++)
			{
				if (i<j && this.data[i][j] != 0 && this.data[i][j] != MAX)
				{
					edge[num].begin = i;
					edge[num].end = j;
					edge[num].w = this.data[i][j];
					num++;
				}
			}
		}
		//���ձߵ�Ȩֵ����(��С����)
		for (int i = 0; i < num; i++)
		{
			min = edge[i].w;
			temp = i;
			for (int j = i + 1; j < num; j++)
			{
				if (edge[j].w < min)
				{
					min = edge[j].w;
					temp = j;
				}
			}
			if (temp != i)//ֵ����
			{
				swap = edge[i];
				edge[i] = edge[temp];
				edge[temp] = swap;
			}
		}
		//��������ߵ�ɸѡ
		for (int i = 0; i < this.numEdges; i++)
		{
			begin = edge[i].begin;
			end = edge[i].end;
			if (find_Tree(Utree, begin) != find_Tree(Utree, end))
			{
				union_Tree(Utree, begin, end);
				System.out.println(this.vetes[begin]+"-->"+this.vetes[end]+" "+this.data[begin][end]);
			}
		}
	}
	
	
	//���鼯�Ĳ���
	public int find_Tree(UFStree [] tree, int num)
	{
		if (tree[num].parent == num)//������//
		{
			return num;
		}
		else
		{
			return find_Tree(tree, tree[num].parent);
		}
	}
	//���鼯�ڵ�ĺϲ�
	public void union_Tree(UFStree [] tree, int x, int y)
	{
		//���ҵ����Ը����жϸ߶�
		int xP = find_Tree(tree, x);
		int yP = find_Tree(tree, y);
		if (tree[xP].high > tree[yP].high)
		{
			tree[y].parent = xP;
		}
		else if (tree[xP].high < tree[yP].high)
		{
			tree[x].parent = yP;
		}
		else
		{
			tree[y].parent = xP;
			tree[xP].high++;
		}
	}
}
