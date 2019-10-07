package CDouble_List;

public class CDouble_List<T> {
	private Node<T> head;
	private int size;
	//�޲ι���
	public CDouble_List()
	{
		this.size = 0;
		this.head = new Node<T>();
		this.head.next = head;
		this.head.pre = head;
	}
	//β�巨
	public void CDouble_List_Append(T data)
	{
		Node<T> p,temp;
		p = this.head.pre;
		temp = new Node<T>();
		temp.data = data;
		temp.next = this.head;
		temp.pre = p;
		p.next = temp;
		this.head.pre = temp;
		this.size++;
	}
	//ͷ�巨
	public void CDouble_List_Front(T data)
	{
		Node<T> p;
		p = new Node<T>();
		p.data = data;
		p.next = this.head.next;
		p.pre = this.head;
		this.head.next.pre = p;
		this.head.next = p;
		this.size++;
	}
	//���λ�ò���
	public void CDouble_List_Insert(int index,T data)
	{
		if (index <= 0 || index > (this.size + 1))
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
			temp = new Node<T>();
			temp.data = data;
			temp.next = p.next;
			temp.pre = p;
			p.next.pre = temp;
			p.next = temp;
			this.size++;
		}
	}
	//���λ��ɾ��
	public void CDouble_List_Del(int index)
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
			p.next = temp.next;
			temp.next.pre = p;
			temp = null;
			this.size--;
		}
	}
	//˳�����
	public void CDouble_List_Print()
	{
		Node<T> p;
		p = this.head.next;
		while (p != this.head)
		{
			System.out.print(p.data+" ");
			p = p.next;
		}
		System.out.println();
	}
	//�������
	public void CDouble_List_Print_Reverse()
	{
		Node<T> p;
		p = this.head.pre;
		while (p != this.head)
		{
			System.out.print(p.data+" ");
			p = p.pre;
		}
		System.out.println();
	}
}
