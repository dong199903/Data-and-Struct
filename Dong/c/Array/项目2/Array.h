/*************************************************************************
> File Name: Array.h
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-07-27
>
> 1��֧��������Զ����ݣ�����ϵ����2
> 2��֧����ɾ�Ĳ�Ȼ�������
************************************************************************/
#pragma once
#include <stdio.h>
#include<stdlib.h>
struct Array
{
	int length;
	int index;
	int *data;
};
void Array_Init(struct Array* arr);//��ʼ������
void Array_Append(struct Array* arr, int data);//����β��
void Array_Insert(struct Array* arr,int index,int data);//����ָ��λ��
void Array_Delete(struct Array* arr,int index);//ɾ��ָ��λ�õ�Ԫ��
void Array_Show(struct Array* arr);//��������
#define Array_size(array) (array->index)
#define Array_length(array) (array->length)
#define Array_is_full(array) (array->index==array->length)


