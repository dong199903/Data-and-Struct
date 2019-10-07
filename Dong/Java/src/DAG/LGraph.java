package DAG;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019年10月3日 下午4:41:28
 >
 > 1）链栈的基本实现
 > 2）入栈和出栈等基本操作
 > 3）
 ************************************************************************/
public class LGraph {
	public char data;
	public Node head;
	public int degree;//每个点都有个入度个数
	public LGraph()
	{
		this.head = null;
		this.degree = 0;
	}
}
