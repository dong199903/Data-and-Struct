package tree_Binary_Search;

public class Tree {
	public Node root;
	public Tree()
	{
		root = null;
	}
	Node Insert_Tree(Node node,int data)
	{
		if(node==null)
		{
			node = new Node(data);
			node.count++;
			return node;
		}else {
			if(data<node.data)
			{
				node.left = Insert_Tree(node.left,data);
			}else if(data>node.data)
			{
				node.right = Insert_Tree(node.right,data);
			}else {
				node.count++;
			}
			return node;
		}
	}
	boolean Find_Tree(int data)
	{
		Node temp;
		temp = this.root;
		while (temp != null)
		{
			if (data < temp.data)
			{
				temp = temp.left;
			}
			else if (data>temp.data) {
				temp = temp.right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	void mid_Order(Node temp)
	{
		if (temp == null)
		{
			return;
		}
		else
		{
			mid_Order(temp.left);
			for (int i = 0; i < temp.count; i++)
			{
				System.out.print(temp.data+" ");
			}
			mid_Order(temp.right);
		}
	}
	
	
	/*--------------------难点来了--------------------*/
	/*
	删除操作分三种情况

	第一类：该元素无左右孩子，直接删除
	第二类：该元素有左孩子或者右孩子(有一个孩子),直接将该孩子节点与其父节点连接
	第三类：该元素左右孩子都在
	3.1：先向左走一步，一直向右走，直到走到一个叶子节点，将该叶子节点的赋给待删除节点元素。
	3.2：先向右走一步，一直向左走，直到走到一个叶子节点，将该叶子节点的赋给待删除节点元素。
	*/
	Node Del(Node n)
	{
		//左子树空，右不空
		if (n.left == null && n.right!= null)
		{
			Node p;
			p = n;
			n = n.right;
			p = null;
			return n;
	
		}
		//右子树空，左不空
		if (n.right == null && n.left != null)
		{
			Node p;
			p = n;
			n = n.left;
			p = null;
			return n;
		
		}
		//左右都空
		if (n.right == null && n.left == null)
		{
			n = null;
			return n;
		
		}
		//左右都不空
		if (n.right != null && n.left != null)
		{
		
			//采用左枝法，先向左走一步，一直向右边走
			Node p, q;
			p = n.left;
			while (p.right != null)
			{
				p = p.right;
			}
			//该节点右子树一定是空，左边不确定
			n.data = p.data;
			if (p.left == null)
			{
				p = null;
			}
			else
			{
				q = p;
				p = q.left;
				q = null;
			}
			return n;
		}
		return n;
	}
	Node Del_Tree(Node n, int data)
	{
		if (n == null)
		{
			return n;
		}
		if (n.data == data)
		{
			n = Del(n);
		}
		else if (n.data > data)
		{
			n.left = Del_Tree(n.left, data);
		}
		else
		{
			n.right = Del_Tree(n.right, data);
		}
		return n;
	}
}
