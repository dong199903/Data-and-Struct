/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#ifndef SORT_2
#define SORT_2
 //归并排序
void sort_Merge(int *arr, int low, int high);
void Merge(int *arr, int low, int mid, int high);
//快速排序
void sort_Qucik(int *arr, int low, int high);
int partition(int *arr, int low, int high);
//希尔排序
void sort_Shell(int *arr, int len);
//堆排序
void sort_Heap(int *arr, int len);
void adjust_Heap(int *arr, int index, int len);


void print(int *arr, int len);
#endif // !SORT_2

