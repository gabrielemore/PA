//Overloading (sovraccarico) si riferisce alla 
//definizione di più metodi con lo stesso nome, 
//ma con diverse firme (cioè differenti tipi o numeri di parametri) 
//all'interno della stessa classe (o una classe derivata).

class A {
    void m(int x) {
        System.out.println("A");
    }
}

class B extends A {
    // OVERLOADING
    void m(double x) {
        System.out.println("B");
    }
}
//Poiché B estende A, B eredita il metodo m(int x) dalla classe A.
//Oltre a questo, B introduce il suo metodo m(double x).

public class App {
    public static void main(String[] args) {
        B b = new B();
        b.m(10); // Chiama m(int x) ereditato dalla classe A --> stampa "A"
        b.m(10.5); // Chiama m(double x) definito nella classe B --> stampa "B"
    }
}
