/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）具有模板类的数组
 > 2）可以实现自动扩容，扩容系数是2
 > 3）具有基本的增删改查等功能
 ************************************************************************/
#include "Array.cpp"
#include<iostream>
using namespace std;
class People
{
public:
	int age;
	char name[20];
	People()
	{
		
	}
	People(int age, char* name)
	{
		this->age = age;
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	friend ostream& operator<<(ostream& out, People &p);
};
ostream& operator<<(ostream& out, People &p)
{
	out << p.age << " " << p.name << endl;
	return out;
}
void main()
{
	Array<int> arr1;
	arr1.Array_Append(1);
	arr1.Array_Append(2);
	arr1.Array_Append(3);
	arr1.Array_Append(4);
	arr1.Array_Append(5);
	arr1.Array_Print();
	arr1.Array_Insert(1, 11);
	arr1.Array_Insert(2, 22);
	arr1.Array_Delete(4);
	arr1.Array_Print();
	Array<People> arr2;
	arr2.Array_Append(People(19,"dzp"));
	arr2.Array_Append(People(19,"ff"));
	arr2.Array_Append(People(19,"gg"));
	arr2.Array_Append(People(19,"ee"));
	arr2.Array_Append(People(19,"rr"));
	arr2.Array_Print();
	system("pause");
}