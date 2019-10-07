package Greedy;

import java.util.Arrays;
import java.util.Scanner;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019��10��3�� ����8:44:11
 >
 > 1����ջ�Ļ���ʵ��
 > 2����ջ�ͳ�ջ�Ȼ�������
 > 3��
 ************************************************************************/
public class Greedy {
	
	/*�����*/
	public void plan_Acivity()
	{
		Plan[] s;
		Plan temp;
		int begin,last,sum=0,count;
		Scanner sc = new Scanner(System.in);
		System.out.print("�����ܸ���: ");
		count = sc.nextInt();
		s = new Plan[count];
		for(int i=0;i<count;i++)
		{
			System.out.print("�����"+(i+1)+"�����ʼ�ͽ���ʱ��");
			begin = sc.nextInt();
			last = sc.nextInt();
			s[i] = new Plan(begin,last);
		}
		Arrays.sort(s);//�������㷨����
		//��ʼ������Ż
		temp = s[0];
		sum++;
		for (int i = 1; i < s.length; i++)
		{
			if (s[i].begin > temp.last)//�жϴλ�Ƿ���԰���
			{
				sum++;
				temp = s[i];
			}
		}
		System.out.println(sum);
	}
	/*0-1����*/
	public void back_Pack()
	{
		double sumW = 100, sumV = 0,maxBi;//�����������100kg
		double weight[] = { 100,30,60,20,50 };
		double value[] = { 100,90,120,80,75 };
		int []temp = { 0,0,0,0,0};
		int index=0;//��ǵ�ǰ��Ʒѡ�����
		double bi[] = { 0,0,0,0,0};
		for (int i = 0; i < 5; i++)
		{
			bi[i] = value[i] * 1.0 / weight[i];
		}
		//��ʼ��ѡ��Ʒ
		for (int i = 0; i < 5; i++)
		{
			maxBi = -9999;
			//��ѡ��ǰδѡ����Ʒ�Լ۱�����
			for (int j = 0; j < 5; j++)
			{
				if (temp[j] == 0 && bi[j] > maxBi)
				{
					maxBi = bi[j];
					index = j;
				}
			}
			//������������
			if (sumW <= 0)
			{
				break;
			}
			//����������
			temp[index] = 1;
			if (sumW >= weight[index])
			{
				sumW -= weight[index];//ȫ������
				sumV += value[index];
			}
			else {
				sumV += bi[index] * sumW;
				sumW = 0;//�������㣬����һ����
			}
		}
		//�������ֵ
		System.out.println(sumV);
	}
	
	
	
	/*����װ��*/
	public void load()
	{
		int weight[] = { 5,2,6,4,3 };
		int temp, maxW = 10;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5 - i - 1; j++)
			{
				if (weight[j] > weight[j + 1])
				{
					temp = weight[j];
					weight[j] = weight[j + 1];
					weight[j + 1] = temp;
				}
			}
		}
		//��ʼ���װ��
		for (int i = 0; i < 5; i++)
		{
			if (maxW - weight[i] > 0)
			{
				System.out.print(weight[i]+" ");
				maxW -= weight[i];
			}
		}
		System.out.println();
	}
}
