package table_Hash;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Hash_Table_List h1 = new Hash_Table_List();
		h1.Insert(1);
		h1.Insert(10);
		h1.Insert(7);
		h1.Insert(8);
		System.out.println(h1.isFind(4));
		System.out.println(h1.isFind(7));
		
		/*
		Hash_Table_Array h2 = new Hash_Table_Array();
		h2.Insert(1);
		h2.Insert(10);
		h2.Insert(7);
		h2.Insert(8);
		System.out.println(h2.isFind(4));
		System.out.println(h2.isFind(7));
		*/
	}

}
