package tree_Binary;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tree t1 = new Tree();
		t1.root = t1.creat_Tree(t1.root);
		//t1.pre_Order(t1.root);
		//t1.level_Order();
		System.out.println("二叉树的节点个数是: "+t1.getCount(t1.root));
		System.out.println("二叉树的高度是: "+t1.getHigh(t1.root));
		/*
		Tree_Line t2 = new Tree_Line();
		t2.Creat_Tree_Line(1);
		t2.pre(1);
		t2.post(1);
		t2.level();
		System.out.println("节点个数是: "+t2.getCount_Line(1));
		System.out.println("树的高度是: "+t2.getHigh_Line(1));
		*/	
	}
}
