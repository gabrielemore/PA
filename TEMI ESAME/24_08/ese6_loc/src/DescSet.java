
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class DescSet<T extends Comparable<T>> {

    private Object[] vet;
    private int dim;

    public DescSet() {
        vet = new Object[0];
        dim = 0;
    }

    public DescSet(List<T> v) {
        List<T> l = new ArrayList<>();
        for (T e : v) {
            if (!(l.contains(e))) {
                l.add(e);
            }
        }
        Collections.sort(l);
        Object[] app = l.toArray();
        this.vet = new Object[app.length];
        for (int i = 0; i < app.length; i++) {
            vet[app.length - i - 1] = app[i];
        }
        this.dim = vet.length;
    }

    public static <T extends Comparable<T>> DescSet<T> unione(DescSet o1, DescSet o2) {

        List<T> l = new ArrayList<>();

        for (int i = 0; i < o1.dim; i++) {
            l.add((T) o1.vet[i]);
        }

        for (int i = 0; i < o2.dim; i++) {
            if (!(l.contains(o2.vet[i]))) {
                l.add((T) o2.vet[i]);
            }
        }
        return new DescSet<>(l);

    }

    public void cancella() {
        this.vet = null;
        this.dim = 0;
    }

    public String toString() {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < dim; i++) {
            s.append(this.vet[i]).append(" ");
        }
        return s.toString();
    }
}
