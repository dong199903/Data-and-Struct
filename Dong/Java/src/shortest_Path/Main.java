package shortest_Path;

/*************************************************************************
 > File Name: LinkStack.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019年10月3日 下午5:11:27
 >
 > 1）链栈的基本实现
 > 2）入栈和出栈等基本操作
 > 3）
 ************************************************************************/
public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MGraph m = new MGraph();
		m.creat_Graph_Matrix();
		//m.Bellman_Ford('a');
		//m.Dijkstra('a');
		//m.SPFA('a');
		m.Floyd();
		//m.Floyd();
	}

}
