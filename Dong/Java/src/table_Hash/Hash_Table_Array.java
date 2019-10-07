package table_Hash;

public class Hash_Table_Array {
	private int maxSize;//���洢��
	private int [] data;
	private int size;//��ǰ�洢���ݸ���
	public Hash_Table_Array()
	{
		this.maxSize = 10;
		this.data = new int[this.maxSize];
		this.size = 0;
		for (int i = 0; i < this.maxSize; i++)
		{
			this.data[i] = 99999;//��������ʼֵ(���)
		}
	}
	public void Insert(int data)//��������
	{
		int []newData;
		int i,index;
		//1.ÿ�β�������ǰ���ȼ���Ƿ񳬹������װ������
		if (this.size*1.0 >= this.maxSize*0.75)
		{
			newData = new int[this.maxSize * 2];
			for (i = 0; i < this.maxSize * 2; i++)
			{
				newData[i] = 99999;
			}
			//��ԭ��������ӳ���ַ
			for (i = 0; i < this.maxSize;i++)
			{
				
				if (this.data[i] != 99999)
				{
					index = this.data[i] % (2 * this.maxSize);
					while (newData[index] != 99999)
					{
						index = (index + 1) % (2 * this.maxSize);
					}
					newData[index] = this.data[i];
				}
			}
			this.maxSize = 2 * this.maxSize;
			this.data = newData;
			index = data % this.maxSize;
			//���ŵ�ַ��
			while (this.data[index] != 99999)
			{
				index = (index + 1) % this.maxSize;
			}
			this.data[index] = data;
			this.size++;
		}
		else {
			index = data % this.maxSize;
			//���ŵ�ַ��
			while (this.data[index]!=99999)
			{
				index = (index + 1) % this.maxSize;
			}
			this.data[index] = data;
			this.size++;
		}
	}
	public int isFind(int data)//���������Ƿ����
	{
		int index,sum=0;
		index = data % this.maxSize;
		//���ŵ�ַ��
		while (this.data[index] != data)
		{
			index = (index + 1) % this.maxSize;
			sum++;
			//���������������Ϊ�գ����߻ص�ԭ�㣬��ʾ�����ݲ�����
			if (this.data[index] == 99999 || sum == this.maxSize)
			{
				return -1;
			}
		}
		return index;
	}
}
