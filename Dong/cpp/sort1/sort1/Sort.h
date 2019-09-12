/*************************************************************************
> File Name: Soer.h
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-08-10
>
> 1）实现了冒泡排序
> 2）实现了选择排序
> 3）实现了插入排序
>
> 4）发现重大模板类输出输入运算符重载编译问题
> 5）解决办法：
> 6）一：在上面加上一行模板头即可
> 7）二：声明时使用  friend ostream& operator<< <>(ostream& os, const Stack<T>&) 可以解决。
************************************************************************/
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
	void sort_Bubble();
	void sort_Choice();
	void sort_Insert();
	void print();
	template<class T>
	friend istream &operator>>(istream &os,Sort<T> &s);
};
#endif // !SORT_H

