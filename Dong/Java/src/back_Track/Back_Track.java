package back_Track;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019年10月3日 下午9:33:11
 >
 > 1）
 > 2）
 > 3）
 ************************************************************************/
public class Back_Track {
	
	/*-------------幂集数据-----------------*/
	private int[]data1;//幂集问题原数组
	private int[]data2;//幂集问题存储结果数组
	
	
	
	/*-------------0-1背包数据-----------------*/
	private int w[] = { 5,3,2,1 };//背包问题物品重量数组
	private int v[] = {4,4,3,1};//背包问题物品价值数组
	private int result[] = { -1 ,-1,-1,-1};//背包问题选择物品数组
	private int weight;//背包最大容量
	private int sumWeight;//背包所有物品重量和
	public int maxValue;//背包当前最大价值
	
	/*-------------最优装载数据---------------*/
	private int results[] = {0,0,0,0,0};
	private int ws[] = {5,2,6,4,3};
	private int maxW = 10;
	public int maxNum = -9999;
	
	/*-------------全排列数据-----------------*/
	private int data3[] = {1,2,3};//全排列问题
	
	
	
	/*-------------任务分配数据-----------------*/
	private int data4[] = {1,2,3,4};//任务分配工作编号
	public int minCost = 999999;//最小成本
	private int task[][] = { {9,2,7,8},{6,4,3,7},{5,8,1,5},{7,6,9,4} };
	
	
	
	/*-------------活动安排数据-----------------*/
	public int maxCount;//活动安排个数
	private int data5[] = { 1,2,3,4 };//活动编号
	private Task t[];//活动区间
	
	
	public Back_Track()
	{
		//初始化幂集问题
		data1 = new int[3];
		data2 = new int[3];
		data1[0] = 1;data1[1] = 2;data1[2] = 3;
		data2[0] = 0;data2[1] = 0;data2[2] = 0;
		//初始化背包问题
		weight = 6;sumWeight=11;maxValue=0;
		//初始化活动安排问题
		t = new Task[4];
		t[0] = new Task(1,3);
		t[1] = new Task(2,5);
		t[2] = new Task(4,8);
		t[3] = new Task(6,10);
	}
	 //求数列的幂级-递归实现
	public void Get_Power_Set(int index)
	{
		//回溯到叶子时，直接打印幂集
		if (index >= data1.length)
		{
			System.out.print("( ");
			for (int i = 0; i <  data1.length; i++)
			{
				if (data2[i] != 0)
				{
					System.out.print(data2[i] + " ");
				}
			}
			System.out.print(")\n");
		}
		else
		{
			//选择这个数字
			data2[index] = data1[index];
			Get_Power_Set(index + 1);
			//不选择这个数字
			data2[index] = 0;
			Get_Power_Set(index + 1);
		}
	}
	//求解马兵炮问题
	public void play_Chess()
	{
		int temp[] = new int[10];//代表当前下标对应数字是否使用
		for (int i = 0; i < 10; i++)
		{
			temp[i] = 0;
		}

		//开始计算
		for (int a = 1; a < 10; a++)//----------棋子炮
		{
			temp[a] = 1;
			for (int b = 0; b < 10; b++)//----------棋子马
			{
				if (temp[b] == 0)
				{
					temp[b] = 1;
					for (int c = 0; c < 10; c++)//----------棋子车
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
								System.out.print("炮: " + a + " 马:" + b + " 车: " + c);
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
	//0-1背包问题
	public void backpack_01(int sumW, int sumV, int index)
	{
		//如果扩展到叶子节点
		if (index >= w.length)
		{
			//如果符合条件，就输出最优解
			if (sumW == weight)
			{
				for (int i = 0; i < w.length; i++)
				{
					//列出详细装载情况
					//if (result[i] != -1)
					//{
						//System.out.print("物品编号: " + (i + 1) + "\n");
					//}
				}
				if(sumV>maxValue)
				{
					maxValue = sumV;
				}
				//System.out.print("总重量是: " + sumW + "最大价值是: " + sumV +"\n");
			}
		}
		else
		{
			if (sumW + w[index] <= weight)
			{
				sumWeight -= w[index];
				result[index] = index;
				backpack_01(sumW + w[index], sumV + v[index], index + 1);
			}
			if (sumW + sumWeight >= weight)
			{
				result[index] = -1;//不选择
				sumWeight += w[index];
				backpack_01(sumW, sumV, index + 1);
			}
		}
	}
	//最优装载问题--尽可能多的货物被装上
	public void optimal(int sumW, int index)
	{
		if (index >= results.length)
		{
			int count = 0;
			for (int i = 0; i < results.length; i++)
			{
				if (results[i] != 0)
				{
					count++;
					//System.out.print("货物" + (i + 1) + "被选择" + "\n");
				}
			}
			//System.out.print("总个数 " + count + "\n");
			if(count>this.maxNum)
			{
				maxNum = count;
			}
		}
		else
		{
			if (sumW + ws[index] <= maxW)
			{
				results[index] = 1;
				optimal(sumW + ws[index], index + 1);
			}
			results[index] = 0;
			optimal(sumW, index + 1);
		}
	}
	//全排列
	public void sort_All(int index)
	{
		if (index >= data3.length)
		{
			System.out.print("( ");;
			for (int i = 0; i < data3.length; i++)
			{
				System.out.print(data3[i] + " ");
			}
			System.out.print(" )\n");
		}
		else {
			for (int i = index; i < data3.length; i++)
			{
				//交换数据
				int temp = data3[i];
				data3[i] = data3[index];
				data3[index] = temp;
				sort_All(index + 1);
				//恢复数据
				temp = data3[i];
				data3[i] = data3[index];
				data3[index] = temp;
			}
		}
	}
	//求解任务分配
	public void task_Assign(int index)
	{
		if (index >= data4.length)
		{
			int sum = 0;
			//处理排列的数据
			for (int i = 0; i < data4.length; i++)
			{
				//System.out.print(task[i][(data4[i] - 1)] + "\n");
				sum += task[i][data4[i]-1];
			}
			if (sum < minCost)
			{
				minCost = sum;
			}
		}
		else {
			for (int i = index; i < data4.length; i++)
			{
				int temp = data4[i];
				data4[i] = data4[index];
				data4[index] = temp;
				task_Assign(index + 1);
				temp = data4[i];
				data4[i] = data4[index];
				data4[index] = temp;
			}
		}
	}
	//活动安排
	public void plan_Activity(int index)
	{
		if (index >= t.length)
		{
			int count = 1, last;
			//进行活动安排个数的统计,打印每个活动的顺序
			last = t[data5[0] - 1].end;//结束时间
			for (int i = 1; i < t.length; i++)
			{
				if (t[data5[i] - 1].begin >= last)
				{
					count++;
					last = t[data5[i] - 1].end;
				}
			}
			if (count > maxCount)
			{
				maxCount = count;
			}
		}
		else {
			for (int i = index; i < t.length; i++)
			{
				int temp = data5[index];
				data5[index] = data5[i];
				data5[i] = temp;
				plan_Activity(index + 1);
				temp = data5[index];
				data5[index] = data5[i];
				data5[i] = temp;
			}
		}
	}
}
