package BFS;

public class Main {
	public static void main(String[] args) {
		MGraph m1 = new MGraph();
		m1.creat_Graph_Matrix();
		m1.BFS_Matrix();
		m1.Find_Path('a', 'd');
		//LGraph_List m2 = new LGraph_List();
		//m2.creat_Graph_List();
		//m2.BFS_List_Queue();
	}
}
