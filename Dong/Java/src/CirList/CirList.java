package CirList;

public class CirList<T> {
	private Node<T> head;
	private int size;
	//�޲ι���
	public CirList()
	{
		this.size = 0;
		this.head = new Node();
		this.head.next = this.head;
	}
	//β�巨
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
	//ͷ�巨
	public void CList_Front(T data)
	{
		Node<T> p;
		p = new Node<T>();
		p.data = data;
		p.next =this.head.next;
		this.head.next = p;
		this.size++;
	}
	//���λ�ò���
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
	//���λ��ɾ��
	public void CList_Del(int index)
	{
		if(index <= 0 || index > this.size)
		{
			return;
		}
		else {
			//���ҵ�Ŀ��λ�õ�ǰһ��λ��p
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
	//���
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