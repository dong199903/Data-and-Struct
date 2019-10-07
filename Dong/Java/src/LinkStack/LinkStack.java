package LinkStack;

public class LinkStack<T> {
	private Node<T> head;
	private int size;
	//�޲ι���
	public LinkStack()
	{
		this.head = new Node<T>();
		this.head.next = null;
		this.size = 0;
	}
	//��ջ
	public void push(T data)
	{
		Node<T> temp = new Node<T>();
		temp.data = data;
		temp.next = this.head.next;
		this.head.next = temp;
		this.size++;
	}
	//��ջ
	public T pop()
	{
		if (this.head.next == null)
		{
			return null;
		}
		else {
			Node<T> p;
			T data;
			data = this.head.next.data;
			p = this.head.next;
			this.head.next = p.next;
			p = null;
			this.size--;
			return data;
		}
	}
	//���ջ
	public void printStack()
	{
		Node<T> p;
		p = this.head.next;
		while (p != null)
		{
			System.out.print(p.data+" ");
			p = p.next;
		}
		System.out.println();
	}
}
