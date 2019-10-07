package tree_Binary_Search;

public class Node {
	public int data;
	Node left;
	Node right;
	int count;
	Node(int data)
	{
		this.data = data;
		this.left = this.right = null;
		this.count = 0;
	}
}
