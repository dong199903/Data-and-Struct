package Sort2;

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
	//�鲢����
	public void sort_Merge(int low,int high)
	{
		int mid;
		if (low < high)
		{
			mid = (low + high) / 2;
			sort_Merge(low, mid);
			sort_Merge(mid+1, high);
			Merge(low, mid, high);
		}
	}
	//�鲢
	public void Merge(int low,int mid,int high)
	{
		int []left;
		int [] right;
		int i,j,n,m,k;
		n = mid - low + 1;
		m = high - mid;
		left = new int[n];
		right = new int[m];
		for (i = 0; i <= n; i++) 
		{
			left[i] = this.arr[low + i];
		}
		for (i = 0; i < m; i++)
		{
			right[i] = this.arr[mid + 1 + i];
		}
		i = 0;
		j = 0;
		k=low;
		while (i < n && j < m)
		{
			if (left[i] < right[j])
			{
				this.arr[k++] = left[i++];
			}
			else {
				this.arr[k++] = right[j++];
			}
		}
		while (i < n)
		{
			this.arr[k++] = left[i++];
		}
		while (j < m)
		{
			this.arr[k++] = right[j++];
		}
	}
	//��������
	public void sort_Qucik( int low, int high)
	{
		if (low < high)
		{
			int index = partition(low, high);
			sort_Qucik(low, index - 1);
			sort_Qucik(index+1, high);
		}
	}
	//����
	public int partition(int low, int high)
	{
		int x = this.arr[low];//��һ������Ϊ������۵�
		int i = low, j = high;
		while (i < j)
		{
			//���ұ߿�ʼ��С�ڷ������ֵ�
			while (i < j && arr[j] >= x)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];
			}
			//����߿�ʼ�Ҵ��ڷ������ֵ�
			while (i < j && arr[i] < x)
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}
		//����λ�÷���x
		arr[i] = x;
		return i;
	}
	//ϣ������
	public void sort_Shell(int len)
	{
		int step, i, j,data,index;
		for (step = len / 2; step > 0; step /= 2)
		{
			for (i = 0; i < step; i++)
			{
				//��ʼ��������
				for (j = i+step; j < len; j += step)
				{
					data = arr[j];
					index = j - step;
					while (index >= i && data < arr[index])
					{
						arr[index + step] = arr[index];
						index = index - step;
					}
					arr[index + step] = data;
				}
			}
		}
	}
	//������
	void sort_Heap(int len)
	{
		//�ӷ�Ҷ�ӽڵ㵽���ڵ㿪ʼ�����������󶥶�
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			adjust_Heap(i,len);
		}
		//��ʼ���������
		for (int i = len-1; i > 0; i--)
		{
			int temp = arr[i];
			arr[i] = arr[0];
			arr[0] = temp;
			//�������ݽ��������������
			adjust_Heap(0, i);
		}
	}
	//�ѵĵ���
	public void adjust_Heap(int index,int len)
	{
		//�ӵ�ǰ�ڵ㿪ʼ������һֱ�����ߵ����һ����Ҷ�ӽڵ�
		int maxIndex,temp;
		while (index <= len/2-1)
		{
			maxIndex = index;
			//�ҳ����Һ��Ӻ��Լ�����֮������ֵ��
			if (2*index+1 <len && arr[maxIndex]< arr[2 * index+1])
			{
				maxIndex = 2 * index + 1;
			}
			if (2 * index + 2 < len && arr[maxIndex]< arr[2 * index + 2])
			{
				maxIndex = 2 * index + 2;
			}
			//����ҵ������ֵ�����Լ�����������,�������µ�����.
			if (maxIndex != index)
			{
				temp = arr[maxIndex];
				arr[maxIndex] = arr[index];
				arr[index] = temp;
				index = maxIndex;
			}
			else
			{
				return ;
			}
		}
	}
	//�������
	public void print(int len)
	{
		for (int i = 0; i < len; i++)
		{
			System.out.print(this.arr[i]+" ");
		}
		System.out.println();
	}
}
