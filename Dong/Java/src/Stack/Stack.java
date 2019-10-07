package Stack;

public class Stack<T> {
	private int top;//ջ��ָ��
	private T [] data;
	private int size;//���洢�ռ�(�����Զ�����)
	
	//�޲ι���
	public Stack()
	{
		this.top = -1;
		this.size = 1;
		this.data = (T[])new Object[this.size];
	}
	//�вι���
	public Stack(int size)
	{
		this.top = -1;
		this.size = size;
		this.data = (T[])new Object[this.size];
	}
	//��ջ
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
	
	//��ջ
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
	
	//ջ�Ĵ�ӡ
	void Stack_Print()
	{
		for (int i = 0; i <= this.top; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
