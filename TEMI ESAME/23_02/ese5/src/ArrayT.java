public class ArrayT<T> {

    private Object[] vet;
    private int numEle;

    public ArrayT(T[] v) {
        vet = new Object[v.length];
        int i = 0;
        for (T e : v) {
            vet[i] = e;
            i++;
        }
        numEle = i;
    }

    public void accoda(T[] v) {
        Object[] app = new Object[v.length + vet.length];
        int i = 0;
        for (Object e : vet) {
            app[i] = e;
            i++;
        }
        for (int j = 0; j < v.length; j++) {
            app[i] = v[j];
            i++;
        }
        this.vet = app;
        this.numEle = i;
        // si poteva usare anche
        // System.arraycopy();
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("{");
        for (int i = 0; i < numEle; i++) {
            s.append(vet[i]);
            if (i < numEle - 1)
                s.append(",");
        }
        s.append("}");
        return s.toString();
    }

}
