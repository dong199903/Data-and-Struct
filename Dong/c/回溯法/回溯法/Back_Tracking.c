/*************************************************************************
 > File Name: Baxk_Tracking.c
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
 > 9��N�ʺ�����-----------���װ�
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

	//��ʼ����
	for (int a = 1; a < 10; a++)//----------������
	{
		temp[a] = 1;
		for (int b = 0; b < 10; b++)//----------������
		{
			if (temp[b] == 0)
			{
				temp[b] = 1;
				for (int c = 0; c < 10; c++)//----------���ӳ�
				{
					if (temp[c] == 0)
					{
						temp[c] = 1;
						int x, y, z;
						x = b * 10 + c;
						y = c * 10 + a;
						z = a * 100 + a * 10 + b;
						if (x + y == z)
						{
							printf("��:%d ��:%d ��%d\n", a, b, c);
						}
					}
					temp[c] = 0;
				}
			}
			temp[b] = 0;
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
	//�����չ��Ҷ�ӽڵ�
	if (index >= len)
	{
		//���������������������Ž�
		if (sumW == weight)
		{
			for (int i = 0; i < len; i++)
			{
				if (result[i] != -1)
				{
					printf("��Ʒ���: %d\n", i + 1);
				}
			}
			printf("��������: %d,����ֵ��: %d\n",sumW, sumV);
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
		if (sumW + sumWeight >= weight)
		{
			result[index] = -1;//��ѡ��
			sumWeight += w[index];
			backpack_01(result, w, v, sumW, sumV, index + 1, len);
		}	
	}
}

//����װ������
/*
result����洢����װ����Ϣ
w���鱣��ÿ����������
sumW�ǵ�ǰ����������
index������չ�ڼ���
len��������ܸ���
maxWeight���ִ���������
*/
void optimal(int *result, int *w, int sumW, int index, int len,int maxWeight)
{
	if (index >= len)
	{
		int count=0;
		for (int i = 0; i < len; i++)
		{
			if (result[i] != 0)
			{
				count++;
				printf("����%d��ѡ\n", i+1);
			}
		}
		printf("�ܸ���%d\n",count);
	}
	else 
	{
		if (sumW + w[index] <= maxWeight)
		{
			result[index] = 1;
			optimal(result, w, sumW + w[index], index+1, len, maxWeight);
		}
		result[index] = 0;
		optimal(result, w, sumW, index + 1, len, maxWeight);
	}
}


void sort_All(int *data,int index, int len)
{
	if (index >= len)
	{
		printf_s("( ");
		for (int i = 0; i < len; i++)
		{
			printf("%d ", data[i]);
		}
		printf_s(")  ");
	}
	else {
		for (int i = index; i < len; i++)
		{
			//��������
			int temp = data[i];
			data[i] = data[index];
			data[index] = temp;
			sort_All(data, index + 1, len);
			//�ָ�����
			temp = data[i];
			data[i] = data[index];
			data[index] = temp;

		}
	}
}


void task_Assign(int *data, int len, int index, int (*task)[4])
{
	if (index >= len)
	{
		int sum=0;
		//�������е�����
		for (int i = 0; i < len; i++)
		{
			sum += task[i][data[i]-1];
		}
		if (sum < minCost)
		{
			minCost = sum;
		}
	}
	else {
		for (int i = index; i < len; i++)
		{
			int temp = data[i];
			data[i] = data[index];
			data[index] = temp;
			task_Assign(data, len, index + 1,task);
			temp = data[i];
			data[i] = data[index];
			data[index] = temp;
		}
	}
}


void plan_Activity(struct task * t, int *data, int index, int len)
{
	if (index >= len)
	{
		int count = 1,last;
		//���л���Ÿ�����ͳ��,��ӡÿ�����˳��
		last = t[data[0]-1].end;//����ʱ��
		for (int i = 1; i < len; i++)
		{
			if (t[data[i]-1].begin >= last)
			{
				count++;
				last = t[data[i]-1].end;
			}
		}
		if (count > maxCount)
		{
			maxCount = count;
		}
	}
	else {
		for (int i = index; i < len; i++)
		{
			int temp = data[index];
			data[index] = data[i];
			data[i] = temp;
			plan_Activity(t, data, index + 1, len);
			temp = data[index];
			data[index] = data[i];
			data[i] = temp;
		}
	}
}


