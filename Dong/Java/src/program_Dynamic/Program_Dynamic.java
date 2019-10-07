package program_Dynamic;

import java.util.Scanner;

public class Program_Dynamic {
	private static int MAX = 100;
	//最大连续子序列和
	public void maxSum()
	{
		int data[] = { 0,-2,11,-4,13,-5,-2 };//0位置不用
		int len = 7,max=-9999;
		int []dp;
		dp = new int[len];
		dp[0] = 0;
		for (int i = 1; i < len; i++)
		{
			if (dp[i - 1] + data[i] > data[i])
			{
				dp[i] = dp[i - 1] + data[i];
			}
			else
			{
				dp[i] = data[i];
			}
		}

		//直接找出dp数组最大，就是最大结果
		for (int i = 0; i < len; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
			}
		}
		System.out.print("最大连续子序列和是:"+max);
	}
	
	
	//三角形最短路径
	public void minPath()
	{
		int i, j, high,min,index,num;
		int [][]data,dp,pre;
		System.out.print("输入三角形的高度: ");
		Scanner sc = new Scanner(System.in);
		high = sc.nextInt();
		data = new int[high][];
		dp = new int[high][];
		pre = new int[high][];
		//输入三角形(二维数组里)
		for (i = 0; i < high; i++)
		{
			data[i] = new int[high];
			dp[i] = new int[high];
			pre[i] = new int[high];
			for (j = 0; j <= i;j++)
			{
				data[i][j] = sc.nextInt();
			}
		}
		
		//初始化边界问题
		dp[0][0] = data[0][0];
		pre[0][0] = -1;
		for (i = 1; i < high; i++)
		{
			dp[i][i] = dp[i - 1][i - 1] + data[i][i];
			dp[i][0] = dp[i - 1][0] + data[i][0];
			pre[i][i] = i-1;
			pre[i][0] = 0;
		}
		//其它正常情况
		for (i = 1; i < high; i++)
		{
			for (j = 1; j < high; j++)
			{
				if (i != j &&j != 0)
				{
					if (dp[i - 1][j - 1] > dp[i - 1][j])
					{
						dp[i][j] = dp[i - 1][j] + data[i][j];
						pre[i][j] = j;
					}
					else {
						dp[i][j] = dp[i - 1][j-1] + data[i][j];
						pre[i][j] = j-1;
					}
				}
			}
		}
		//找出最短距离
		min = dp[high - 1][0];
		index = 0;
		for (i = 1; i < high; i++)
		{
			if (dp[high-1][i] < min)
			{
				min = dp[high-1][i];
				index = i;
			}
		}
		System.out.print("最短距离是:"+min+"它的路径是: ");
		num = high-1;
		while (num!=0)
		{
			System.out.print(data[num][index]);
			index = pre[num][index];
			num--;	
		}
		System.out.println(data[0][0]);
	}
	
	
	//最长递增子序列
	public void maxLen()
	{
		int len, i,j,max;
		int[]data,dp;
		System.out.print("输入你的数组长度: ");
		Scanner sc = new Scanner(System.in);
		len = sc.nextInt();
		data = new int[len];
		dp = new int[len];
		for (i = 0; i < len; i++)
		{
			data[i] = sc.nextInt();
		}
		for (i = 0; i < len; i++)
		{
			dp[i] = 1;
			for (j = 0; j < i; j++)
			{
				if (data[j] < data[i])
				{
					if (dp[j] + 1 > dp[i])
					{
						dp[i] = dp[j] + 1;
					}
				}
			}
		}
		max = dp[0];
		//找出最大长度
		for (i = 1; i < len; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
			}
		}
		System.out.print(max);
	}
	
	
	//0-1背包
	public void packages()
	{
		int w[] = { 2,2,6,5,4 };
		int v[] = { 6,3,5,4,6 };
		int len = 5, maxWeight = 10,i,j,weight;//dp数组存储结果
		int dp[][];
		dp = new int[MAX][];
		for(i=0;i<MAX;i++)
		{
			dp[i] = new int[MAX];
		}
		weight = maxWeight;//weight存储当前背包剩余容量
		for (i = 0; i < len; i++)
		{
			dp[i][0] = 0;
		}
		for (i = 0; i <= weight; i++)
		{
			if (w[0] <= i)
			{
				dp[0][i] = v[0];
			}
			else
			{
				dp[0][i] = 0;
			}
		}
		
		for (i = 1; i < len; i++)
		{
			for (j = 0; j <= weight; j++)
			{
				//是否可以放下第i个物品
				if (j >= w[i])
				{
					if (dp[i - 1][j] > dp[i - 1][j - w[i]] + v[i])
					{
						dp[i][j] = dp[i - 1][j];
					}
					else
					{
						dp[i][j] = dp[i - 1][j - w[i]] + v[i];
					}
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		for (i = 0; i < len; i++)
		{
			for (j = 0; j <= weight; j++)
			{
				System.out.print(dp[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println("最大价值:"+ dp[4][10]);
		//逆序推导选择的物品
		len--;
		while (len > 0)
		{
			if (dp[len][weight] != dp[len - 1][weight])//选择物品len
			{
				System.out.println("物品"+(len+1)+"被选中");
				weight -= w[len];
			}
			len--;
		}
		//判断物品1是否被选择
		if(weight!=0)
		{
			System.out.println("物品"+(len+1)+"被选中");
		}
	}
	
	
	//完全背包
	public void full_Pack()
	{
		int weight[] = {3, 4, 2};
		int value[] = { 4,5,3 };
		int len = 3, maxWeight = 7,i,j,k,max;
		int [][]dp,count;
		dp  =new int[MAX][];
		count = new int[MAX][];
		for(i=0;i<MAX;i++)
		{
			dp[i] = new int[MAX];
			count[i] = new int[MAX];
		}
		//初始化边界
		for (i = 0; i < len; i++)
		{
			dp[i][0] = 0;
		}
		for (i = 0; i <= maxWeight; i++)
		{
			for (k = 0; k*weight[0] <= i; k++)//背包容量足够，放入物品0越多，价值越大。
			{
				dp[0][i] = k*value[0];
				count[0][i] = k;
			}
		}
		//开始
		for (i = 1; i < len; i++)
		{
			for (j = 1; j <= maxWeight; j++)
			{
				max = dp[i][0];
				dp[i][j] = max;
				count[i][j] = 0;
				for (k = 0; k*weight[i] <= j; k++)
				{
					if (dp[i - 1][j - weight[i] * k] + value[i] * k > max)
					{
						max = dp[i - 1][j - weight[i] * k] + value[i] * k;
						dp[i][j] = max;
						count[i][j] = k;
					}
				}
			}
		}
		System.out.print("最大价值:"+dp[2][7]+"\n");
		//输出选择物品
		len--;
		while (len >= 0)
		{
			System.out.println((len + 1)+" "+count[len][maxWeight]);
			maxWeight -= weight[len] * count[len][maxWeight];
			len--;
		}
	}
}
