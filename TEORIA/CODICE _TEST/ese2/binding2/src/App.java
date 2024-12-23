// ESERCIZIO 2: Overloading
class A {

    static void m(int x) {
        System.out.println("Mint");
    }

    static void m(double x) {
        System.out.println("Mdouble");
    }

    static void f(int g, double d) {
        System.out.println("Methodo 1");
    };

    static void f(double d, int g) {
        System.out.println("Methodo 2");
    };
}

public class App {
    public static void main(String[] args) {
        //A.f(3, 3); ERRORE IN COMPILAZIONE -> METODO AMBIGUO!!!
        A.m(3); //Mint
        A.m(6.67); //Mdouble
        
        double y = 2;
        A.m(y); // Mdouble
        short u = 8; //Short=2Byte | Int = 4Byte 
        //Abbiamo promozione numerica implicita senza perdita di dati da Short --> Int
        A.m(u); //Mint
    }
}