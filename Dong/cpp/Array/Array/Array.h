/*************************************************************************
 > File Name: Array.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）具有模板类的数组
 > 2）可以实现自动扩容，扩容系数是2
 > 3）具有基本的增删改查等功能
 ************************************************************************/
#ifndef ARRAY_H
#define ARRAY_H
template<class T>
class Array 
{
public:
	Array();
	~Array();
	void Array_Append(T data);
	void Array_Insert(int index, T data);
	void Array_Delete(int index);
	void Array_Print();
	int getLen();
	bool isEmpty();

private:
	int index;
	int length;
	T* data;
};

#endif 


