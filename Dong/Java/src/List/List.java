package List;

public class List<T> {
	private int size;
	private Node<T> head;
	//���캯��
	public List()
	{
		this.size = 0;
		this.head = new Node();
	}
	//β�巨
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
	//ͷ�巨
	public void List_Front(T data)
	{
		Node<T> p;
		p = new Node();
		p.data = data;
		p.next = this.head.next;
		this.head.next = p;
		this.size++;
	}
	//���λ�ò���
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
	//���λ��ɾ��
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
	//��ӡ
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
