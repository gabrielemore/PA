// ESERCIZIO 4: Overriding
class A {

    void m(int x) {
        System.out.println("A");
    }
}

class B extends A {
    @Override
    void m(int x) {
        System.out.println("B");
    }
}

public class App {
    public static void main(String[] args) {
        A a;
        a = new B();
        a.m(3);
        //a.m(4.4);
    }
}
