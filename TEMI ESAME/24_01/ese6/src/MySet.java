import java.util.ArrayList;
import java.util.List;

//ATTENZIONE: Cerca di non usare T extends comparable e poi un array di Object perchè nei cast poi è un dito nel culo
// in questo caso usa le List che presentano dei metodi come .contains() o direttamente HashSet che non inserisce duplicati
// Il problema lo hai quando da object devi fare un cast ad un T e questo T deve essere comparable (da errore in compilazione)

public class MySet<T extends Comparable<T>> {

    Object[] vet;
    int dim;

    public MySet(T[] v) {
        vet = new Object[v.length];
        dim = 0;
        for (T e : v) {
            if (!isPresent(e)) {
                vet[dim] = e;
                dim++;
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < dim; i++) {
            s.append(vet[i]).append(" ");
        }
        return s.toString();
    }

    public static <T extends Comparable<T>> MySet<T> unione(MySet<T> o1, MySet<T> o2) {

        Object[] v_ret = new Object[o1.dim + o2.dim];

        for (int i = 0; i < o1.dim; i++) {
            v_ret[i] = o1.vet[i];
        }
        for (int i = 0; i < o2.dim; i++) {
            v_ret[i] = o2.vet[i];
        }

        // QUESTO E' IL DITO IN CULO DI CUI PARLAVO
        return new MySet<>((T[]) v_ret);

    }

    private boolean isPresent(T e) {
        for (int i = 0; i < dim; i++) {
            if (e.compareTo((T) vet[i]) == 0)
                return true;
        }
        return false;
    }

}
