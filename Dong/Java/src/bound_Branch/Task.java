package bound_Branch;

public class Task {
	static int MAX = 100;
	public int lever;
	public int down;//下界最优成本
	public int cost;//已经分配的成本
	public int temp[] = new int[MAX];//任务是否分配
}
