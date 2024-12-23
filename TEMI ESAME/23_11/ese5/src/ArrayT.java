public class ArrayT<T> {

    private Object[] vet;
    private int dim;

    public ArrayT(T[] v) {
        this.vet = new Object[v.length];
        int i = 0;
        for (T e : v) {
            this.vet[i] = e;
            i++;
        }
        this.dim = v.length;
    }

    public void accoda(ArrayT<T> o) {
        Object[] app = new Object[this.dim + o.dim];
        for (int i = 0; i < this.dim; i++) {
            app[i] = this.vet[i];
        }
        for (int j = 0; j < o.dim; j++) {
            app[this.dim + j] = o.vet[j];
        }
        this.vet = app;
        this.dim = this.vet.length;
    }

    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("\"");
        for (int i = 0; i < dim; i++) {
            s.append(vet[i]).append(" ");
        }
        s.append("\"");
        return s.toString();
    }

    // In Java la funzione cancella non ha molto senso di esistere data la presenza
    // del garbage collector che si occupa in automatico di liberare la memoria
    // qunado questa non serve piu
}
