/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）循环单链表
 > 2）支持模板泛型编程
 > 3）支持增删该查基本操作
 ************************************************************************/

#include "CirList.cpp"
class Man {
public:
	int age;
	Man()
	{

	}
	Man(int a)
	{
		this->age = a;
	}
	friend ostream& operator<<(ostream& out, Man& m);
};
ostream& operator<<(ostream& out, Man& m)
{
	out << m.age << endl;
	return out;
}
void main()
{
	CirList<int> clist1;
	clist1.CList_Append(1);
	clist1.CList_Append(2);
	clist1.CList_Append(3);
	clist1.CList_Append(4);
	clist1.CList_Append(5);
	clist1.CList_Print();
	clist1.CList_Front(22);
	clist1.CList_Front(11);
	clist1.CList_Insrt(3, 33);
	clist1.CList_Print();
	CirList<Man> clist2;
	clist2.CList_Append(Man(19));
	clist2.CList_Append(Man(19));
	clist2.CList_Append(Man(19));
	clist2.CList_Append(Man(19));
	clist2.CList_Append(Man(19));
	clist2.CList_Print();
	system("pause");
}