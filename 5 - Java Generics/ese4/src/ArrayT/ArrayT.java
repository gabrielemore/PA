package ArrayT;

import java.util.ArrayList;

public class ArrayT<T> {
    private Object[] array;
    private final int buffer = 10;
    private int len;

    public ArrayT() {
        array = new Object[buffer];
        len = 0;
    }

    public ArrayT(T[] a) {
        array = new Object[a.length];
        len = 0;
        for (T e : a) {
            array[len] = e;
            len++;
        }
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("{");
        for (Object o : this.array) {
            s.append(o).append(",");
        }
        s.deleteCharAt(s.lastIndexOf(","));
        s.append("}");
        return s.toString();
    }

    public void cancella() {
        this.array = null;
        this.len = 0;
    }

    @SuppressWarnings("unchecked")
    public static <T> ArrayT<T> accoda(ArrayT<T> x, ArrayT<T> y) {
        ArrayList<T> app = new ArrayList<>();
        for (int i = 0; i < y.len; i++) {
            app.add((T) y.array[i]);
        }
        for (int i = 0; i < x.len; i++) {
            app.add((T) x.array[i]);
        }
        return new ArrayT<T>((T[]) app.toArray());

    }
}
