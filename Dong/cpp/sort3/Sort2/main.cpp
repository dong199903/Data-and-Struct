/*************************************************************************
 > File Name: main.cpp
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-08-11
 >
 > 1）计数排序
 > 2）桶排序
 > 3）基数排序
 > 4）按f9设置断点-->点击本地windows调试器-->点击调式栏的逐语句或逐过程-->查找错误
 ************************************************************************/
#include "Sort.cpp"
void main()
{
	Sort<int> s1(5);
	cin >> s1;//输入数据的个数
	//s1.sort_Count();
	s1.sort_Radix();//-------------------存在错误
	//s1.sort_Bucket();
	//s1.print();
	system("pause");
}