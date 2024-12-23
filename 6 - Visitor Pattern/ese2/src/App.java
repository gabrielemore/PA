/*  TE 11/2023
    ES.6 VISITOR PATTERN  
*/

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import Mobile.Armadio;
import Mobile.Mobile;
import Mobile.Tavolo;
import Visitor.Visitor;
import Visitor.getPrezzo;

public class App {

    public static <T extends Comparable<T>> T findMax(List<T> l) {
        return Collections.max(l);
    }

    public static void main(String[] args) throws Exception {
        Mobile m1 = new Mobile("ikea");
        Mobile m2 = new Mobile("aaaa");
        Tavolo t1 = new Tavolo("cassio");
        Tavolo t2 = new Tavolo("breno");
        Tavolo t3 = new Tavolo("zante");
        Armadio a1 = new Armadio("penelope");

        // Ricorda che il visitor specifico deve avere il nome della classe che esegue
        // il metodo
        Visitor<Integer> v_i = new getPrezzo();

        System.out.println(m1.accept(v_i));
        System.out.println(t1.accept(v_i));
        System.out.println(a1.accept(v_i));

        List<Mobile> list = new ArrayList<>();
        list.add(m1);
        list.add(m2);

        System.out.println(findMax(list));

        List<Mobile> list_t = new ArrayList<>();
        list_t.add(t1);
        list_t.add(t2);
        list_t.add(t3);

        System.out.println(findMax(list_t));

    }
}
