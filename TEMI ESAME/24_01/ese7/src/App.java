import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import Cibo.*;
import Visitor.*;

public class App {
    public static void main(String[] args) throws Exception {
        Pietanze p1 = new Agnello(200, 100);
        Pietanze p2 = new Agnello(240, 140);
        Pietanze p3 = new Carote(25);
        Pietanze p4 = new Carote(15);

        List<Pietanze> l = new ArrayList<>();
        l.add(p1);
        l.add(p2);
        l.add(p3);
        l.add(p4);
        System.out.println(l);
        Collections.sort(l);
        System.out.println(l);

        Visitor<String> v_it = new getMenuIT();
        Visitor<String> v_en = new getMenuEN();
        Visitor<Integer> v_cal = new getCalorie();

        System.out.println(p1.accept(v_it));
        System.out.println(p1.accept(v_en));
        System.out.println(p3.accept(v_cal));
        System.out.println(p4.accept(v_cal));


    }
}
