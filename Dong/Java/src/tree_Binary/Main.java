package tree_Binary;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tree t1 = new Tree();
		t1.root = t1.creat_Tree(t1.root);
		//t1.pre_Order(t1.root);
		//t1.level_Order();
		System.out.println("�������Ľڵ������: "+t1.getCount(t1.root));
		System.out.println("�������ĸ߶���: "+t1.getHigh(t1.root));
		/*
		Tree_Line t2 = new Tree_Line();
		t2.Creat_Tree_Line(1);
		t2.pre(1);
		t2.post(1);
		t2.level();
		System.out.println("�ڵ������: "+t2.getCount_Line(1));
		System.out.println("���ĸ߶���: "+t2.getHigh_Line(1));
		*/	
	}
}
