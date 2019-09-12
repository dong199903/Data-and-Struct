/*************************************************************************
> File Name: Array.cpp
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-07-27
>
> 1��֧��������Զ����ݣ�����ϵ����2
> 2��֧����ɾ�Ĳ�Ȼ�������
************************************************************************/
#include "Array.h"
void Array_Init(struct Array* arr)//��ʼ������
{
	arr->length = 1;//��󳤶ȳ�ʼ����1
	arr->index = 0;//���鵱ǰ�洢��Ԫ�ظ���
	arr->data = (int*)malloc(sizeof(int) * arr->length);//��̬�����ڴ�ռ�
}
void Array_Append(struct Array* arr,int data)//����β��-���Զ����ݵ�Ч��
{
	//�ж������Ƿ����ˣ������Զ�����
	if (Array_is_full(arr))
	{
		arr->length = arr->index * 2;
		int *p = (int*)malloc(sizeof(int) * arr->length);
		for (int i = 0; i < arr->index; i++)
		{
			p[i] = arr->data[i];
		}
		free(arr->data);//�ͷžɵ��ڴ�(������)
		arr->data = p;//ָ�����µ��ڴ�
		arr->data[arr->index] = data;
		arr->index++;
	}
	else {
		arr->data[arr->index] = data;
		arr->index++;
	}

}
void Array_Insert(struct Array* arr,int index,int data)//����ָ��λ��-���Զ����ݵ�Ч��
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
		free(arr->data);//�ͷžɵ��ڴ�(������)
		arr->data = p;//ָ�����µ��ڴ�
	}
	//�����һ����ʼ����ǰ�ڳ�λ��
	for (int i = arr->index; i >= index; i--)
	{
		arr->data[i] = arr->data[i - 1];
	}
	arr->data[index - 1] = data;
	arr->index++;
}
void Array_Delete(struct Array* arr,int index)//ɾ��ָ��λ�õ�Ԫ��
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

void Array_Show(struct Array* arr)//��������
{
	int i;
	for (i = 0; i < arr->index; i++)
	{
		printf_s("%d ",arr->data[i]);
	}
	printf("\n");
}
