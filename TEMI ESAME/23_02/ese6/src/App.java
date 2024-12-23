import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import Mobili.Armadio;
import Mobili.Mobile;
import Mobili.Tavolo;
import Visitor.*;

public class App {

    // NB:il max non è sul prezzo, ma sul campo comparable, ovvero il nome. Non
    // serve richiamare il visitor. Non chiede di tornare il max prezzo

    // Con questa segnatura al posto di <T extends Comparable<T>> posso mandare
    // anche delle sottoclassi che non implementano in modo esplicito Comparable
    // ma il cui padre lo fa
    // ESEMPIO: Mobile implementa Comparable ma Tavolo e Armadio no (non in modo
    // esplcito)
    // max prenderà il metodo del padre non essendo implementato nei figli
    public static <T extends Comparable<? super T>> T getMax(List<T> l) {
        return Collections.max(l);
    }

    // Con questa funzione mandare List<Tavolo> o List<Armadio> genera ERRORE
    public static <T extends Comparable<T>> T getMaxRes(List<T> l) {
        return Collections.max(l);
    }

    public static void main(String[] args) throws Exception {
        Mobile m = new Mobile("clara");
        Mobile m2 = new Mobile("fiamma");
        Tavolo t1 = new Tavolo("ikea");
        Tavolo t2 = new Tavolo("krug");
        Armadio a1 = new Armadio("roku");
        Armadio a2 = new Armadio("pilo");

        Visitor<Integer> v = new getPrezzo();

        System.out.println("M:\t" + m.accept(v));
        System.out.println("T:\t" + t1.accept(v));
        System.out.println("A:\t" + a1.accept(v));
        System.out.println("-------");

        List<Mobile> l1 = new ArrayList<>();
        l1.add(m);
        l1.add(m2);
        l1.add(t1);
        l1.add(t2);
        l1.add(a1);
        l1.add(a2);
        System.out.println("max:\t" + getMax(l1));
        System.out.println("max:\t" + getMaxRes(l1));
        System.out.println("-------");

        List<Tavolo> l2 = new ArrayList<>();
        l2.add(t1);
        l2.add(t2);
        System.out.println("max:\t" + getMax(l2));
        // System.out.println("max:\t" + getMaxRes(l2)); ERRORE
        System.out.println("-------");

        List<Armadio> l3 = new ArrayList<>();
        l3.add(a1);
        l3.add(a2);
        System.out.println("max:\t" + getMax(l3));
        // System.out.println("max:\t" + getMaxRes(l3)); ERRORE

    }
}
