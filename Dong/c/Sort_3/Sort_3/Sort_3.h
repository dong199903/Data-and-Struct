/*************************************************************************
 > File Name: Sort_3.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-02
 >
 > 1）计数排序
 > 2）桶排序
 > 3）基数排序
 ************************************************************************/
#pragma once
#ifndef SORT_3_H
#define SORT_3_H

 //桶排序用的链表结构
struct Node
{
	struct Node *next;
	int data;
};


//基数排序用到的数组结构
struct Array
{
	int *data;
	int len;
};
void sort_Bucket(int *arr, int len);
void sort_Count(int *arr, int len);
void sort_Radix(int *arr, int len);
void arr_Print(int *arr, int len);
#endif // !SORT_3_H

