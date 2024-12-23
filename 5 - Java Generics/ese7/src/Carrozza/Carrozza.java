package Carrozza;

public class Carrozza<T> {
    private Object[] vet;
    private int len;
    private static final int delta = 2;

    public Carrozza() {
        this.vet = new Object[delta];
        this.len = 0;
    }

    public Carrozza(T[] e) {
        this.len = 0;
        if (e.length > delta) {
            this.vet = new Object[e.length + delta];
        } else {
            this.vet = new Object[delta];
        }
        for (T o : e) {
            // con questa scrittura assegniamo alla posizione len di vet l'elemento o. Solo
            // dopo effettuiamo il ++. Se mettessimo il ++ a sinistra effettuiamo il cambio
            // dell'indice prima di assegnare alla posizione len di vet l'elemento o. Quindi
            // assegneremmo a len+1 e non a len
            this.vet[this.len++] = o;
        }
    }

    public void insert(T e) {
        if (this.len + 1 > this.vet.length) {
            Object[] app = new Object[this.vet.length + delta];
            for (int i = 0; i < this.vet.length; i++) {
                app[i] = this.vet[i];
            }
            this.vet = app;
        }
        this.vet[this.len++] = e;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("[");
        for (Object o : this.vet) {
            if (o != null)
                s.append(o.toString()).append(" ");
        }
        s.append("]");
        return s.toString();
    }

}
