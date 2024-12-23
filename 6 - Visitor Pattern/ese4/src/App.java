/*  TE 01/2022
    ES.6 VISITOR PATTERN  
*/

import java.util.ArrayList;
import java.util.List;

import Pasto.*;
import Visitor.Visitor;
import Visitor.getCosto;
import Visitor.getOrario;

public class App {

    public static int sommaCosto(List<Pasto> l, Visitor<Integer> v) {
        int ret = 0;
        for (Pasto p : l) {
            ret += p.accept(v);
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        Pasto p1 = new Pranzo();
        Pasto p2 = new Cena();
        Pasto p3 = new Pranzo();
        Pasto p4 = new Cena();
        Pasto p5 = new Cena();
        Pasto p6 = new Cena();

        Visitor<Integer> v_p = new getCosto();
        Visitor<Integer> v_o = new getOrario();

        System.out.println("Costo:\t" + p1.accept(v_p) + "\n" + "Orario:\t" + p1.accept(v_o) + "\n");
        System.out.println("Costo:\t" + p6.accept(v_p) + "\n" + "Orario:\t" + p6.accept(v_o) + "\n");

        List<Pasto> list = new ArrayList<>();
        list.add(p1);
        list.add(p2);
        list.add(p3);
        list.add(p4);
        list.add(p5);
        list.add(p6);

        System.out.println("Costo totale:\t" + sommaCosto(list, v_p));
        

    }
}
