package List;

public class List<T> {
	private int size;
	private Node<T> head;
	//构造函数
	public List()
	{
		this.size = 0;
		this.head = new Node();
	}
	//尾插法
	public void List_Append(T data)
	{
		Node<T> temp, p;
		p = this.head;
		while (p.next != null)
		{
			p = p.next;
		}
		temp = new Node();
		temp.data = data;
		temp.next = p.next;
		p.next = temp;
		this.size++;
	}
	//头插法
	public void List_Front(T data)
	{
		Node<T> p;
		p = new Node();
		p.data = data;
		p.next = this.head.next;
		this.head.next = p;
		this.size++;
	}
	//随机位置插入
	public void List_Insrt(int index, T data)
	{
		if (index <= 0 || index > (this.size + 1))
		{
			return;
		}
		else {
			Node<T> p, temp;
			p = this.head;
			for (int i = 1; i < index; i++)
			{
				p = p.next;
			}
			temp = new Node();
			temp.data = data;
			temp.next = p.next;
			p.next = temp;
			this.size++;
		}
	}
	//随机位置删除
	public void List_Del(int index)
	{
		if (index <= 0 || index > this.size)
		{
			return;
		}
		else {
			Node<T> p,temp;
			p = this.head;
			for (int i = 1; i < index; i++)
			{
				p = p.next;
			}
			temp = p.next;
			p.next = p.next.next;
			temp = null;
			this.size--;
		}
	}
	//打印
	public void List_Print()
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
