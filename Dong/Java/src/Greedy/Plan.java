package Greedy;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019��10��3�� ����8:44:22
 >
 > 1��
 > 2��
 > 3��
 ************************************************************************/
public class Plan implements Comparable   {
	public int begin;
	public int last;
	public Plan(int b,int l)
	{
		this.begin = b;
		this.last = l;
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	//���ջ��ʼʱ������
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		if(o instanceof Plan)
		{
			Plan temp = (Plan)o;
			if(this.begin<temp.begin)
			{
				return -1;
			}else {
				return 1;
			}
		}
		return 0;
	}
	
	public String toString()
	{
		return "beign: "+this.begin+"  last: "+last;
	}
}
