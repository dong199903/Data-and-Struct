/*************************************************************************
 > File Name: main.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-09-29
 >
 > 1�������˻����㷨�ļ��󾭵���Ŀ��ͨ���Ӽ������������Ļ��ֽ��л���
 > 2���ݼ�����
 > 3�����������
 > 4��0-1��������
 > 5������װ������
 > 6��ȫ��������
 > 7�������������
 > 8�����������
 > 9��N�ʺ�����
 ************************************************************************/
#include "Back_Tracking.h"
#include <stdio.h>
void main()
{
	//����ݼ�
	/*
	int arr1[] = { 1,2,3 };
	int len;
	len = sizeof(arr1) / sizeof(int);
	int *arr2 = (int*)malloc(sizeof(int)*len);
	memset(arr2, 0, len);//��ʼ������ĺ���
	Get_Power_Set(arr1, arr2, len, 0);
	*/

	//��������
	/*
	play_Chess();
	*/


	//���0-1����
	/*
	int w[4] = { 5,3,2,1 };
	int v[4] = {4,4,3,1};
	int result[4] = { -1 ,-1,-1,-1};
	weight = 6;
	maxValue = 0;
	sumWeight = 11;
	backpack_01(result, w, v, 0, 0, 0, 4);
	*/

	//�������װ��
	/*
	int result[5] = {0};
	int w[5] = { 5,2,6,4,3 };
	optimal(result, w, 0, 0, 5, 10);
	*/

	//���ȫ����
	/*
	int data[3] = { 1,2,3 };
	sort_All(data, 0, 3);
	*/


	//����������
	/*
	int data[4]= { 1,2,3,4 };
	minCost = 999999;
	int task[4][4] = { 9,2,7,8,6,4,3,7,5,8,1,5,7,6,9,4};
	task_Assign(data, 4, 0,task);
	printf_s("��ͳɱ���%d", minCost);
	*/

	//�������
	/*
	int data[4] = { 1,2,3,4 };
	struct task t[4] = { {1,3},{2,5},{4,8},{6,10} };
	maxCount = -9999;
	plan_Activity(t, data, 0, 4);
	printf_s("�������%d", maxCount);
	*/

	//N�ʺ�����

	system("pause");
}