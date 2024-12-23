import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import Mobile.Armadio;
import Mobile.Mobile;
import Mobile.Tavolo;
import Visitor.Visitor;
import Visitor.getCosto;

public class App {
    // con questa scrittura Posso passargli anche una lista di Tavolo che non
    // implementa il metodo compareTo o implementa direttamente Comparable ma il cui
    // padre (Mobile) si. Per determinare il max verrà utilizzato il compareTo del
    // padre (Mobile)
    public static <T extends Comparable<? super T>> T getMax(List<T> l) {
        return Collections.max(l);
    }

    // con questa scrittura Tavolo e Armadio generano errore
    public static <T extends Comparable<T>> T getMaxRes(List<T> l) {
        return Collections.max(l);
    }

    public static void main(String[] args) throws Exception {
        Armadio a1 = new Armadio("pippo");
        Armadio a2 = new Armadio("pluto");

        Mobile m1 = new Mobile("minni");
        Mobile m2 = new Mobile("topolino");

        Tavolo t1 = new Tavolo("bruto");
        Tavolo t2 = new Tavolo("cassio");

        Visitor<Integer> v_costo = new getCosto();

        System.out.println(m1.accept(v_costo));
        System.out.println(a1.accept(v_costo));
        System.out.println(t1.accept(v_costo));

        System.out.println("-----------------------");

        List<Mobile> l1 = new ArrayList<>();
        // lista mobile posso aggiungere mobile,tavolo e armadio
        l1.add(a1);
        l1.add(a1);
        l1.add(m1);
        l1.add(m2);
        l1.add(t1);
        l1.add(t2);
        // essendo lista<Mobile> posso usare sia funzione piu restrittiva che quella piu
        // generale nonostante all'interno di questa lista ci siano Tavoli e Armadi
        System.out.println(getMax(l1));
        System.out.println(getMaxRes(l1));

        System.out.println("-----------------------");

        List<Armadio> l2 = new ArrayList<>();
        // Lista Armadio posso aggiungere solo elementi Armadio
        // l2.add(t1); ERRORE
        l2.add(a1);
        l2.add(a2);

        // essendo lista<Armadio> NON posso usare funzione piu restrittiva perchè
        // Armadio non implementa dirrettamente Comparable
        System.out.println(getMax(l2));
        // System.out.println(getMaxRes(l2)); ERRORE

        // del tutto analogo per Tavolo...

    }
}
