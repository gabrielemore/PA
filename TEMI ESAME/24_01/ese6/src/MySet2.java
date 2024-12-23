import java.util.ArrayList;
import java.util.List;

public class MySet2<T> {

    Object[] vet;
    int dim;

    public MySet2(T[] v) {
        List<T> l = new ArrayList<>();
        for (T e : v) {
            if (!l.contains(e)) {
                l.add(e);
            }
        }
        dim = l.size();
        vet = l.toArray();
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < dim; i++) {
            s.append(vet[i]).append(" ");
        }
        return s.toString();
    }

    public static <T> MySet2<T> unione(MySet2<T> o1, MySet2<T> o2) {

        List<T> l = new ArrayList<>();

        for (int i = 0; i < o1.dim; i++) {
            l.add((T) o1.vet[i]);
        }
        for (int i = 0; i < o2.dim; i++) {
            l.add((T) o2.vet[i]);
        }

        return new MySet2<>((T[]) l.toArray());

    }

    public void cancella() {
        vet = null;
        dim = 0;
    }

}
