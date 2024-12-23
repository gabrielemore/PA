/*  TE 11/2023
    ES.5 JAVA GENERICS  
*/

import Buffer.MyBuffer;

public class App {
    public static void main(String[] args) throws Exception {
        Integer[] x = { 1, 4, 6, 8, 9 };

        Integer[] y = { -5, -8, -2, -3, -1 };

        String[] s = { "c", "i", "a", "o" };
        String[] ss = { "p", "i", "p", "o" };

        MyBuffer<Integer> a = new MyBuffer<>(x, 5);
        MyBuffer<Integer> b = new MyBuffer<Integer>(y, 5);
        // Funziona lo stesso ma da un warning
        MyBuffer<Integer> d = new MyBuffer(x, 5);

        // Con stringhe
        MyBuffer<String> e = new MyBuffer<>(s, 4);
        MyBuffer<String> f = new MyBuffer<>(ss, 4);

        // Ricorda che per stampare una stringa devi usare il sys.out.print..!!
        System.out.println(a.toString());

        MyBuffer<Integer> c = MyBuffer.accoda(a, b);

        System.out.println(c.toString());

        System.out.println(d.toString());
        d.cancella();
        System.out.println(d.toString());

        System.out.println(e.toString());

        MyBuffer<String> g = MyBuffer.accoda(f, e);

        System.out.println(g.toString());
    }
}
