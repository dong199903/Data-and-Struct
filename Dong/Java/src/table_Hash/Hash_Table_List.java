package table_Hash;

public class Hash_Table_List {
	private Node [] head;//边表数组
	private int length;//边表的长度
	private int len;//当前总共存储的数据量
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

		//超过装载因子，自动扩容
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
			//将旧数据，逐个重新映射到新的散列表上
			for (i = 0; i < this.length; i++)
			{
				p = this.head[i].next;
				while (p!=null)
				{
					//原数据
					value = p.data;
					//映射后地址
					index = p.data % (this.length * 2);
					//根据地址，放到新散列表的后面
					q = new Node();
					q.data = value;
					q.next = newHead[index].next;
					newHead[index].next = q;
					//删除旧散列表边表结构
					this.head[i].next = p.next;
					p = this.head[i].next;
				}
			}
			
			this.head = newHead;
			this.length = this.length * 2;

			//插入数据进去
			index = data % this.length;
			q = new Node();
			q.data = data;
			q.next = this.head[index].next;
			this.head[index].next = q;
			this.len++;
		}
		//没有超过装载因子，不需要扩容
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
			return -1;//没找到
		}
		//返回链表的下标
		else {
			return index;
		}
	}
}
