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
	//无参构造
	public Queue_upgrade()
	{
		this.size = 1;
		this.front = this.rear = 0;
		this.data = (T[])new Object[this.size];
	}
	//有参构造
	public Queue_upgrade(int size)
	{
		this.size = size;
		this.front = this.rear = 0;
		this.data = (T[])new Object[this.size];
	}
	//入队列
	public void inQueue(T data) 
	{
		if (this.rear == this.size)
		{
			//队列空间全利用--自动扩容
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
			//队列空间出现假溢出，数据搬迁至前面
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
	//出队列
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
	//队列打印
	public void Queue_Print()
	{
		for (int i = this.front; i < this.rear; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
