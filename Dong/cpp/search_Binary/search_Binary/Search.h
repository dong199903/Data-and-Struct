/*************************************************************************
> File Name: Search.h
> Author:    DongZePing
> Mail:      1939485575@qq.com
> Time:      2019-08-03
>
> 1）二分查找（找到一个目标数）
> 2）二分查找（找到第一个等于目标的数）
> 3）二分查找（找到最后一个等于目标的数）
> 4）二分查找（找到第一个大于等于目标的数）
> 5）二分查找（找到最后一个小于等于目标的数）
************************************************************************/
#ifndef SEARCH_H
#define SEARCH_H
class Array
{
private:
	int* data;
	int len;
public:
	Array();
	void print();
	int Search_Binary1(int num);
	int Search_Binary2(int num);
	int Search_Binary3(int num);
	int Search_Binary4(int num);
	int Search_Binary5(int num);
};
#endif // !SEARCH_H
