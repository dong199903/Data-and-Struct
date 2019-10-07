package Greedy;

import java.util.Arrays;
import java.util.Scanner;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019年10月3日 下午8:44:11
 >
 > 1）链栈的基本实现
 > 2）入栈和出栈等基本操作
 > 3）
 ************************************************************************/
public class Greedy {
	
	/*活动安排*/
	public void plan_Acivity()
	{
		Plan[] s;
		Plan temp;
		int begin,last,sum=0,count;
		Scanner sc = new Scanner(System.in);
		System.out.print("输入活动总个数: ");
		count = sc.nextInt();
		s = new Plan[count];
		for(int i=0;i<count;i++)
		{
			System.out.print("输入第"+(i+1)+"个活动开始和结束时间");
			begin = sc.nextInt();
			last = sc.nextInt();
			s[i] = new Plan(begin,last);
		}
		Arrays.sort(s);//用内置算法排序
		//开始逐个安排活动
		temp = s[0];
		sum++;
		for (int i = 1; i < s.length; i++)
		{
			if (s[i].begin > temp.last)//判断次活动是否可以安排
			{
				sum++;
				temp = s[i];
			}
		}
		System.out.println(sum);
	}
	/*0-1背包*/
	public void back_Pack()
	{
		double sumW = 100, sumV = 0,maxBi;//背包最大容量100kg
		double weight[] = { 100,30,60,20,50 };
		double value[] = { 100,90,120,80,75 };
		int []temp = { 0,0,0,0,0};
		int index=0;//标记当前物品选择与否
		double bi[] = { 0,0,0,0,0};
		for (int i = 0; i < 5; i++)
		{
			bi[i] = value[i] * 1.0 / weight[i];
		}
		//开始挑选物品
		for (int i = 0; i < 5; i++)
		{
			maxBi = -9999;
			//挑选当前未选的物品性价比最大的
			for (int j = 0; j < 5; j++)
			{
				if (temp[j] == 0 && bi[j] > maxBi)
				{
					maxBi = bi[j];
					index = j;
				}
			}
			//背包容量不足
			if (sumW <= 0)
			{
				break;
			}
			//背包容量足
			temp[index] = 1;
			if (sumW >= weight[index])
			{
				sumW -= weight[index];//全部放入
				sumV += value[index];
			}
			else {
				sumV += bi[index] * sumW;
				sumW = 0;//容量不足，放入一部分
			}
		}
		//输出最大价值
		System.out.println(sumV);
	}
	
	
	
	/*最优装载*/
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
		//开始逐个装载
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
