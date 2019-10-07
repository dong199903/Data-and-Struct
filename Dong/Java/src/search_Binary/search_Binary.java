package search_Binary;

import java.util.Scanner;

public class search_Binary {
	private int [] arr;
	public void print()
	{
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
	public search_Binary()
	{
		int len;
		System.out.print("���������ݵĳ��� ");
		Scanner sc = new Scanner(System.in);
		len = sc.nextInt();
		arr = new int[len];
		for(int i=0;i<len;i++)
		{
			System.out.print("�����"+(i+1)+"������");
			arr[i] = sc.nextInt();
		}
	}
	//���������Ƿ����
	public boolean Search_Binary1(int num)
	{
		int low, high, mid;
		low = 0;
		high = this.arr.length - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] == num)
			{
				return true;
			}
			else if (arr[mid] < num)
			{
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return false;
	}
	//���ֲ��ң��ҵ���һ������Ŀ�������
	public int Search_Binary2(int num)
	{
		int low, high, mid;
		low = 0;
		high = arr.length - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] == num)
			{
				if (mid == 0 || arr[mid - 1] != num)
				{
					return mid;
				}
				else
				{
					high = mid - 1;
				}
			}
			else if (arr[mid] < num)
			{
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return -1;
	}
	//�������һ������Ŀ�������
	public int Search_Binary3(int num)
	{
		int low, high, mid;
		low = 0;
		high = arr.length - 1;
		
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] == num)
			{
				if (mid == arr.length - 1 || arr[mid + 1] != num)
				{
					return mid;
				}
				else {
					low = mid + 1;
				}
			}
			else if (arr[mid] < num)
			{
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return -1;
	}
	//���ҵ�һ�����ڵ���Ŀ�������
	public int Search_Binary4(int num)
	{
		int low, high, mid;
		low = 0;
		high = arr.length - 1;
		
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] >= num)
			{
				if (mid == 0 || arr[mid - 1] < num)
				{
					return mid;
				}
				else {
					high = mid - 1;
				}
			}
			else {
				high = mid - 1;
			}
		}
		return -1;
	}
	/*���ֲ��ң��ҵ����һ��С�ڵ���Ŀ�������*/
	public int Search_Binary5(int num)
	{
		int low, high, mid;
		low = 0;
		high = arr.length - 1;
		
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] <= num)
			{
				if (mid == arr.length-1 || arr[mid +1] > num)
				{
					return mid;
				}
				else {
					low = mid + 1;
				}
			}
			else {
				high = mid - 1;
			}
		}
		return -1;
	}
}
