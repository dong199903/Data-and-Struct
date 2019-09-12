/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-30
 >
 > 1）循环双链表-支持模板类操作
 > 2）支持增删改查等基本操作
 > 3）支持逆序输出
 ************************************************************************/
#include "CDoulbe_List.cpp"
class Man
{
public:
	int age;
	Man()
	{

	}
	Man(int a) :age(a)
	{

	}
	Man(const Man& m)
	{
		this->age = m.age;
	}
};
void main()
{
	CDouble_List<int> list;
	list.CDouble_List_Append(1);
	list.CDouble_List_Append(2);
	list.CDouble_List_Append(3);
	list.CDouble_List_Append(4);
	list.CDouble_List_Append(5);
	list.CDouble_List_Front(22);
	list.CDouble_List_Front(11);
	list.CDouble_List_Insert(5, 55);
	list.CDouble_List_Del(4);
	list.CDouble_List_Print();
	list.CDouble_List_Print_Reverse();

	CDouble_List<Man> list2;
	Man m1(10);
	Man m2(10);
	Man m3(10);
	Man m4(10);
	Man m5(10);

	list2.CDouble_List_Append(m1);
	list2.CDouble_List_Append(m2);
	list2.CDouble_List_Append(m3);
	list2.CDouble_List_Append(m4);
	
	system("pause");
}