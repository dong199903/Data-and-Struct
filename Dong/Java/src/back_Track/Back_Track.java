package back_Track;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019��10��3�� ����9:33:11
 >
 > 1��
 > 2��
 > 3��
 ************************************************************************/
public class Back_Track {
	
	/*-------------�ݼ�����-----------------*/
	private int[]data1;//�ݼ�����ԭ����
	private int[]data2;//�ݼ�����洢�������
	
	
	
	/*-------------0-1��������-----------------*/
	private int w[] = { 5,3,2,1 };//����������Ʒ��������
	private int v[] = {4,4,3,1};//����������Ʒ��ֵ����
	private int result[] = { -1 ,-1,-1,-1};//��������ѡ����Ʒ����
	private int weight;//�����������
	private int sumWeight;//����������Ʒ������
	public int maxValue;//������ǰ����ֵ
	
	/*-------------����װ������---------------*/
	private int results[] = {0,0,0,0,0};
	private int ws[] = {5,2,6,4,3};
	private int maxW = 10;
	public int maxNum = -9999;
	
	/*-------------ȫ��������-----------------*/
	private int data3[] = {1,2,3};//ȫ��������
	
	
	
	/*-------------�����������-----------------*/
	private int data4[] = {1,2,3,4};//������乤�����
	public int minCost = 999999;//��С�ɱ�
	private int task[][] = { {9,2,7,8},{6,4,3,7},{5,8,1,5},{7,6,9,4} };
	
	
	
	/*-------------���������-----------------*/
	public int maxCount;//����Ÿ���
	private int data5[] = { 1,2,3,4 };//����
	private Task t[];//�����
	
	
	public Back_Track()
	{
		//��ʼ���ݼ�����
		data1 = new int[3];
		data2 = new int[3];
		data1[0] = 1;data1[1] = 2;data1[2] = 3;
		data2[0] = 0;data2[1] = 0;data2[2] = 0;
		//��ʼ����������
		weight = 6;sumWeight=11;maxValue=0;
		//��ʼ�����������
		t = new Task[4];
		t[0] = new Task(1,3);
		t[1] = new Task(2,5);
		t[2] = new Task(4,8);
		t[3] = new Task(6,10);
	}
	 //�����е��ݼ�-�ݹ�ʵ��
	public void Get_Power_Set(int index)
	{
		//���ݵ�Ҷ��ʱ��ֱ�Ӵ�ӡ�ݼ�
		if (index >= data1.length)
		{
			System.out.print("( ");
			for (int i = 0; i <  data1.length; i++)
			{
				if (data2[i] != 0)
				{
					System.out.print(data2[i] + " ");
				}
			}
			System.out.print(")\n");
		}
		else
		{
			//ѡ���������
			data2[index] = data1[index];
			Get_Power_Set(index + 1);
			//��ѡ���������
			data2[index] = 0;
			Get_Power_Set(index + 1);
		}
	}
	//������������
	public void play_Chess()
	{
		int temp[] = new int[10];//����ǰ�±��Ӧ�����Ƿ�ʹ��
		for (int i = 0; i < 10; i++)
		{
			temp[i] = 0;
		}

		//��ʼ����
		for (int a = 1; a < 10; a++)//----------������
		{
			temp[a] = 1;
			for (int b = 0; b < 10; b++)//----------������
			{
				if (temp[b] == 0)
				{
					temp[b] = 1;
					for (int c = 0; c < 10; c++)//----------���ӳ�
					{
						if (temp[c] == 0)
						{
							temp[c] = 1;
							int x, y, z;
							x = b * 10 + c;
							y = c * 10 + a;
							z = a * 100 + a * 10 + b;
							if (x + y == z)
							{
								System.out.print("��: " + a + " ��:" + b + " ��: " + c);
							}
						}
						temp[c] = 0;
					}
				}
				temp[b] = 0;
			}
			temp[a] = 0;
		}
	}
	//0-1��������
	public void backpack_01(int sumW, int sumV, int index)
	{
		//�����չ��Ҷ�ӽڵ�
		if (index >= w.length)
		{
			//���������������������Ž�
			if (sumW == weight)
			{
				for (int i = 0; i < w.length; i++)
				{
					//�г���ϸװ�����
					//if (result[i] != -1)
					//{
						//System.out.print("��Ʒ���: " + (i + 1) + "\n");
					//}
				}
				if(sumV>maxValue)
				{
					maxValue = sumV;
				}
				//System.out.print("��������: " + sumW + "����ֵ��: " + sumV +"\n");
			}
		}
		else
		{
			if (sumW + w[index] <= weight)
			{
				sumWeight -= w[index];
				result[index] = index;
				backpack_01(sumW + w[index], sumV + v[index], index + 1);
			}
			if (sumW + sumWeight >= weight)
			{
				result[index] = -1;//��ѡ��
				sumWeight += w[index];
				backpack_01(sumW, sumV, index + 1);
			}
		}
	}
	//����װ������--�����ܶ�Ļ��ﱻװ��
	public void optimal(int sumW, int index)
	{
		if (index >= results.length)
		{
			int count = 0;
			for (int i = 0; i < results.length; i++)
			{
				if (results[i] != 0)
				{
					count++;
					//System.out.print("����" + (i + 1) + "��ѡ��" + "\n");
				}
			}
			//System.out.print("�ܸ��� " + count + "\n");
			if(count>this.maxNum)
			{
				maxNum = count;
			}
		}
		else
		{
			if (sumW + ws[index] <= maxW)
			{
				results[index] = 1;
				optimal(sumW + ws[index], index + 1);
			}
			results[index] = 0;
			optimal(sumW, index + 1);
		}
	}
	//ȫ����
	public void sort_All(int index)
	{
		if (index >= data3.length)
		{
			System.out.print("( ");;
			for (int i = 0; i < data3.length; i++)
			{
				System.out.print(data3[i] + " ");
			}
			System.out.print(" )\n");
		}
		else {
			for (int i = index; i < data3.length; i++)
			{
				//��������
				int temp = data3[i];
				data3[i] = data3[index];
				data3[index] = temp;
				sort_All(index + 1);
				//�ָ�����
				temp = data3[i];
				data3[i] = data3[index];
				data3[index] = temp;
			}
		}
	}
	//����������
	public void task_Assign(int index)
	{
		if (index >= data4.length)
		{
			int sum = 0;
			//�������е�����
			for (int i = 0; i < data4.length; i++)
			{
				//System.out.print(task[i][(data4[i] - 1)] + "\n");
				sum += task[i][data4[i]-1];
			}
			if (sum < minCost)
			{
				minCost = sum;
			}
		}
		else {
			for (int i = index; i < data4.length; i++)
			{
				int temp = data4[i];
				data4[i] = data4[index];
				data4[index] = temp;
				task_Assign(index + 1);
				temp = data4[i];
				data4[i] = data4[index];
				data4[index] = temp;
			}
		}
	}
	//�����
	public void plan_Activity(int index)
	{
		if (index >= t.length)
		{
			int count = 1, last;
			//���л���Ÿ�����ͳ��,��ӡÿ�����˳��
			last = t[data5[0] - 1].end;//����ʱ��
			for (int i = 1; i < t.length; i++)
			{
				if (t[data5[i] - 1].begin >= last)
				{
					count++;
					last = t[data5[i] - 1].end;
				}
			}
			if (count > maxCount)
			{
				maxCount = count;
			}
		}
		else {
			for (int i = index; i < t.length; i++)
			{
				int temp = data5[index];
				data5[index] = data5[i];
				data5[i] = temp;
				plan_Activity(index + 1);
				temp = data5[index];
				data5[index] = data5[i];
				data5[i] = temp;
			}
		}
	}
}
