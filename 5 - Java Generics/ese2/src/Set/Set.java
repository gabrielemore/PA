package Set; //Ricorda di scrivere package altrimenti non va l'import!

import java.util.HashSet;

//in generale questa classe avrà sempre il generic!
public class Set<T> {

    private Object[] vet;
    private int len;
    static final int dim = 5;

    public Set() {
        this.vet = new Object[dim];
        len = dim;
    }

    public Set(T[] a) {
        // OK ma non verifico la dulicazione degli elementi
        // this.vet = new Object[a.length];
        // for (T e : a) {
        // vet[len] = e;
        // len++;
        // }

        // Per verificare la duplicazione degli elementi posso usare un TRUCCHETTO,
        // ovvero utilizzo hashset e poi come sottostante ritorno un vettore (come da
        // consegna)
        HashSet<T> obj = new HashSet<>();
        for (T e : a) {
            obj.add(e);
        }
        this.len = obj.size();
        this.vet = new Object[len];
        this.vet = obj.toArray();
    }

    // oppure meglio non farlo static e farlo in questo modo public void cancella()
    // e dal Main si richiama come obj.cancella();
    public static <T> void cancella(Set<T> obj) {
        obj.vet = null;
        obj.len = 0;
    }

    @Override
    // Il toString NON ha nessun parametro!!!
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("[");
        for (int i = 0; i < this.len; i++) {
            s.append(this.vet[i]).append(" ");
        }
        s.append("]");
        return s.toString();
    }

    @SuppressWarnings("unchecked")
    public static <T> Set<T> unione(Set<T> a, Set<T> b) {
        T[] c;
        HashSet<T> app = new HashSet<>();

        for (int i = 0; i < a.len; i++) {
            app.add((T) a.vet[i]);
        }

        for (int i = 0; i < b.len; i++) {
            app.add((T) b.vet[i]);
        }

        c = (T[]) app.toArray();
        return new Set<>(c);
    }

}