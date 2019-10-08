/*************************************************************************
 > File Name: match_String.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-10-08
 >
 > 1）匹配算法BF
 > 2）匹配算法RK
 > 3）匹配算法Sunday
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include "match_String.h"
int BF(char *str1, char* str2)
{
	int i, j, index, begin, l2,len1,len2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 < len2)
	{
		return -1;
	}
	//开始BF算法
	for (i = 0; i < len1; i++)
	{
		begin = i;//主串起点位置
		j = 0;//模式串起点位置
		while (str1[begin] == str2[j])
		{
			begin++;
			j++;
			if (j == len2)
			{
				break;
			}
		}
		if (j == len2)
		{
			return i;
		}
		else
		{
			begin++;
		}
	}
	return -1;
}
int RK(char* str1, char* str2)
{
	//准备一个素数和一个进制数(进制数按照你的字符串范围进行)
	int q = 144451, d = 26,len1,len2;//假设我的字符串全是a-z组成,范围是26，进制用26进制。
	int main_Str = str1[0] - 'a';//主串第一个字符下标a就是0,b就是2
	int pat_Str = str2[0] - 'a';//模式串第一个字符下标
	int h = 1, begin, j, i;//26的多少幂次方
	len1 = strlen(str1);
	len2 = strlen(str2);
	for (i = 1; i < len2; i++)
	{
		main_Str = (main_Str * 26 + str1[i] - 'a') % q;
		pat_Str = (pat_Str * 26 + str2[i] - 'a') % q;
		h = h*d;
	}
	//开始逐个串的比较
	for (i = 0; i < len1 - len2 + 1; i++)
	{
		//先判断code值是否相等
		if (main_Str == pat_Str)
		{
			begin = i;//主串开始位置
			j = 0;
			//继续逐个字符的判断
			while (str1[begin] == str2[j])
			{
				begin++;
				j++;
				if (j == len2)
				{
					return i;//匹配ok
				}
			}
		}
		//code不等或者匹配失败，就更新main_Str的值是下一个
		//code更新办法是减去最高位的进制，剩余的数字*26 +最新进来的数字
		main_Str = ((main_Str - h*(str1[i] - 'a')) * d + str1[i + len2] - 'a') % q;
	}
	return -1;
}
int Sunday(char* str1, char* str2)
{
	int i, j, temp, index[100] = { 0 },len1,len2;
	char ch;
	//记录模式串每个字符最后出现的位置(相对于模式串)
	len1 = strlen(str1);
	len2 = strlen(str2);
	for (i = 0; i < len2; i++)
	{
		j = i;
		index[i] = j;
		while (j != len2)
		{
			if (str2[j] == str2[i])
			{
				index[i] = j;
			}
			j++;
		}
	}
	/*
	1.每次先在主串里和模式串逐个字符匹配
	2.当遇到不匹配时，立马去主串对应下一个起点处找一个字符位置是index
	3.此时将该字符在模式串里面从头到尾对应的找
	4.如果没找到，就将主串的游标直接移动到index+1,模式串回归到0
	5.如果找到了,先确定模式串找到的位置x,然后查看此元素在模式串最后出现位置y，让主串的游标直接加上模式串长度-最后位置
	*/



	for (i = 0; i < len1; )
	{
		temp = i;//temp主串游标
		j = 0;//j模式串游标
		while (str1[temp] == str2[j])
		{
			temp++;
			j++;
			if (j == len2)
			{
				return i;
			}
		}
		//此时主串下标temp,模式串下标j不匹配了,来到主串下一个起点ch
		ch = str1[i + len2];
		//在模式串，从头找，是否存在与ch相等的值
		j = 0;
		while (str2[j] != ch)
		{
			j++;
			if (j == len2)
			{
				break;
			}
		}
		//判断是否找到了这个值ch
		if (j == len2)//没有找到
		{
			i += len2 + 1;
		}
		else//找到了
		{
			i += len2 - index[j];
		}
	}
	return -1;
}