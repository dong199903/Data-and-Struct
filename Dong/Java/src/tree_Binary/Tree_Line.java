package tree_Binary;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Tree_Line {
	private static int MAX = 100;
	private char [] data;
	int count;//节点个数
	public Tree_Line()
	{
		data = new char[MAX];
		this.count = 0;
		for (int i = 0; i < MAX; i++)
		{
			this.data[i] = '0';
		}
	}
	public void Creat_Tree_Line(int index)
	{
		char ch;
		Scanner sc = new Scanner(System.in);
		ch = sc.next().charAt(0);
		if (ch == '#')
		{
			return;
		}
		else
		{
			this.data[index] = ch;
			this.count++;
			//printf("请输入左孩子信息: ");
			Creat_Tree_Line(2 * index);
			//printf("请输入右孩子信息: ");
			Creat_Tree_Line(2 * index + 1);
		}
	}
	public void pre( int index)
	{
		if (this.data[index] == '0')
		{
			return;
		}
		else
		{
			System.out.print(this.data[index]+" ");
			this.pre(2 * index);
			this.pre(2 * index + 1);
		}
	}
	public void mid(int index)
	{
		if (this.data[index] == '0')
		{
			return;
		}
		else
		{
			this.mid(2 * index);
			System.out.print(this.data[index]+" ");
			this.mid(2 * index + 1);
		}
	}
	public void post(int index)
	{
		if (this.data[index] == '0')
		{
			return;
		}
		else
		{
			this.post(2 * index);
			this.post(2 * index + 1);
			System.out.print(this.data[index]+" ");
		}
	}
	public void level()
	{
		Queue<Integer> q =  new LinkedList<Integer>();
		int temp;
		if (this.data[1] != '0')
		{
			q.offer(1);
		}
		while (!q.isEmpty())
		{
			temp = q.poll();
			System.out.print(this.data[temp]+" ");
			if (this.data[temp * 2] != '0')
			{
				q.offer(temp*2);
			}
			if (this.data[temp * 2 + 1] != '0')
			{
				q.offer(temp*2+1);
			}
		}
	}
	public int getHigh_Line(int index)
	{
		if (this.data[index] == '0')
		{
			return 0;
		}
		else
		{
			return getHigh_Line(2 * index) > getHigh_Line(2 * index + 1) ? getHigh_Line( 2 * index) + 1 : getHigh_Line( 2 * index + 1)+1;
		}
	}
	public int getCount_Line(int index)
	{
		if (this.data[index] == '0')
		{
			return 0;
		}
		else
		{
			return getCount_Line(2 * index) + getCount_Line( 2 * index + 1) + 1;
		}
	}
}
