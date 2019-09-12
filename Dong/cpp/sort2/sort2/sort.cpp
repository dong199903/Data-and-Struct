/*************************************************************************
 > File Name: sort.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-13
 >
 > 1）归并排序
 > 2）快速排序
 > 3）希尔排序
 ************************************************************************/
#include "sort.h"
#include <iostream>
using namespace std;
void sort_Merge(int *arr, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		sort_Merge(arr, low, mid);
		sort_Merge(arr, mid+1, high);
		Merge(arr, low, mid, high);
	}
}
void Merge(int *arr, int low, int mid, int high)
{
	int *left, *right,i,j,n,m,k;
	n = mid - low + 1, m = high - mid;
	left = new int[n];
	right = new int[m];
	for (i = 0; i <= n; i++) 
	{
		left[i] = arr[low + i];
	}
	for (i = 0; i < m; i++)
	{
		right[i] = arr[mid + 1 + i];
	}
	i = 0,j = 0,k=low;
	while (i < n && j < m)
	{
		if (left[i] < right[j])
		{
			arr[k++] = left[i++];
		}
		else {
			arr[k++] = right[j++];
		}
	}
	while (i < n)
	{
		arr[k++] = left[i++];
	}
	while (j < m)
	{
		arr[k++] = right[j++];
	}
}


//快速排序核心
void sort_Qucik(int *arr, int low, int high)
{
	if (low < high)
	{
		int index = partition(arr, low, high);
		sort_Qucik(arr, low, index - 1);
		sort_Qucik(arr, index+1, high);
	}
}
//分区
int partition(int *arr, int low, int high)
{
	int x = arr[low];//第一个数字为分区标价点
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
void sort_Shell(int *arr, int len)
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


/*
堆排序
1.将数据按照完全二叉树存储在数组里。
2.假设建立大顶堆，从最后一个非叶子节点到根节点，向下层调整堆
3.从建好大顶堆中，逐个将最后一个元素与头交换数据，然后调整堆(向下调整)。直到取完数据(每次取出的都是剩余的最大值)
*/
void sort_Heap(int *arr, int len)
{
	//从非叶子节点到根节点开始调整，构建大顶堆
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		adjust_Heap(arr, i,len);
	}
	print(arr, len);
	//开始堆排序过程
	for (int i = len-1; i > 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		//交换数据结束，立马调整堆
		adjust_Heap(arr, 0, i);
	}
}
void adjust_Heap(int *arr, int index,int len)
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

void print(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}