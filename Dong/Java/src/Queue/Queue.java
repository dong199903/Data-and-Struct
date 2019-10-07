package Queue;

public class Queue<T> {
	private int front;
	private int rear;
	private int size;
	private T [] data;
	//无参构造
	public Queue()
	{
		this.front = 0;
		this.rear = 0;
		this.size = 1;
		this.data = (T[])new Object[this.size];
	}
	//有参构造
	public Queue(int size)
	{
		this.front = 0;
		this.rear = 0;
		this.size = 1;
		this.data = (T[])new Object[this.size];
	}
	//入队列
	public void inQueue(T data)
	{
		if (this.rear == this.size)
		{
			int len = this.size;
			this.size = 2 * this.size;
			T [] temp = (T[])new Object[this.size];
			for (int i = 0; i < len; i++)
			{
				temp[i] = this.data[i];
			}
			this.data = temp;
			this.data[this.rear++] = data;
		}
		else {
			this.data[this.rear++] = data;
		}
	}
	//出队列
	public T outQueue()
	{
		if (this.front == 0)
		{
			return null;
		}
		else {
			return this.data[this.front++];
		}
	}
	//输出队列
	public void Queue_Print()
	{
		for (int i = this.front; i < this.rear; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
