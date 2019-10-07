package Double_List;

public class Double_List<T> {
	private Node<T> head;
	private int size;
	//无参构造
	public Double_List()
	{
		this.head = new Node<T>();
		this.size = 0;
	}
	//尾插法
	public void Double_List_Append(T data)
	{

		Node<T> p, q;
		p = this.head;
		while (p.next != null)
		{
			p = p.next;
		}
		q = new Node<T>();
		q.data = data;
		q.next = p.next;
		q.pre = p;
		p.next = q;
		this.size++;
	}
	//头插法
	public void Double_List_Front(T data)
	{
		Node<T> p = this.head;
		Node<T> temp = new Node<T>();
		temp.data = data;
		temp.pre = p;
		temp.next = p.next;
		p.next.pre = temp;
		p.next = temp;
		this.size++;
	}
	//随机位置插入
	public void Double_List_Insert(int index,T data)
	{
		if (index >= 0 || index > (this.size + 1))
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
			temp = new Node<T>();
			temp.data = data;
			temp.next = p.next;
			temp.pre = p;
			p.next.pre = temp;
			p.next = temp;
			this.size++;
		}
	}
	//随机位置删除
	public void Double_List_Del(int index) {
		if (index >= 0 || index > this.size)
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
			temp = p.next;
			p.next = temp.next;
			temp.next.pre = p;
			temp = null;
			this.size--;
		}
	}
	//顺序打印
	public void Double_List_Print()
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
	//逆序打印
	public void Double_List_Print_Reverse()
	{
		Node<T> p;
		p = this.head;
		while (p.next != null)
		{
			p = p.next;
		}
		while (p != this.head)
		{
			System.out.print(p.data+" ");
			p = p.pre;
		}
		System.out.println();
	}
}
