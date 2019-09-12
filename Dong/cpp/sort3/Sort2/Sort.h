/*************************************************************************
 > File Name: Sort.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-11
 >
 > 1）计数排序
 > 2）桶排序
 > 3）基数排序
 > 4）按f9设置断点-->点击本地windows调试器-->点击调式栏的逐语句或逐过程-->查找错误
 ************************************************************************/
#pragma once
#ifndef SORT_H
#define SORT_H
#include<iostream>
using namespace std;
template<class T>
class Sort
{
public:
	T *arr;
	int len;
	Sort(int len);
	void sort_Count();
	void sort_Bucket();
	void sort_Radix();
	void print();
	template<class T>
	friend istream &operator >> (istream &os, Sort<T> &s);
};


//桶排序用的链表结构
template<class T>
class Node
{
public:
	Node *next;
	T data;
};

//基数排序用到的数组结构
template<class T>
class Array
{
public:
	T *data;
	int len;
};

#endif // !SORT_H
