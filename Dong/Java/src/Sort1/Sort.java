package Sort1;

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
		//ð������
		public void sort_Bubble()
		{
			int  flag;
			int temp;
			for (int i = 0; i < this.len; i++)
			{
				flag = 1;
				for (int j = 0; j < this.len - i - 1; j++)
				{
					if (this.arr[j] > this.arr[j + 1])
					{
						temp = this.arr[j];
						this.arr[j] = this.arr[j + 1];
						this.arr[j + 1] = temp;
						flag = 0;
					}
				}
				//һ��û���������������Ѿ�����OK
				if (flag == 1)
				{
					return;
				}
			}
		}
		//ѡ������
		public void sort_Choice()
		{
			int index;
			int min;
			for (int i = 0; i < this.len; i++)
			{
				min = arr[i];
				index = i;
				for (int j = i + 1; j < this.len; j++)
				{
					if (arr[j] < min)
					{
						min = arr[j];
						index = j;
					}
				}
				if (index != i)
				{
					int temp = arr[index];
					arr[index] = arr[i];
					arr[i] = temp;
				}
			}
		}
		//��������
		public void sort_Insert()
		{
			int  index;
			int data;
			for (int i = 1; i < this.len; i++)
			{
				data = arr[i];
				index = i - 1;
				while (index >= 0 && data < arr[index])
				{

					arr[index + 1] = arr[index];
					index--;
				}
				arr[index + 1] = data;
			}
		}
		//�������
		public void print()
		{
			for (int j = 0; j < this.len; j++)
			{
				System.out.println(this.arr[j]+" ");
			}
			System.out.println();
		}
}
