// Es5
import set.MySet;

public class Main {

	public static void main(String[] args) {
		MySet<Integer> b1=new MySet<Integer>();
		
		for(int i=0; i<8;i++) {
			b1.addElement(i);
		}
		
		MySet<Integer> b2=new MySet<Integer>();
		
		for(int i=0; i<8;i++) {
			b2.addElement(i+15);
		}

		MySet<Integer> b3=MySet.union(b1, b2);
		
		System.out.println(b3);
		

		MySet<Character> c1=new MySet<Character>();
		
		for(int i=0; i<8;i++) {
			c1.addElement((char) (65+i));
		}
		
		MySet<Character> c2=new MySet<Character>();
		
		for(int i=0; i<8;i++) {
			c2.addElement((char) (65+i+15));
		}

		MySet<Character> c3=MySet.union(c1, c2);
		
		System.out.println(c3);
		

	}

}
