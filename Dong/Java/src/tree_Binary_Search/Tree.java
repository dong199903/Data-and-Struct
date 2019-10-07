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
	
	
	/*--------------------�ѵ�����--------------------*/
	/*
	ɾ���������������

	��һ�ࣺ��Ԫ�������Һ��ӣ�ֱ��ɾ��
	�ڶ��ࣺ��Ԫ�������ӻ����Һ���(��һ������),ֱ�ӽ��ú��ӽڵ����丸�ڵ�����
	�����ࣺ��Ԫ�����Һ��Ӷ���
	3.1����������һ����һֱ�����ߣ�ֱ���ߵ�һ��Ҷ�ӽڵ㣬����Ҷ�ӽڵ�ĸ�����ɾ���ڵ�Ԫ�ء�
	3.2����������һ����һֱ�����ߣ�ֱ���ߵ�һ��Ҷ�ӽڵ㣬����Ҷ�ӽڵ�ĸ�����ɾ���ڵ�Ԫ�ء�
	*/
	Node Del(Node n)
	{
		//�������գ��Ҳ���
		if (n.left == null && n.right!= null)
		{
			Node p;
			p = n;
			n = n.right;
			p = null;
			return n;
	
		}
		//�������գ��󲻿�
		if (n.right == null && n.left != null)
		{
			Node p;
			p = n;
			n = n.left;
			p = null;
			return n;
		
		}
		//���Ҷ���
		if (n.right == null && n.left == null)
		{
			n = null;
			return n;
		
		}
		//���Ҷ�����
		if (n.right != null && n.left != null)
		{
		
			//������֦������������һ����һֱ���ұ���
			Node p, q;
			p = n.left;
			while (p.right != null)
			{
				p = p.right;
			}
			//�ýڵ�������һ���ǿգ���߲�ȷ��
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
