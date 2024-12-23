package set;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class MySet<T> {

    static final int INITIAL_LENGTH = 10;
    static final int DELTA = 5;

    private int numElementi;
    private Object[] array;



    public MySet() {
        this.array = new Object[INITIAL_LENGTH];
        this.numElementi = 0;
    }

    public MySet(List<T> elements){
        //Utilizzo HashSet (implementa set) che elimina in automatico i duplicati
        // e ordina automaticamente gli elementi
        HashSet<T> uniqueElements = new HashSet<T>(elements);
        int length = uniqueElements.size();

        array = new Object[length];
        int i = 0;
        for(T elem : uniqueElements){
            array[i] = elem;
            i++;
            numElementi++;
        }

    }

    @SuppressWarnings("unchecked")
    public static <T> MySet<T> unione(MySet<T> a, MySet<T> b){
        List<T> listaElementi = new ArrayList<>();
        //Copio il primo array nella list
        for(int i = 0; i < a.numElementi; i++){
            listaElementi.add((T) a.array[i]);
        }
        //Copio il secondo array nella list
        for(int i = 0; i < b.numElementi; i++){
            listaElementi.add((T) b.array[i]);
        }

        //Chiamo il costruttore con la Lista ottenuta
        return new MySet<T>(listaElementi);

    }


    @Override
    @SuppressWarnings("unchecked")
    public MySet<T> clone() {
        return new MySet<T>(Arrays.asList((T[]) array));
    }

    @Override
    public String toString() {
        System.out.println("Set di dimensione: " + numElementi);
        StringBuilder b = new StringBuilder();
        b.append("[ ");
        for(int i = 0; i < numElementi; i++){
            b.append(array[i]).append(" ");
        }
        b.append("]");
        return b.toString();
    }

    /* Esula dalla consegna dell'esercizio, inoltre se aggiungo un elemento così
    non rispetto la proprieta del Set (no duplicati)*/
    public void addElement(T element){
        if(numElementi < array.length) {
            array[numElementi] = element;
            numElementi++;
        } else {
            Object[] newArray = new Object[numElementi + DELTA];
            for(int i = 0; i < numElementi; i++){
                newArray[i] = array[i];
            }
            newArray[numElementi] = element;
            array = newArray;
            numElementi++;
        }
    }


    public void cancella(){
        array = null;
        numElementi = 0;
    }


}