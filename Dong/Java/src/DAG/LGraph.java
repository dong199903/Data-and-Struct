package DAG;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019��10��3�� ����4:41:28
 >
 > 1����ջ�Ļ���ʵ��
 > 2����ջ�ͳ�ջ�Ȼ�������
 > 3��
 ************************************************************************/
public class LGraph {
	public char data;
	public Node head;
	public int degree;//ÿ���㶼�и���ȸ���
	public LGraph()
	{
		this.head = null;
		this.degree = 0;
	}
}
