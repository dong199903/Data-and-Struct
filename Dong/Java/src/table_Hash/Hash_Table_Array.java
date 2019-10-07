package table_Hash;

public class Hash_Table_Array {
	private int maxSize;//最大存储量
	private int [] data;
	private int size;//当前存储数据个数
	public Hash_Table_Array()
	{
		this.maxSize = 10;
		this.data = new int[this.maxSize];
		this.size = 0;
		for (int i = 0; i < this.maxSize; i++)
		{
			this.data[i] = 99999;//标记数组初始值(标空)
		}
	}
	public void Insert(int data)//插入数据
	{
		int []newData;
		int i,index;
		//1.每次插入数据前，先检测是否超过了最大装载因子
		if (this.size*1.0 >= this.maxSize*0.75)
		{
			newData = new int[this.maxSize * 2];
			for (i = 0; i < this.maxSize * 2; i++)
			{
				newData[i] = 99999;
			}
			//将原数据重新映射地址
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
			//开放地址法
			while (this.data[index] != 99999)
			{
				index = (index + 1) % this.maxSize;
			}
			this.data[index] = data;
			this.size++;
		}
		else {
			index = data % this.maxSize;
			//开放地址法
			while (this.data[index]!=99999)
			{
				index = (index + 1) % this.maxSize;
			}
			this.data[index] = data;
			this.size++;
		}
	}
	public int isFind(int data)//查找数据是否存在
	{
		int index,sum=0;
		index = data % this.maxSize;
		//开放地址法
		while (this.data[index] != data)
		{
			index = (index + 1) % this.maxSize;
			sum++;
			//如果继续查找数据为空，或者回到原点，表示该数据不存在
			if (this.data[index] == 99999 || sum == this.maxSize)
			{
				return -1;
			}
		}
		return index;
	}
}
