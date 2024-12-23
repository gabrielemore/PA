package TreatArray;

import java.util.ArrayList;

public class TreatArray<T extends Comparable<? super T>> {
    private ArrayList<T> vet;

    public TreatArray() {
        this.vet = new ArrayList<>();
    }

    public TreatArray(T[] a) {
        this.vet = new ArrayList<>();
        for (T e : a) {
            vet.add(e);
        }
    }

    public T max() {
        T max;
        ArrayList<T> app = this.vet;
        // con arraylist si puo usare il sort. se all'interno del metodo sort si mette
        // null viene utilizzato come "discriminante" per ordinare il vettore il
        // naturale ordine degli oggetti
        app.sort(null);
        max = app.get(app.size() - 1);
        return max;
    }

    public T min() {
        T max;
        ArrayList<T> app = this.vet;
        // con arraylist si puo usare il sort. se all'interno del metodo sort si mette
        // null viene utilizzato come "discriminante" per ordinare il vettore il
        // naturale ordine degli oggetti
        app.sort(null);
        max = app.get(0);
        return max;
    }

    public void sort() {
        // con arraylist si puo usare il sort. se all'interno del metodo sort si mette
        // null viene utilizzato come "discriminante" per ordinare il vettore il
        // naturale ordine degli oggetti
        this.vet.sort(null);
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("[");
        for (T e : this.vet) {
            s.append(e).append("\t");
        }
        s.append("]");
        return s.toString();
    }
}
