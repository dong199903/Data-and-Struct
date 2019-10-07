package Sort3;

//桶排序用的链表结构
public class Tool {
	public Tool next;
	public int data;
	Tool()
	{
		this.next = null;
	}
}
//基数排序用到的数组结构
class Array
{
	public int[] data;
	public int len;
	public Array()
	{
		this.data = null;
		this.len = 0;
	}
}
