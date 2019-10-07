package Greedy;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019年10月3日 下午8:44:22
 >
 > 1）
 > 2）
 > 3）
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
	//按照活动开始时间排序
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
