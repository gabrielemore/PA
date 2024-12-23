public class OrderedStack<T extends Comparable<? super T>> {

    private Object[] vet;
    private int numEle;
    private final int delta = 3;

    public OrderedStack() {
        vet = new Object[10];
        numEle = 0;
    }

    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("[");
        for (int i = 0; i < numEle; i++) {
            s.append((T) vet[i]).append(" ");
        }
        s.append("]");
        return s.toString();
    }

    public void push(T n) {
        if (numEle + 1 > vet.length) {
            Object[] app = new Object[vet.length + delta];
            for (int i = 0; i < numEle; i++) {
                app[i] = vet[i];
            }
            vet = app;
        }
        vet[numEle] = n;
        numEle++;
    }

    public T pop() {
        T ret = (T) vet[numEle - 1];
        vet[numEle - 1] = null;
        numEle--;
        return ret;
    }

    public boolean empty() {
        return numEle == 0;
    }

    public T max() {
        T ret = (T) vet[0];
        for (int i = 0; i < numEle; i++) {
            if (ret.compareTo((T) vet[i]) < 0)
                ret = (T) vet[i];
        }
        return ret;
    }

    public T min() {
        T ret = (T) vet[0];
        for (int i = 0; i < numEle; i++) {
            if (ret.compareTo((T) vet[i]) > 0)
                ret = (T) vet[i];
        }
        return ret;
    }

}
