package tree_Binary;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Tree {
	public Node root;
	public Tree()
	{
		root = null;
	}
	public Node creat_Tree(Node n)
	{
		n = null;
		char ch;
		Scanner sc = new Scanner(System.in);
		ch = sc.next().charAt(0);
		if(ch!='#')
		{
			n = new Node(ch);
			n.left = creat_Tree(n.left);
			n.right = creat_Tree(n.right);
		}
		return n;
	}
	public void pre_Order(Node r)
	{
		if (r == null)
		{
			return;
		}
		System.out.print(r.data+" ");
		pre_Order(r.left);
		pre_Order(r.right);
	}
	public void mid_Order(Node r)
	{
		if (r == null)
		{
			return;
		}
		
		mid_Order(r.left);
		System.out.print(r.data+" ");
		mid_Order(r.right);
	}
	public void post_Order(Node r)
	{
		if (r == null)
		{
			return;
		}
		post_Order(r.left);
		post_Order(r.right);
		System.out.print(r.data+" ");
	}
	public void level_Order()
	{
		@SuppressWarnings("unchecked")
		Queue<Node> q =  new LinkedList<Node>();
		Node temp;
		if (this.root != null)
		{
			q.offer(this.root);//根节点入队
		}
		while (!q.isEmpty())
		{
			temp = q.poll();
			System.out.print(temp.data+" ");
			if (temp.left != null)
			{
				q.offer(temp.left);
			}
			if (temp.right != null)
			{
				q.offer(temp.right);
			}
		}
	}
	//返回二叉树的高度
	public int getHigh(Node root)
	{
		if (root == null)
		{
			return 0;
		}
		return getHigh(root.left)>getHigh(root.right)? getHigh(root.left)+1: getHigh(root.right)+1;
	}
	//返回二叉树的节点数量
	public int getCount(Node root)
	{
		if (root == null)
		{
			return 0;
		}
		else
		{
			return getCount(root.left) +getCount(root.right) + 1;
		}
	}
	
}	
