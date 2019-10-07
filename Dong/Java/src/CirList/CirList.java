package CirList;

public class CirList<T> {
	private Node<T> head;
	private int size;
	//无参构造
	public CirList()
	{
		this.size = 0;
		this.head = new Node();
		this.head.next = this.head;
	}
	//尾插法
	public void CList_Append(T data)
	{
		Node<T> p, temp;
		p = this.head.next;
		while (p.next != this.head)
		{
			p = p.next;
		}
		temp = new Node<T>();
		temp.data = data;
		temp.next = this.head;
		p.next = temp;
		this.size++;
	}
	//头插法
	public void CList_Front(T data)
	{
		Node<T> p;
		p = new Node<T>();
		p.data = data;
		p.next =this.head.next;
		this.head.next = p;
		this.size++;
	}
	//随机位置插入
	public void CList_Insrt(int index, T data)
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
			temp = new Node<T>();
			temp.data = data;
			temp.next = p.next;
			p.next = temp;
			this.size++;
		}
	}
	//随机位置删除
	public void CList_Del(int index)
	{
		if(index <= 0 || index > this.size)
		{
			return;
		}
		else {
			//先找到目标位置的前一个位置p
			Node<T> p, temp;
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
	//输出
	public void CList_Print()
	{

		Node<T> p = this.head.next;
		while (p != this.head)
		{
			System.out.print(p.data+" ");
			p = p.next;
		}
	System.out.println();
	}	
}