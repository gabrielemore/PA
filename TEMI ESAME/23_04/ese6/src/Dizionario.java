import java.util.ArrayList;

public class Dizionario<T extends Comparable<? super T>, E> {

    private ArrayList<T> chiave;
    private ArrayList<E> valore;

    public Dizionario() {
        chiave = new ArrayList<>();
        valore = new ArrayList<>();
    }

    public void add(T c, E v) {
        if (chiave.contains(c))
            valore.set(chiave.indexOf(c), v);
        else {
            chiave.add(c);
            valore.add(v);
        }
    }

    public E get(T c) throws Exception {
        if (chiave.contains(c))
            return valore.get(chiave.indexOf(c));
        else
            throw new Exception("ERRORE: chiave non presente in lista");
    }

}
