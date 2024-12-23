/*  TE 07/2023
    ES.6 VISITOR PATTERN  
*/

import java.util.ArrayList;
import java.util.List;

import Carichi.Carico;
import Carichi.DieciCarichi;
import Carichi.Doppio;
import Carichi.Singolo;
import Visitor.Visitor;
import Visitor.getCount;
import Visitor.getMax;

public class App {
    public static void main(String[] args) throws Exception {

        // List<Carico<Integer>> l = new ArrayList<>();

        // Carico<Integer> c1 = new Singolo<Integer>(2);
        // Carico<Integer> d1 = new Doppio<Integer>(4, 2);

        // Carico<Integer> c2 = new Singolo<Integer>(7);
        // Carico<Integer> d2 = new Doppio<Integer>(8, 5);

        // Carico<Integer> c3 = new Singolo<Integer>(1);
        // Carico<Integer> d3 = new Doppio<Integer>(9, 3);

        // Carico<Integer> c4 = new Singolo<Integer>(2);
        // Carico<Integer> d4 = new Doppio<Integer>(4, 5);

        // Carico<Integer> c5 = new Singolo<Integer>(4);
        // Carico<Integer> c6 = new Singolo<Integer>(0);

        // l.add(c1);
        // l.add(c2);
        // l.add(c3);
        // l.add(c4);
        // l.add(c5);
        // l.add(c6);
        // l.add(d1);
        // l.add(d2);
        // l.add(d3);
        // l.add(d4);

        // Carico<Integer> d_c1 = new DieciCarichi<>(l);

        // // VISITOR
        // Visitor<Integer> v_i = new getCount();
        // Visitor<Integer> v_max = new getMax<Integer>();

        // // COUNT
        // System.out.println(c1.accept(v_i)); // 1
        // System.out.println(d4.accept(v_i)); // 2
        // System.out.println(d_c1.accept(v_i)); // 14

        // // MAX
        // System.out.println(d_c1.accept(v_max)); // 9
        // System.out.println(d4.accept(v_max)); // 5
        // System.out.println(c6.accept(v_max)); // 0


        //CON STRING
        List<Carico<String>> l = new ArrayList<>();

        Carico<String> c1 = new Singolo<String>("a");
        Carico<String> d1 = new Doppio<String>("n", "z");

        Carico<String> c2 = new Singolo<String>("e");
        Carico<String> d2 = new Doppio<String>("w", "l");

        Carico<String> c3 = new Singolo<String>("h");
        Carico<String> d3 = new Doppio<String>("p", "g");

        Carico<String> c4 = new Singolo<String>("t");
        Carico<String> d4 = new Doppio<String>("e", "l");

        Carico<String> c5 = new Singolo<String>("y");
        Carico<String> c6 = new Singolo<String>("u");

        l.add(c1);
        l.add(c2);
        l.add(c3);
        l.add(c4);
        l.add(c5);
        l.add(c6);
        l.add(d1);
        l.add(d2);
        l.add(d3);
        l.add(d4);

        Carico<String> d_c1 = new DieciCarichi<>(l);

        // VISITOR
        Visitor<Integer> v_i = new getCount();
        Visitor<String> v_max = new getMax<String>();

        // COUNT
        System.out.println(c1.accept(v_i)); // 1
        System.out.println(d4.accept(v_i)); // 2
        System.out.println(d_c1.accept(v_i)); // 14

        // MAX
        System.out.println(d_c1.accept(v_max)); // z
        System.out.println(d4.accept(v_max)); // l
        System.out.println(c6.accept(v_max)); // u

    }
}
