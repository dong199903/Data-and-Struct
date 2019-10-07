/*************************************************************************
 > File Name: sort.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-13
 >
 > 1）归并排序
 > 2）快速排序
 > 3）希尔排序
 > 4）堆排序
 ************************************************************************/
#ifndef SORT_H
#define SORT_H
//归并排序
void sort_Merge(int *arr,int low,int high);
void Merge(int *arr1,int low,int mid,int high);
//快速排序
void sort_Qucik(int *arr, int low, int high);
int partition(int *arr, int low, int high);
//希尔排序
void sort_Shell(int *arr, int len);
//堆排序
void sort_Heap(int *arr, int len);
void adjust_Heap(int *arr, int index,int len);


void print(int *arr, int len);
#endif // !SORT_H

