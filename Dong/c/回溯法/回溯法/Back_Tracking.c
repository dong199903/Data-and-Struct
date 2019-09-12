/*************************************************************************
 > File Name: array_queue.c
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1��
 > 2��
 > 3��
 ************************************************************************/
#include "Back_Tracking.h"
#include <stdio.h>

/*
�ݼ�����
arr1����������
arr2���鱣����
len�����Ӽ����߶ȣ�Ҳ������arr1����
index����ǰ���ݵĲ���
*/
void Get_Power_Set(int *arr1, int *arr2, int len, int index)
{
	//���ݵ�Ҷ��ʱ��ֱ�Ӵ�ӡ�ݼ�
	if (index >= len)
	{
		printf("( ");
		for (int i = 0; i < len; i++)
		{
			if (arr2[i] != 0)
			{
				printf("%d ", arr2[i]);
			}
		}
		printf(")\n");
	}
	else
	{
		//ѡ���������
		arr2[index] = arr1[index];
		Get_Power_Set(arr1, arr2, len, index + 1);
		//��ѡ���������
		arr2[index] = 0;
		Get_Power_Set(arr1, arr2, len, index + 1);
	}
}



//�����㷨
void play_Chess()
{
	int temp[10];//����ǰ�±��Ӧ�����Ƿ�ʹ��
	for (int i = 0; i < 10; i++)
	{
		temp[i] = 0;
	}
	for (int a = 1; a < 10; a++)//----------���ӱ�
	{
		temp[a] = 1;
		for (int b = 0; b < 10; b++)//----------������
		{
			if (temp[b] != 1)
			{
				temp[b] = 1;
				for (int c = 0; c < 10; c++)//----------������
				{
					if (temp[c] != 1)
					{
						temp[c] = 1;
						for (int d = 0; d < 10; d++)//----------������
						{
							if (temp[d] != 1)
							{
								temp[d] = 1;
								for (int e = 0; e < 10; e++)//----------���ӳ�
								{
									if (temp[e] != 1)
									{
										temp[e] = 1;
										int x1, x2, x3;
										x1 = 1000 * a + 100 * b + 10 * c + d;
										x2 = 100 * a + 100 * b + 10 * e + d;
										x3 = 10000 * e + 1000 * d + 100 * c + 10 * a + b;
										if (x1 + x2 == x3)
										{
											printf("��:%d  ��:%d  ��:%d  ��:%d  ��:%d\n", a, b, c, d, e);
										}
										temp[e] = 0;//�ؼ��Ļ�����һ��
									}
								}
								temp[d] = 0;
							}
						}
						temp[c] = 0;
					}
				}
				temp[b] = 0;
			}	
		}
		temp[a] = 0;
	}
}



//0-1��������
/*
resule���鱣��⣬��Ʒ���
w���鱣����Ʒ��Ӧ����
v���鱣����Ʒ��Ӧ��ֵ
sunW���浱ǰ��Ʒ������
sumV���浱ǰ��Ʒ�ܼ�ֵ
index��������չ�ڼ���
len������Ʒ������Ҳ����������
*/
void backpack_01(int *result, int *w, int *v, int sumW, int sumV,int index,int len)
{
	printf("%d %d %d\n", weight, sumWeight, maxValue);
	//�����չ��Ҷ�ӽڵ�
	if (index >= len)
	{
		//���������������������Ž�
		if (sumW == weight && sumV>maxValue)
		{
			maxValue = sumV;
			for (int i = 0; i < len; i++)
			{
				if (result[i] != 0)
				{
					printf("��Ʒ���: %d\n", i + 1);
				}
			}
			printf("��������: %d,����ֵ��: %d\n",weight, maxValue);
		}
	}
	else
	{
		if (sumW + w[index] <= weight)
		{
			sumWeight -= w[index];
			result[index] = index;
			backpack_01(result, w, v, sumW+w[index], sumV+v[index], index + 1, len);
		}
		if (sumWeight + sumW > weight)
		{
			sumWeight -= w[index];
			result[index] = 0;//��ѡ��
			backpack_01(result, w, v, sumW, sumV, index + 1, len);
		}
	}
}