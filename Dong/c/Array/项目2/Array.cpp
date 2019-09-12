/*************************************************************************
> File Name: Array.cpp
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-07-27
>
> 1）支持数组的自动扩容，扩容系数是2
> 2）支持增删改查等基本操作
************************************************************************/
#include "Array.h"
void Array_Init(struct Array* arr)//初始化数组
{
	arr->length = 1;//最大长度初始化是1
	arr->index = 0;//数组当前存储的元素个数
	arr->data = (int*)malloc(sizeof(int) * arr->length);//动态分配内存空间
}
void Array_Append(struct Array* arr,int data)//插在尾部-有自动扩容的效果
{
	//判断数组是否满了，满了自动扩容
	if (Array_is_full(arr))
	{
		arr->length = arr->index * 2;
		int *p = (int*)malloc(sizeof(int) * arr->length);
		for (int i = 0; i < arr->index; i++)
		{
			p[i] = arr->data[i];
		}
		free(arr->data);//释放旧的内存(堆区的)
		arr->data = p;//指向了新的内存
		arr->data[arr->index] = data;
		arr->index++;
	}
	else {
		arr->data[arr->index] = data;
		arr->index++;
	}

}
void Array_Insert(struct Array* arr,int index,int data)//插在指定位置-有自动扩容的效果
{
	if (index <= 0 || index > arr->index + 1)
	{
		return;
	}
	if (arr->index == arr->length)
	{
		arr->length = arr->index * 2;
		int *p = (int*)malloc(sizeof(int) * arr->length);
		for (int i = 0; i < arr->index; i++)
		{
			p[i] = arr->data[i];
		}
		free(arr->data);//释放旧的内存(堆区的)
		arr->data = p;//指向了新的内存
	}
	//从最后一个开始，向前腾出位置
	for (int i = arr->index; i >= index; i--)
	{
		arr->data[i] = arr->data[i - 1];
	}
	arr->data[index - 1] = data;
	arr->index++;
}
void Array_Delete(struct Array* arr,int index)//删除指定位置的元素
{
	if (index <= 0 || index > arr->index)
	{
		return;
	}
	else {
		for (int i = index-1; i < arr->index - 1; i++)
		{
			arr->data[i] = arr->data[i+1];
		}
		arr->index--;
	}
}

void Array_Show(struct Array* arr)//遍历数组
{
	int i;
	for (i = 0; i < arr->index; i++)
	{
		printf_s("%d ",arr->data[i]);
	}
	printf("\n");
}
