package Sort3;

import java.util.Scanner;

public class Sort {
	private int [] arr;
	private int len;
	//有参构造
	public Sort(int len)
	{
		this.len = len;
		this.arr =  new int[this.len];
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<this.len;i++)
		{
			System.out.print("请输入第"+(i+1)+"个数据");
			arr[i] = sc.nextInt();
		}
	}
	
	public void sort_Count()
	{
		int min, max;
		int i;
		min = this.arr[0];
		max = this.arr[0];
		//找最小和最大值
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
		//按最小值和最大值创建数组
		int []arr2 = new int[max - min + 1];
		int num = 0 - min;//关键的一个数字
		for (i = 0; i < max - min + 1; i++)
		{
			arr2[i] = 0;
		}
		for (i = 0; i < this.len; i++)
		{
			arr2[this.arr[i] + num]++;
		}
		//将数组前缀相加
		for (i = 1; i < max - min + 1; i++) 
		{
			arr2[i] = arr2[i] + arr2[i - 1];
		}
		//创建arr3,逆序遍历原数组，按值找到temp数组位置
		int []arr3 = new int[this.len];
		for (i = this.len - 1; i >= 0; i--)
		{
			int index;//标记arr2数组下标
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
		table = new Tool[this.len];//桶
		table[0] = new Tool();
		for (i = 1; i < this.len; i++)
		{
			table[i] = new Tool();
			if (arr[i] > max)
			{
				max = arr[i];
			}
			table[i].next = null;//初始化桶
		}
		table[0].next = null;
		//遍历数组，分别入桶
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
		//遍历桶，取出数据
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
		//1.找出最大数
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
		//2.确定最大数的位数
		count = 0;
		while (max != 0)
		{
			max = max / 10;
			count++;
		}
		//3.从最低位开始逐个放数据，取数据
		Array [] array = new Array[10];//存放0--9的桶
		for (i = 0; i < 10; i++)
		{
			array[i] = new Array();
			array[i].data = new int[this.len];//每个桶的最大容量就是待排序数据
			array[i].len = 0;//每个桶里面数据暂时为空
		}
		
		for (i = 1; i <= count; i++)
		{
			//数据逐个放入对应的桶
			for (j = 0; j < this.len; j++)
			{
				index = 0;//标记第i位
				temp = this.arr[j];
				while (temp != 0 && index < i)
				{
					num = temp % 10;//保存第i位数据
					temp = temp / 10;
					index++;
				}
				if (temp == 0)
				{
					num = 0;//第i位的数据是0
				}
				//放在对应下标的桶里面
				array[num].data[array[num].len++] = this.arr[j];
			}
			//取出逐个桶数据，归位
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
