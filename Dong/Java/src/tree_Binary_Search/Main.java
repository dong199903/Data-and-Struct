package tree_Binary_Search;

public class Main {
	public static void main(String[] args) {
		Tree t = new Tree();
		t.root = t.Insert_Tree(t.root, 1);
		t.root = t.Insert_Tree(t.root, 2);
		t.root = t.Insert_Tree(t.root, 3);
		t.root = t.Insert_Tree(t.root, 4);
		t.root = t.Insert_Tree(t.root, 5);
		t.root = t.Del_Tree(t.root, 5);
		t.mid_Order(t.root);
	}
}
