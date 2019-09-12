/*************************************************************************
> File Name: main.cpp
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
#include "Sort.cpp"
void main()
{
	Sort<int> s1(10);
	cin >> s1;
	s1.sort_Bubble();
	s1.print();
	system("pause");
}