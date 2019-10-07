package test;
class Man
{
	int age;
	String name;
	Man(int a,String s)
	{
		age = a;
		name = s;
	}
	public String toString() {
		return "age "+age+"name: "+name;
		
	}
}
public class Test1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Man m1 = null;
		//Man m2 = new Man(12,"dzp");
		//test1(m2);
		//System.out.println(m2);
		int []arr = new int[3];
		arr[0] = 1;
		test2(arr);
		System.out.println(arr[0]);
	}
	
	static void test1(Man m)
	{
		//m = new Man(20,"xxx");
		m.age = 20;
		m.name = "xxx";
	}
	static void test2(int []arr)
	{
		arr[0] = 0;
	}
	

}
