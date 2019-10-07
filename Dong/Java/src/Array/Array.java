package Array;

public class Array<T> {
	private int length;
	private int index;
	private T[] data;
	//�޲ι���
	public Array()
	{
		this.index = 0;
		this.length = 1;
		this.data = (T[])new Object[this.length];
	}
	//�вι���
	public Array(int len)
	{
		this.index= 0;
		this.length = len;
		this.data = (T[])new Object[this.length];
	}
	//��������Ԫ�ظ���
	public int getLength()
	{
		return this.index;
	}
	//�ж������Ƿ�Ϊ��
	public boolean isEmpty()
	{
		return this.index==0;
	}
	//����β��
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
	//����ָ��λ��
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
	//ɾ��ָ��λ�õ�Ԫ��
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
	//��������
	public void Array_Show()
	{
		for (int i = 0; i < this.index; i++)
		{
			System.out.print(this.data[i]+" ");
		}
		System.out.println();
	}
}
