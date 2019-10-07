package Stack;

public class Stack<T> {
	private int top;//栈顶指针
	private T [] data;
	private int size;//最大存储空间(满了自动扩容)
	
	//无参构造
	public Stack()
	{
		this.top = -1;
		this.size = 1;
		this.data = (T[])new Object[this.size];
	}
	//有参构造
	public Stack(int size)
	{
		this.top = -1;
		this.size = size;
		this.data = (T[])new Object[this.size];
	}
	//入栈
	void push(T data)
	{
		if (this.top + 1 == this.size)
		{
			int len = this.size;
			this.size = 2 * this.size;
			T [] temp = (T[])new Object[this.size];
			for (int i = 0; i < len; i++)
			{
				temp[i] = this.data[i];
			}
			
			this.data = temp;
			this.data[++this.top] = data;
		}
		else {
			this.data[++this.top] = data;
		}
	}
	
	//出栈
	T pop()
	{
		if (this.top == -1)
		{
			return null;
		}
		else {
			return this.data[this.top--];
		}
	}
	
	//栈的打印
	void Stack_Print()
	{
		for (int i = 0; i <= this.top; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
