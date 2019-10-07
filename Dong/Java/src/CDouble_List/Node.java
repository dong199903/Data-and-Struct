package CDouble_List;

public class Node<T> {
	public T data;
	public Node<T> next;
	public Node<T> pre;
	public Node()
	{
		this.next = this.pre = null;
	}
}
