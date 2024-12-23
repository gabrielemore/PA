package set;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class MySet<T> {
	
	Object[] array;
	private final static int BUFFER_DIMENSION=10;
	private int lastElementIndex=0;
	
	public MySet() {
		this.array=new Object[BUFFER_DIMENSION];
		lastElementIndex=0;
	}
	
	
	public MySet(List<T> elements) {
		this.array=new Object[BUFFER_DIMENSION];
		
		HashSet<T> uniqueElements=new HashSet<T>(elements);
		
		int i=0;
		for(T e: uniqueElements) {
			array[i]=e;
			lastElementIndex=lastElementIndex+1;
			i++;
		}
	}
	
	public String toString() {
		StringBuilder b=new StringBuilder();
		for(int i=0; i< lastElementIndex; i++) {
			b.append(array[i]+"\t");
		}
		return b.toString();
	}
	
	@SuppressWarnings("unchecked")
	public MySet<T> clone(){
		return new MySet(
				Arrays.asList(array)
				);
	}
	
	public void addElement(T element) {
		if(lastElementIndex==array.length) {
			Object[] buffer1=new Object[array.length+BUFFER_DIMENSION];
			for(int i=0; i< lastElementIndex; i++) {
				buffer1[i]=array[i];
			}
			buffer1[lastElementIndex]=element;
			lastElementIndex=lastElementIndex+1;
			array=buffer1;
		}
		else {
			array[lastElementIndex]=element;
			lastElementIndex=lastElementIndex+1;
		}
	}
	
	public void cancella() {
		this.array=null;
	}

	// I metodi statici non possono accedere ai parametri di tipo generico definiti a livello di classe. 
	// I parametri di tipo generico della classe (<T> nel tuo esempio) sono legati all'istanza della classe, 
	// ma poiché il metodo statico non appartiene a un'istanza specifica, non ha accesso a questi parametri 
	// di tipo a meno che non siano dichiarati esplicitamente nel metodo. Quindi deve essere scritto prima
	// in modo esplicito perchè T non sarebbe riconosciuto dal metodo, poiché non è stato dichiarato come 
	// parametro di tipo generico all'interno del metodo stesso.
	
	@SuppressWarnings("unchecked")
	public static <T> MySet<T> union(MySet<T> x, MySet<T> y){
		List<T> elements=new ArrayList<>();
		
		for(int i=0; i< x.lastElementIndex; i++) {
			elements.add((T) x.array[i]);
		}

		for(int i=0; i< y.lastElementIndex; i++) {
			elements.add((T) y.array[i]);
		}
		return new MySet<T>(elements);
	}
}
