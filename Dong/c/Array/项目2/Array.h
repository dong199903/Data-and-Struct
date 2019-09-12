/*************************************************************************
> File Name: Array.h
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-07-27
>
> 1）支持数组的自动扩容，扩容系数是2
> 2）支持增删改查等基本操作
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
void Array_Init(struct Array* arr);//初始化数组
void Array_Append(struct Array* arr, int data);//插在尾部
void Array_Insert(struct Array* arr,int index,int data);//插在指定位置
void Array_Delete(struct Array* arr,int index);//删除指定位置的元素
void Array_Show(struct Array* arr);//遍历数组
#define Array_size(array) (array->index)
#define Array_length(array) (array->length)
#define Array_is_full(array) (array->index==array->length)


