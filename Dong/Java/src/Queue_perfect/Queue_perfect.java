package Queue_perfect;

public class Queue_perfect <T>{
	private int front;
	private int rear;
	private int size;
	private T [] data;
	//�޲ι���
	public Queue_perfect()
	{
		this.size = 1;
		this.front = this.rear = 0;
		this.data = (T[])new Object[this.size];
	}
	//�вι���
	public Queue_perfect(int size)
	{
		this.size = 1;
		this.front = this.rear = 0;
		this.data = (T[])new Object[this.size];
	}
	//�����
	public void inQueue(T data)
	{
		//��������,�Զ�����
		if ((this.rear + 1) % this.size == this.front)
		{
			//����Ԫ�ظ���
			int count = 0;
			int len = (this.rear - this.front) % this.size;
			this.size = 2 * this.size;
			T [] p = (T[])new Object[this.size];
			for (int i = this.front; i < this.rear; i++)
			{
				p[count++] = this.data[i];
			}
		
			this.data = p;
			this.front = 0;
			this.rear = count;
			this.data[this.rear] = data;
			this.rear = (this.rear + 1) % this.size;
		}//����δ�����������
		else {
			this.data[this.rear] = data;
			this.rear = (this.rear + 1) % this.size;
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
			T data = this.data[this.front];
			this.front = (this.front + 1) % this.size;
			return data;
		}
	}
	//�������
	public void Queue_Print()
	{
		for (int i = this.front; i < this.rear; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
