package OrderedStack;

public class OrderedStack<T extends Comparable<? super T>> {
    private Object[] vet;
    private int len;
    private final static int delta = 10;

    public OrderedStack() {
        this.vet = new Object[delta];
        this.len = 0;
    }

    public void push(T e) {
        Object[] app;
        int i = 0;
        if (this.len + 1 < delta) {
            app = new Object[delta];
        } else {
            app = new Object[this.len + delta];
        }
        app[i] = e;
        i++;
        for (Object o : this.vet) {
            if (o != null) {
                app[i] = o;
                i++;
            }

        }
        this.vet = app;
        this.len = this.len + 1;
    }

    public T pop() {
        if (empty()) {
            return null;
        }
        Object[] app = new Object[this.vet.length];
        T ret = (T) this.vet[0];
        int i = 0;
        for (int j = 1; j < this.len; j++) {
            app[i] = this.vet[j];
            i++;
        }
        this.vet = app;
        this.len = this.len - 1;
        return ret;
    }

    public boolean empty() {
        return this.len == 0;
    }

    public void cancella() {
        this.vet = null;
        this.len = 0;
    }

    public T max() {
        T app = (T) this.vet[0];
        for (int i = 0; i < this.len; i++) {
            if (app.compareTo((T) this.vet[i]) < 0) {
                // elemento app minore di elemento i
                app = (T) this.vet[i];
            }
        }
        return app;
    }

    public T min() {
        T app = (T) this.vet[0];
        for (int i = 0; i < this.len; i++) {
            if (app.compareTo((T) this.vet[i]) > 0) {
                // elemento app maggiore di elemento i
                app = (T) this.vet[i];
            }
        }
        return app;
    }
}
