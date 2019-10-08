/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-10-08
 >
 > 1）匹配算法BF
 > 2）匹配算法RK
 > 3）匹配算法Sunday
 ************************************************************************/
#include "match_String.h"
#include <stdio.h>
void main()
{
	printf_s("%d\n", BF("abcd","cd"));
	printf_s("%d\n", RK("abcd", "cd"));
	printf_s("%d\n", Sunday("abcd", "cd"));
	system("pause");
}