package DFS;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		/*
		MGraph m1 = new MGraph();
		m1.creat_Graph_Matrix();
		m1.print_Graph_Matrix();
		m1.DFS_Matrix();
		m1.DFS_Matrix_Stack(0);
		m1.Find_Path('a', 'd');
		*/
		LGraph_List m2 = new LGraph_List();
		m2.creat_Graph_List();
		m2.DFS_List_Stack();
		m2.DFS_List();
	}

}
