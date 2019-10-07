package Queue_upgrade;
/*
 * 
 * 
*/
public class Queue_upgrade<T> {
	private int front;
	private int rear;
	private int size;
	private T [] data;
	//�޲ι���
	public Queue_upgrade()
	{
		this.size = 1;
		this.front = this.rear = 0;
		this.data = (T[])new Object[this.size];
	}
	//�вι���
	public Queue_upgrade(int size)
	{
		this.size = size;
		this.front = this.rear = 0;
		this.data = (T[])new Object[this.size];
	}
	//�����
	public void inQueue(T data) 
	{
		if (this.rear == this.size)
		{
			//���пռ�ȫ����--�Զ�����
			if (this.front == 0)
			{
				this.size = 2 * this.size;
				int temp = this.size;
				T [] p = (T[])new Object[this.size * 2];
				for (int i = 0; i < temp; i++)
				{
					p[i] = this.data[i];
				}
				this.data = p;
				this.data[this.rear++] = data;
			}
			//���пռ���ּ���������ݰ�Ǩ��ǰ��
			else {
				int count = 0;
				for (int i = 0; i < (this.rear - this.front); i++)
				{
					this.data[i] = this.data[this.front++];
					count++;
				}
				this.front = 0;
				this.rear = count;
			}
		}
		else 
		{
			this.data[this.rear++] = data;
		}
	}
	//������
	public T outQueue()
	{
		if (this.front == this.rear)
		{
			return null;
		}
		else {
			return this.data[this.front++];
		}
	}
	//���д�ӡ
	public void Queue_Print()
	{
		for (int i = this.front; i < this.rear; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
