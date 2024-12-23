package Buffer;

import java.util.ArrayList;
import java.util.List;

public class MyBuffer<T> {

    private Object[] array;
    private int length;

    // ATTENZIONE: Il costruttore di un generico NON ha <T>!! ma solo il nome della
    // classe
    public MyBuffer() {
        array = null;
        length = 0;
    }

    public MyBuffer(T[] a, int l) {
        // per inizializzare un array ho bisogno della sua dimensione
        this.array = new Object[l];
        // questo sotto non posso farlo
        // this.array = new T[l];
        this.length = l;

        int i = 0;
        // per ogni elemento presente nell'array a...
        for (T e : a) {
            this.array[i] = e;
            i++;
        }
    }

    @SuppressWarnings("unchecked")
    public static <T> MyBuffer<T> accoda(MyBuffer<T> a, MyBuffer<T> b) {
        // Per fare questo utilizziamo un TRUCCHETTO con le liste
        // T[] c = new T[a.length + b.length];
        List<T> c = new ArrayList<>();
        int c_l = a.length + b.length;
        // Non puoi usare forech in questo caso per problemi con conversione Object - T
        for (int i = 0; i < a.length; i++) {
            // NB: è necessario fare il cast da Object a T
            c.add((T) a.array[i]);
        }
        for (int i = 0; i < b.length; i++) {
            // NB: è necessario fare il cast da Object a T
            c.add((T) b.array[i]);
        }

        // Serve questo per riportare la lista ad essere un array
        T[] c_ret = (T[]) c.toArray();
        // NB: per richiamare il costruttore si usa il generico, NON basta MyBuffer.
        // Questo nonstante il costruttore non abbia il generico
        return new MyBuffer<T>(c_ret, c_l);

        // Potevo fare anche subito un newMyBuffer e accedere ai campi dell'oggetto per
        // costruire c
    }

    // Per il cancella non serve farlo così passando un oggetto. Basta usare il this
    // public void cancella(MyBuffer<T> a)
    // {
    // a.array=null;
    // a.length=0;
    // }
    public void cancella() {
        this.array = null;
        this.length = 0;
    }

    public String toString() {
        // Si utilizza un oggeto apposito per creare la stringa da stampare
        StringBuilder s = new StringBuilder();
        // Scorriamo l'array presente in MyBuffer e "appendiamo" il carattere a s
        for (int i = 0; i < length; i++) {
            s.append(array[i] + "\t");
        }
        // NB: s non è di tipo string. Devi fare il toString di s prima di restituire s
        return s.toString();
    }

}
