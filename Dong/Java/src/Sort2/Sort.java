package Sort2;

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
	//归并排序
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
	//归并
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
	//快速排序
	public void sort_Qucik( int low, int high)
	{
		if (low < high)
		{
			int index = partition(low, high);
			sort_Qucik(low, index - 1);
			sort_Qucik(index+1, high);
		}
	}
	//分区
	public int partition(int low, int high)
	{
		int x = this.arr[low];//第一个数字为分区标价点
		int i = low, j = high;
		while (i < j)
		{
			//从右边开始找小于分区数字的
			while (i < j && arr[j] >= x)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];
			}
			//从左边开始找大于分区数字的
			while (i < j && arr[i] < x)
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}
		//最终位置访问x
		arr[i] = x;
		return i;
	}
	//希尔排序
	public void sort_Shell(int len)
	{
		int step, i, j,data,index;
		for (step = len / 2; step > 0; step /= 2)
		{
			for (i = 0; i < step; i++)
			{
				//开始插入排序
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
	//堆排序
	void sort_Heap(int len)
	{
		//从非叶子节点到根节点开始调整，构建大顶堆
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			adjust_Heap(i,len);
		}
		//开始堆排序过程
		for (int i = len-1; i > 0; i--)
		{
			int temp = arr[i];
			arr[i] = arr[0];
			arr[0] = temp;
			//交换数据结束，立马调整堆
			adjust_Heap(0, i);
		}
	}
	//堆的调整
	public void adjust_Heap(int index,int len)
	{
		//从当前节点开始调整，一直向下走到最后一个非叶子节点
		int maxIndex,temp;
		while (index <= len/2-1)
		{
			maxIndex = index;
			//找出左右孩子和自己三个之间的最大值。
			if (2*index+1 <len && arr[maxIndex]< arr[2 * index+1])
			{
				maxIndex = 2 * index + 1;
			}
			if (2 * index + 2 < len && arr[maxIndex]< arr[2 * index + 2])
			{
				maxIndex = 2 * index + 2;
			}
			//如果找到的最大值不是自己，交换数据,继续向下调整堆.
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
	//数组输出
	public void print(int len)
	{
		for (int i = 0; i < len; i++)
		{
			System.out.print(this.arr[i]+" ");
		}
		System.out.println();
	}
}
