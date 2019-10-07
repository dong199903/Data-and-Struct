package Sort3;

import java.util.Scanner;

public class Sort {
	private int [] arr;
	private int len;
	//�вι���
	public Sort(int len)
	{
		this.len = len;
		this.arr =  new int[this.len];
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<this.len;i++)
		{
			System.out.print("�������"+(i+1)+"������");
			arr[i] = sc.nextInt();
		}
	}
	
	public void sort_Count()
	{
		int min, max;
		int i;
		min = this.arr[0];
		max = this.arr[0];
		//����С�����ֵ
		for (i = 1; i < this.len; i++)
		{
			
			if (arr[i] < min)
			{
				min = arr[i];
			}
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		//����Сֵ�����ֵ��������
		int []arr2 = new int[max - min + 1];
		int num = 0 - min;//�ؼ���һ������
		for (i = 0; i < max - min + 1; i++)
		{
			arr2[i] = 0;
		}
		for (i = 0; i < this.len; i++)
		{
			arr2[this.arr[i] + num]++;
		}
		//������ǰ׺���
		for (i = 1; i < max - min + 1; i++) 
		{
			arr2[i] = arr2[i] + arr2[i - 1];
		}
		//����arr3,�������ԭ���飬��ֵ�ҵ�temp����λ��
		int []arr3 = new int[this.len];
		for (i = this.len - 1; i >= 0; i--)
		{
			int index;//���arr2�����±�
			index = this.arr[i] + num;
			arr3[arr2[index] - 1] = this.arr[i];
			arr2[index]--;
		}
		this.arr = arr3;
	}
	
	public void sort_Bucket()
	{
		int i,j;
		int max, hash;
		Tool [] table;
		Tool temp,p,q;
		max = arr[0];
		table = new Tool[this.len];//Ͱ
		table[0] = new Tool();
		for (i = 1; i < this.len; i++)
		{
			table[i] = new Tool();
			if (arr[i] > max)
			{
				max = arr[i];
			}
			table[i].next = null;//��ʼ��Ͱ
		}
		table[0].next = null;
		//�������飬�ֱ���Ͱ
		for (i = 0; i < this.len; i++)
		{
			hash = (arr[i] * this.len) / (max + 1);
			if (table[hash].next == null)
			{
				temp = new Tool();
				temp.data = this.arr[i];
				temp.next = table[hash].next;
				table[hash].next = temp;
			}
			else
			{
				temp = new Tool();
				temp.data = this.arr[i];
				q = table[hash];
				p = table[hash].next;
				while (p != null && p.data <= temp.data)
				{
					q = q.next;
					p = p.next;
				}
				if (p == null)
				{
					temp.next = p;
					q.next = temp;
				}
				else {
					temp.next = p;
					q.next = temp;
				}
			}
		}
		//����Ͱ��ȡ������
		j = 0;
		for (i = 0; i < this.len; i++)
		{
			p = table[i].next;
			while (p != null)
			{
				this.arr[j++] = p.data;
				p = p.next;
			}
		}
	}
	
	public void sort_Radix()
	{
		//1.�ҳ������
		int max,temp;
		int i,count,j,index,num = 0,biaoji;
		max = this.arr[0];
		for (i = 0; i < this.len; i++)
		{
			if (this.arr[i] > max)
			{
				max = arr[i];
			}
		}
		//2.ȷ���������λ��
		count = 0;
		while (max != 0)
		{
			max = max / 10;
			count++;
		}
		//3.�����λ��ʼ��������ݣ�ȡ����
		Array [] array = new Array[10];//���0--9��Ͱ
		for (i = 0; i < 10; i++)
		{
			array[i] = new Array();
			array[i].data = new int[this.len];//ÿ��Ͱ������������Ǵ���������
			array[i].len = 0;//ÿ��Ͱ����������ʱΪ��
		}
		
		for (i = 1; i <= count; i++)
		{
			//������������Ӧ��Ͱ
			for (j = 0; j < this.len; j++)
			{
				index = 0;//��ǵ�iλ
				temp = this.arr[j];
				while (temp != 0 && index < i)
				{
					num = temp % 10;//�����iλ����
					temp = temp / 10;
					index++;
				}
				if (temp == 0)
				{
					num = 0;//��iλ��������0
				}
				//���ڶ�Ӧ�±��Ͱ����
				array[num].data[array[num].len++] = this.arr[j];
			}
			//ȡ�����Ͱ���ݣ���λ
			this.len = 0;
			
			for (j = 0; j < 10; j++)
			{
				biaoji = 0;
				while (array[j].len != 0)
				{
					this.arr[this.len++] = array[j].data[biaoji++];
					array[j].len--;
				}
			}
		}
	}
	public void print()
	{
		for (int j = 0; j < this.len; j++)
		{
			System.out.print(this.arr[j]+" ");
		}
		System.out.println();
	}
	
}
