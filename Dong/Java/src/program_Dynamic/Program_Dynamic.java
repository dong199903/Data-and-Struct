package program_Dynamic;

import java.util.Scanner;

public class Program_Dynamic {
	private static int MAX = 100;
	//������������к�
	public void maxSum()
	{
		int data[] = { 0,-2,11,-4,13,-5,-2 };//0λ�ò���
		int len = 7,max=-9999;
		int []dp;
		dp = new int[len];
		dp[0] = 0;
		for (int i = 1; i < len; i++)
		{
			if (dp[i - 1] + data[i] > data[i])
			{
				dp[i] = dp[i - 1] + data[i];
			}
			else
			{
				dp[i] = data[i];
			}
		}

		//ֱ���ҳ�dp������󣬾��������
		for (int i = 0; i < len; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
			}
		}
		System.out.print("������������к���:"+max);
	}
	
	
	//���������·��
	public void minPath()
	{
		int i, j, high,min,index,num;
		int [][]data,dp,pre;
		System.out.print("���������εĸ߶�: ");
		Scanner sc = new Scanner(System.in);
		high = sc.nextInt();
		data = new int[high][];
		dp = new int[high][];
		pre = new int[high][];
		//����������(��ά������)
		for (i = 0; i < high; i++)
		{
			data[i] = new int[high];
			dp[i] = new int[high];
			pre[i] = new int[high];
			for (j = 0; j <= i;j++)
			{
				data[i][j] = sc.nextInt();
			}
		}
		
		//��ʼ���߽�����
		dp[0][0] = data[0][0];
		pre[0][0] = -1;
		for (i = 1; i < high; i++)
		{
			dp[i][i] = dp[i - 1][i - 1] + data[i][i];
			dp[i][0] = dp[i - 1][0] + data[i][0];
			pre[i][i] = i-1;
			pre[i][0] = 0;
		}
		//�����������
		for (i = 1; i < high; i++)
		{
			for (j = 1; j < high; j++)
			{
				if (i != j &&j != 0)
				{
					if (dp[i - 1][j - 1] > dp[i - 1][j])
					{
						dp[i][j] = dp[i - 1][j] + data[i][j];
						pre[i][j] = j;
					}
					else {
						dp[i][j] = dp[i - 1][j-1] + data[i][j];
						pre[i][j] = j-1;
					}
				}
			}
		}
		//�ҳ���̾���
		min = dp[high - 1][0];
		index = 0;
		for (i = 1; i < high; i++)
		{
			if (dp[high-1][i] < min)
			{
				min = dp[high-1][i];
				index = i;
			}
		}
		System.out.print("��̾�����:"+min+"����·����: ");
		num = high-1;
		while (num!=0)
		{
			System.out.print(data[num][index]);
			index = pre[num][index];
			num--;	
		}
		System.out.println(data[0][0]);
	}
	
	
	//�����������
	public void maxLen()
	{
		int len, i,j,max;
		int[]data,dp;
		System.out.print("����������鳤��: ");
		Scanner sc = new Scanner(System.in);
		len = sc.nextInt();
		data = new int[len];
		dp = new int[len];
		for (i = 0; i < len; i++)
		{
			data[i] = sc.nextInt();
		}
		for (i = 0; i < len; i++)
		{
			dp[i] = 1;
			for (j = 0; j < i; j++)
			{
				if (data[j] < data[i])
				{
					if (dp[j] + 1 > dp[i])
					{
						dp[i] = dp[j] + 1;
					}
				}
			}
		}
		max = dp[0];
		//�ҳ���󳤶�
		for (i = 1; i < len; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
			}
		}
		System.out.print(max);
	}
	
	
	//0-1����
	public void packages()
	{
		int w[] = { 2,2,6,5,4 };
		int v[] = { 6,3,5,4,6 };
		int len = 5, maxWeight = 10,i,j,weight;//dp����洢���
		int dp[][];
		dp = new int[MAX][];
		for(i=0;i<MAX;i++)
		{
			dp[i] = new int[MAX];
		}
		weight = maxWeight;//weight�洢��ǰ����ʣ������
		for (i = 0; i < len; i++)
		{
			dp[i][0] = 0;
		}
		for (i = 0; i <= weight; i++)
		{
			if (w[0] <= i)
			{
				dp[0][i] = v[0];
			}
			else
			{
				dp[0][i] = 0;
			}
		}
		
		for (i = 1; i < len; i++)
		{
			for (j = 0; j <= weight; j++)
			{
				//�Ƿ���Է��µ�i����Ʒ
				if (j >= w[i])
				{
					if (dp[i - 1][j] > dp[i - 1][j - w[i]] + v[i])
					{
						dp[i][j] = dp[i - 1][j];
					}
					else
					{
						dp[i][j] = dp[i - 1][j - w[i]] + v[i];
					}
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		for (i = 0; i < len; i++)
		{
			for (j = 0; j <= weight; j++)
			{
				System.out.print(dp[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println("����ֵ:"+ dp[4][10]);
		//�����Ƶ�ѡ�����Ʒ
		len--;
		while (len > 0)
		{
			if (dp[len][weight] != dp[len - 1][weight])//ѡ����Ʒlen
			{
				System.out.println("��Ʒ"+(len+1)+"��ѡ��");
				weight -= w[len];
			}
			len--;
		}
		//�ж���Ʒ1�Ƿ�ѡ��
		if(weight!=0)
		{
			System.out.println("��Ʒ"+(len+1)+"��ѡ��");
		}
	}
	
	
	//��ȫ����
	public void full_Pack()
	{
		int weight[] = {3, 4, 2};
		int value[] = { 4,5,3 };
		int len = 3, maxWeight = 7,i,j,k,max;
		int [][]dp,count;
		dp  =new int[MAX][];
		count = new int[MAX][];
		for(i=0;i<MAX;i++)
		{
			dp[i] = new int[MAX];
			count[i] = new int[MAX];
		}
		//��ʼ���߽�
		for (i = 0; i < len; i++)
		{
			dp[i][0] = 0;
		}
		for (i = 0; i <= maxWeight; i++)
		{
			for (k = 0; k*weight[0] <= i; k++)//���������㹻��������Ʒ0Խ�࣬��ֵԽ��
			{
				dp[0][i] = k*value[0];
				count[0][i] = k;
			}
		}
		//��ʼ
		for (i = 1; i < len; i++)
		{
			for (j = 1; j <= maxWeight; j++)
			{
				max = dp[i][0];
				dp[i][j] = max;
				count[i][j] = 0;
				for (k = 0; k*weight[i] <= j; k++)
				{
					if (dp[i - 1][j - weight[i] * k] + value[i] * k > max)
					{
						max = dp[i - 1][j - weight[i] * k] + value[i] * k;
						dp[i][j] = max;
						count[i][j] = k;
					}
				}
			}
		}
		System.out.print("����ֵ:"+dp[2][7]+"\n");
		//���ѡ����Ʒ
		len--;
		while (len >= 0)
		{
			System.out.println((len + 1)+" "+count[len][maxWeight]);
			maxWeight -= weight[len] * count[len][maxWeight];
			len--;
		}
	}
}
