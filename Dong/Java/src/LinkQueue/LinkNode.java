package LinkQueue;

public class LinkNode<T>{
	private Node<T> head;
	private int size;
	
	//无参构造
	public LinkNode()
	{
		this.size = 0;
		this.head = new Node<T>();
		this.head.next = null;
	}
	//入队列
	public void inQueue(T data)
	{
		Node<T> p = this.head;
		while (p.next != null)
		{
			p = p.next;
		}
		Node<T> temp = new Node<T>();
		temp.data = data;
		temp.next = p.next;
		p.next = temp;
		this.size++;
	}
	//出队列
	public T outQueue()
	{
		T data;
		Node<T> p;
		p = this.head.next;
		if (p == null)
		{
			return null;
		}
		else {
			data = p.data;
			this.head.next = p.next;
			p = null;
			return data;
		}
	}
	//输出队列
	public void print_Queue()
	{
		Node<T> p = this.head.next;
		while (p != null)
		{
			System.out.print(p.data+" ");
			p = p.next;
		}
		System.out.println();
	}
}
