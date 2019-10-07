package Double_List;

public class Node<T> {
	public T data;
	public Node next;
	public Node pre;
	public Node()
	{
		this.pre = this.next = null;
	}
}
