
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class App {

    public static void main(String[] args) throws Exception {
        Agnello p1 = new Agnello(230, 80);
        Carote p2 = new Carote(80);
        Agnello p3 = new Agnello(430, 180);
        Agnello p4 = new Agnello(200, 50);
        Carote p5 = new Carote(35);

        Visitor<String> v_m_it = new getMenuIT();
        Visitor<String> v_m_en = new getMenuEN();
        Visitor<Integer> v_c = new getCalorie();

        //PUNTO A MENU IT+EN + CALORIE
        System.out.println(p1.accept(v_m_it) + ": " + p1.accept(v_c));
        System.out.println(p1.accept(v_m_en) + ": " + p1.accept(v_c));

        System.out.println(p5.accept(v_m_it) + ": " + p5.accept(v_c));
        System.out.println(p5.accept(v_m_en) + ": " + p5.accept(v_c));

        //PUNTO B
        //Lista pietanze
        List<Pietanza> l = new ArrayList<>();
        l.add(p1);
        l.add(p2);
        l.add(p3);
        l.add(p4);
        l.add(p5);
        //ordine in base alle calorie
        System.out.println("Pietanze non ordinate:\t" + l);
        Collections.sort(l);
        System.out.println("Pietanze ordinate:\t" + l);

        //PUNTO C
        List<Agnello> l_a = new ArrayList<>();
        l_a.add(p1);
        l_a.add(p3);
        l_a.add(p4);

        // Non c'è covarianza con i generics. Nonostante Agnello sia sottotipo di Pietanza, List<Agnello> non è sottotipo di List<Pietanza>.
        // Quindi questo non posso farlo:
        // List<Pietanza> test = l_a; //ERRORE
    }
}
