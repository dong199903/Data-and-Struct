package Array;

public class Array<T> {
	private int length;
	private int index;
	private T[] data;
	//无参构造
	public Array()
	{
		this.index = 0;
		this.length = 1;
		this.data = (T[])new Object[this.length];
	}
	//有参构造
	public Array(int len)
	{
		this.index= 0;
		this.length = len;
		this.data = (T[])new Object[this.length];
	}
	//返回数组元素个数
	public int getLength()
	{
		return this.index;
	}
	//判断数组是否为空
	public boolean isEmpty()
	{
		return this.index==0;
	}
	//插在尾部
	public void Array_Append(T data)
	{
		if (this.index == this.length)
		{
			this.length = 2 *this.index;
			T [] newData = (T[])new Object[this.length];
			for (int i = 0; i < this.index; i++)
			{
				newData[i] = this.data[i];
			}
			this.data = newData;
			this.data[this.index] = data;
			this.index++;
		}
		else {
			this.data[this.index] = data;
			this.index++;
		}
	}
	//插在指定位置
	public void Array_Insert(int index,T data)
	{
		if (index <= 0 || index > this.index + 1)
		{
			return;
		}
		if (this.index == this.length)
		{
			this.length = 2 * this.index;
			T [] newData = (T[])new Object[this.length];
			for (int i = 0; i < this.index; i++)
			{
				newData[i] = this.data[i];
			}
			this.data = newData;
		}
		for (int i = this.index; i >= index; i--)
		{
			this.data[i] = this.data[i - 1];
		}
		this.data[index - 1] = data;
		this.index++;
	}
	//删除指定位置的元素
	public void Array_Delete(int index)
	{
		if (index <= 0 || index >this.index)
		{
			return;
		}
		else {
			for (int i = index - 1; i < this.index - 1; i++)
			{
				this.data[i] = this.data[i + 1];
			}
			this.index--;
		}
	}
	//遍历数组
	public void Array_Show()
	{
		for (int i = 0; i < this.index; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
