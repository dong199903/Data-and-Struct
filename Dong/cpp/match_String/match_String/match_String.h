/*************************************************************************
 > File Name: match_String.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-10-08
 >
 > 1）BF匹配
 > 2）RK匹配
 > 3）Sunday匹配
 ************************************************************************/
#ifndef MATCH_STRING_H
#define MATCH_STRING_H
#include<iostream>
using namespace std;
class String
{
private:
	string s1;//主串
	string s2;//模式串
public:
	String(string s1,string s2);
	int BF();
	int Sunday();
	int RK();
};
#endif // !MATCH_STRING_H

