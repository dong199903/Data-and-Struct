package table_Hash;

public class Hash_Table_List {
	private Node [] head;//�߱�����
	private int length;//�߱�ĳ���
	private int len;//��ǰ�ܹ��洢��������
	public Hash_Table_List()
	{
		int i;
		this.len = 0;
		this.length = 10;
		this.head = new Node[10];
		for (i = 0; i < 10; i++)
		{
			this.head[i] = new Node();
			this.head[i].data = i;
		}
	}
	public void Insert(int data)
	{

		//����װ�����ӣ��Զ�����
		Node [] newHead;
		Node p,q;
		int i,value,index;
		if (this.len*1.0 >= this.length * 0.75)
		{
			newHead = new Node[this.length * 2];
			for (i = 0; i < this.length * 2; i++)
			{
				newHead[i].data = i;
				newHead[i].next = null;
			}
			//�������ݣ��������ӳ�䵽�µ�ɢ�б���
			for (i = 0; i < this.length; i++)
			{
				p = this.head[i].next;
				while (p!=null)
				{
					//ԭ����
					value = p.data;
					//ӳ����ַ
					index = p.data % (this.length * 2);
					//���ݵ�ַ���ŵ���ɢ�б�ĺ���
					q = new Node();
					q.data = value;
					q.next = newHead[index].next;
					newHead[index].next = q;
					//ɾ����ɢ�б�߱�ṹ
					this.head[i].next = p.next;
					p = this.head[i].next;
				}
			}
			
			this.head = newHead;
			this.length = this.length * 2;

			//�������ݽ�ȥ
			index = data % this.length;
			q = new Node();
			q.data = data;
			q.next = this.head[index].next;
			this.head[index].next = q;
			this.len++;
		}
		//û�г���װ�����ӣ�����Ҫ����
		else
		{
			index = data % this.length;
			q = new Node();
			q.data = data;
			q.next = this.head[index].next;
			this.head[index].next = q;
			this.len++;
		}
	}
	public int isFind(int data)
	{
		Node p;
		int index;
		index = data %this.length;
		p = this.head[index].next;
		while (p != null && p.data != data)
		{
			p = p.next;
		}
		if (p == null)
		{
			return -1;//û�ҵ�
		}
		//����������±�
		else {
			return index;
		}
	}
}
