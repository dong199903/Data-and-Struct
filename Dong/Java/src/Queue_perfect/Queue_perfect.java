package Queue_perfect;

public class Queue_perfect <T>{
	private int front;
	private int rear;
	private int size;
	private T [] data;
	//无参构造
	public Queue_perfect()
	{
		this.size = 1;
		this.front = this.rear = 0;
		this.data = (T[])new Object[this.size];
	}
	//有参构造
	public Queue_perfect(int size)
	{
		this.size = 1;
		this.front = this.rear = 0;
		this.data = (T[])new Object[this.size];
	}
	//入队列
	public void inQueue(T data)
	{
		//队列满额,自动扩容
		if ((this.rear + 1) % this.size == this.front)
		{
			//队列元素个数
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
		}//队列未满，正常入队
		else {
			this.data[this.rear] = data;
			this.rear = (this.rear + 1) % this.size;
		}
	}
	//出队列
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
	//队列输出
	public void Queue_Print()
	{
		for (int i = this.front; i < this.rear; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
