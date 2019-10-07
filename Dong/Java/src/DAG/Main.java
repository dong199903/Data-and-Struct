package DAG;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019年10月3日 下午4:41:36
 >
 > 1）链栈的基本实现
 > 2）入栈和出栈等基本操作
 > 3）
 ************************************************************************/
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LGraph_List l = new LGraph_List();
		l.creat_Graph_List();
		//l.KaHn();
		l.DAG_DFS_Init();
	}

}
