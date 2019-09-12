/*************************************************************************
 > File Name: Array.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）具有模板类的数组
 > 2）可以实现自动扩容，扩容系数是2
 > 3）具有基本的增删改查等功能
 ************************************************************************/
#include "Array.h"
#include<iostream>
using namespace std;
template<class T>
Array<T>::Array()
{
	this->index = 0;
	this->length = 1;
	this->data = new T[this->length];
}

template<class T>
Array<T>::~Array()
{
	this->index = this->length = 0;
	if (this->data)
	{
		delete[] data;
		data = NULL;
	}
}

template<class T>
void Array<T>::Array_Append(T data)
{
	if (this->index == this->length)
	{
		this->length = 2 * this->index;
		T* newData = new T[this->length];
		for (int i = 0; i < this->index; i++)
		{
			newData[i] = this->data[i];
		}
		delete[] this->data;
		this->data = newData;
		this->data[this->index] = data;
		this->index++;
	}
	else {
		this->data[this->index] = data;
		this->index++;
	}
}

template<class T>
void Array<T>::Array_Insert(int index, T data)
{
	if (index <= 0 || index > this->index + 1)
	{
		return;
	}
	if (this->index == this->length)
	{
		this->length = 2 * this->index;
		T* newData = new T[this->length];
		for (int i = 0; i < this->index; i++)
		{
			newData[i] = this->data[i];
		}
		delete[] this->data;
		this->data = newData;
	}
	for (int i = this->index; i >= index; i--)
	{
		this->data[i] = this->data[i - 1];
	}
	this->data[index - 1] = data;
	this->index++;
}

template<class T>
void Array<T>::Array_Delete(int index)
{
	if (index <= 0 || index >this->index)
	{
		return;
	}
	else {
		for (int i = index - 1; i < this->index - 1; i++)
		{
			this->data[i] = this->data[i + 1];
		}
		this->index--;
	}
}

template<class T>
void Array<T>::Array_Print()
{
	for (int i = 0; i < this->index; i++)
	{
		cout << this->data[i] << " ";
	}
	cout << endl;
}

template<class T>
int Array<T>::getLen()
{
	return this->index;
}

template<class T>
bool Array<T>::isEmpty()
{
	return this->index==0;
}