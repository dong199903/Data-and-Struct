/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）支持简单的增删改查
 > 2）支持模板泛型编程
 > 3）支持添加第三方类成员(Tip:有指针的需要实现深拷贝构造)
 ************************************************************************/

#include"List.cpp"
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
	out << " name: " << p.name << "\tage: " << p.age << endl;
	return out;
}
void main()
{
	List<int> list1;
	list1.List_Append(1);
	list1.List_Append(2);
	list1.List_Append(3);
	list1.List_Append(4);
	list1.List_Append(5);
	list1.List_Front(22);
	list1.List_Front(11);
	list1.List_Print();
	List<char> list2;
	list2.List_Append('A');
	list2.List_Append('B');
	list2.List_Append('C');
	list2.List_Append('D');
	list2.List_Append('E');
	list2.List_Print();
	List<People> list3;
	list3.List_Append(People(19, "dzp"));
	list3.List_Append(People(19, "lyk"));
	list3.List_Append(People(20, "whh"));
	list3.List_Append(People(21, "ls"));
	list3.List_Append(People(18, "lz"));
	list3.List_Print();
	system("pause");
}