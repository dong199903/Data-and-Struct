package bound_Branch;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Bound_Branch {
	/*------------------0-1����---------------------*/
	public int maxValue;
	public int countPack;
	public int minCost;
	private int w[] = { 16,15,15 };
	private int v[] = { 45,25,25 };
	private static int MAX = 50;
	private static int INF = 88888;
	Bound_Branch()
	{
		maxValue = -99999;
		countPack = w.length;
		minCost = 99999;
	}
	//��ǰ�ڵ������Ͻ�
	void bound(Node []n, int index,int maxWeight)
	{
		int lever = n[index].lever;//��ǰ�ڵ���
		int sumW = n[index].weight;
		int sumV = n[index].value;
		while (sumW <= maxWeight && lever<countPack)
		{
			sumW += w[lever];
			sumV += v[lever];
			lever++;
		}
		if (lever < countPack)//δ��ȫ��װ
		{
			n[index].up = sumV + (maxWeight - sumW)*v[lever] / w[lever];
		}
		else {//ȫ��װ��
			n[index].up = sumV;
		}
	}
	//���ĺ���
	void packages(int maxWeight)
	{
		int count = 0,index = 0,top=0;
		Queue<Integer> q = new LinkedList<Integer>();
		Node []n = new Node[50];//���ڵ�
		for(int i=0;i<50;i++)
		{
			n[i] = new Node();
		}
		n[index].lever = n[index].value = n[index].weight = n[index].no = 0;
		bound(n, index,  maxWeight);
		//�ø��ڵ����
		q.offer(n[index].no);
		while (!q.isEmpty())
		{
			//������Ԫ��
			top = q.poll();//�õ����
			//�������Ͻ�,��ǰ��������ֵ������,���
			n[2 * top + 1].no = 2*n[top].no + 1;//���
			n[2 * top + 1].lever = n[top].lever + 1;//����
			System.out.print(n[2 * top + 1].lever+"\n");
			n[2 * top + 1].weight = n[top].weight + w[n[2 * top + 1].lever-1];//����
			n[2 * top + 1].value = n[top].value + v[n[2 * top + 1].lever-1];//��ֵ
			bound(n, 2 * top + 1,  maxWeight);
			//�������������������
			if (n[2 * top + 1].up > maxValue && n[2 * top + 1].weight <= maxWeight)
			{
				//���������Ѿ�ʱҶ�ӽڵ㣬������ڵ�ǰ���Ž⣬�����(����ɲ��룬�������),�޸����Ž�
				if (n[2 * top + 1].lever == countPack)
				{
					if (n[2 * top + 1].value > maxValue)
					{
						maxValue = n[2 * top + 1].value;
					}
				}
				else {
					q.offer(n[2 * top + 1].no); 
				}

			}
			////���Һ����Ͻ�,��ǰ��������ֵ������
			n[2 * top + 2].no = 2*n[top].no + 2;//���
			n[2 * top + 2].lever = n[top].lever + 1;//����
			n[2 * top + 2].weight = n[top].weight; //����
			n[2 * top + 2].value = n[top].value;//��ֵ
			bound(n, 2 * top + 2,  maxWeight);
			//�Һ������������������
			if (n[2 * top + 2].up > maxValue)
			{
				//�����Һ����Ѿ�ʱҶ�ӽڵ㣬������ڵ�ǰ���Ž⣬�����(����ɲ��룬�������),�޸����Ž�
				if (n[2 * top + 2].lever == countPack)
				{
					if (n[2 * top + 2].value > maxValue)
					{
						maxValue = n[2 * top + 2].value;
					}
				}
				else {
					q.offer(n[2 * top + 2].no);
				}
			}
		}
		System.out.print("����ֵ��: " + maxValue + "\n");
	}


	/*------------------��Դ���·��-----------------*/
	void minPath()//����ͼ������ͼ������
	{
		int [][]data;
		int []dis,queue,path;//��ά����洢��������
		dis = new int[MAX];
		queue = new int[MAX];
		path = new int[MAX];
		data = new int[MAX][];
		int numEdge, numVer, x, y, w, temp,front, rear, top;
		front = rear = 0;
		System.out.print("������ͼ�ĵ������ͱ߸��� ");
		Scanner sc = new Scanner(System.in);
		numVer = sc.nextInt();
		numEdge = sc.nextInt();
		//��ʼ��ͼ��Ȩֵ
		for (int i = 0; i < MAX; i++)
		{
			data[i] = new int [MAX];
			for (int j = 0; j < MAX; j++)
			{
				data[i][j] = INF;
				dis[j] = INF;
				path[j] = -1;
				if (i == j)
				{
					data[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < numEdge; i++)
		{
			System.out.print("������ÿ���ߵ���±��Ȩֵ: ");
			x = sc.nextInt();
			y = sc.nextInt();
			w = sc.nextInt();
			data[x][y] = w;
		}
		//��ʼ���,�������±�0�����������̾���
		queue[rear++] = 0;
		dis[0] = 0;
		while (front != rear)
		{
			//����ͷԪ��
			top = queue[front++];
			for (int i = 0; i < numVer; i++)
			{
				//���ڸ���·�������õ�����С�
				if (data[top][i] < INF&& i != top && dis[top] + data[top][i] < dis[i])
				{
					dis[i] = dis[top] + data[top][i];
					path[i] = top;
					//������ڶ��У�����ӡ�
					temp = 0;
					for (int j = front; j <= rear; j++)
					{
						if (queue[j] == i)
						{
							temp = 1;
							break;
						}
					}
					if (temp == 0)
					{
						queue[rear++] = i;
					}
				}
			}
		}
		//�����̾���
		for (int i = 1; i < numVer; i++)
		{
			System.out.print(dis[i]);
		}
	}

	/*------------------�������---------------------*/
	void assign_Task()
	{
		//����ÿ���˶�Ӧÿ������ĳɱ�
		int cost[][] = { {9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };
		int front, rear;
		Task queue[] = new Task[MAX];
		Task node1, node2, top;//����
		node1 = new Task();
		node2 = new Task();
		//����и��ڵ�
		node1.lever = node1.cost = front = rear = 0;
		for (int i = 0; i < 4; i++)
		{
			node1.temp[i] = 0;//����δ����
		}
		getLow(node1, cost);
		queue[rear++] = node1;
		while (front != rear)
		{
			top = queue[front++];//����
			//����һ�˷�������
			for (int i = 0; i < 4; i++)
			{
				if (top.temp[i] == 0)//��ǰ����δ������,���������������ˡ�
				{
					for (int j = 0; j < 4; j++)//����temp��node2
					{
						node2.temp[j] = top.temp[j];
					}
					node2.temp[i] = 1;
					node2.lever = top.lever + 1;
					node2.cost = top.cost + cost[node2.lever-1][i];
					//cout << node2.cost << endl;
					getLow(node2, cost);//���½�
					if (node2.down < minCost)
					{
						if (node2.lever == 4)//����Ҷ�ӽڵ�
						{
							//for (int k = 0; k < 4; k++)
							//{
							//printf_s("%d ", node2.temp[k]);
							//}
							//printf_s("\n");
							minCost = node2.cost;
							//printf_s("%d\n", minCost);
							queue[rear++] = node2;
						}
						else {
							queue[rear++] = node2;
						}
					}
				}
			}
		}
		System.out.print(minCost);
	}
	//����½�
	void getLow(Task t, int [][]cost)
	{
		int sum = 0;
		for (int i = t.lever; i < 4; i++)
		{
			int min = 9999;
			for (int j = 0; j < 4; j++)
			{
				if (t.temp[j] == 0 && cost[i][j] < min)
				{
					min = cost[i][j];
				}
			}
			sum += min;
		}
		t.down = sum + t.cost;
	}
	
}
