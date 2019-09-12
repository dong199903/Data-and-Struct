/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
#ifndef BACK_TRACKING_H
#define BACK_TRACKING_H
//求数列的幂级-递归实现
void Get_Power_Set(int *arr1, int *arr2, int len, int index);
//求解马兵炮问题
void play_Chess();
#endif // !BACK_TRACKING_H
//0-1背包问题
void backpack_01(int *result, int *w, int *v, int sumW,int sumV,int index,int len);
int weight;//背包最大容量
int sumWeight;//所有物品重量和
int maxValue;//最大价值
