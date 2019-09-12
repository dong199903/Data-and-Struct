/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-31
 >
 > 1）栈的实现
 > 2）支持入栈和出栈等基本操作
 > 3）实现了模板类，添加自己的类时,注意浅拷贝和深拷贝问题
 ************************************************************************/
#include "Stack.cpp"
void main()
{
	Stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.Stack_Print();
	cout << s1.pop() << endl;
	system("pause");
}