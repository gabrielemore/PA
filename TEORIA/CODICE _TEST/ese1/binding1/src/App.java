// ESERCIZIO 1: Binding
class G {
}

class F extends G {
}

class S {

    void foo(G a) {
        System.out.println("S");
    }
}

class T extends S {
    // overloading
    void foo(F b) {
        System.out.println("T");
    }
}

public class App {
    public static void main(String[] args) {
        S s = new T();
        G a = new G();
        s.foo(a);
        // STATICO: Cerco in S un foo(G) -> c'è
        // e lo seleziono
        // DINAMICO: Cerco in T un foo(G),
        // non lo trovo, risalgo in S e li c'è
        F f = new F();
        s.foo(f);
        // STATICO: cerco in S un foo(F), non c'è
        // seleziono foo(G) (promuovo F a G, è il più "vicino" e compatibile)
        // DINAMICO: cerco in T un foo(G),
        // non lo trovo, risalgo in S e li lo trovo


        //Stamperò due volte "S"
    }
}