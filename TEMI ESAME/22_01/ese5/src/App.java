
import java.util.ArrayList;
import java.util.List;

import Pasto.*;
import Visitor.*;

public class App {

    public static int SommaCosto(List<? extends Pasto> l, Visitor<Integer> v) {
        int sum = 0;
        for (int i = 0; i < l.size(); i++) {
            sum += v.visit(l.get(i));
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        Pasto p1 = new Pranzo();
        Pasto p2 = new Cena();
        Pasto p3 = new Cena();
        Pasto p4 = new Cena();
        Pasto p5 = new Pranzo();
        Pasto p6 = new Pranzo();
        Pasto p7 = new Pranzo();
        Pasto p8 = new Cena();

        Visitor<Integer> v_costo = new getCosto();
        Visitor<String> v_orario = new getOrario();

        System.out.println(p2.accept(v_costo));
        System.out.println(p2.accept(v_orario));

        List<Pasto> lista = new ArrayList<>();

        lista.add(p1);
        lista.add(p2);
        lista.add(p3);
        lista.add(p4);
        lista.add(p5);
        lista.add(p6);
        lista.add(p7);
        lista.add(p8);

        System.out.println(SommaCosto(lista, v_costo));

        List<Cena> listaCena = new ArrayList<>();

        Cena c1 = new Cena();
        Cena c2 = new Cena();
        Cena c3 = new Cena();

        listaCena.add(c1);
        listaCena.add(c2);
        listaCena.add(c3);

        System.out.println(SommaCosto(listaCena, v_costo));

        List<Pranzo> listaPranzo = new ArrayList<>();

        Pranzo pp1 = new Pranzo();
        Pranzo pp2 = new Pranzo();

        listaPranzo.add(pp1);
        listaPranzo.add(pp2);

        System.out.println(SommaCosto(listaPranzo, v_costo));

    }
}
