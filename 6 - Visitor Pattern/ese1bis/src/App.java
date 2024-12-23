/*  TE 04/2023
    ES.6 VISITOR PATTERN  
*/

import java.util.ArrayList;
import java.util.List;

import Animali.Pesce;
import Animali.Animale;
import Visitor.Visitor;
import Visitor.isPesce;

public class App {

    public static int contaNuota(List<Animale> l) {
        int ret = 0;
        Visitor<Boolean> v_b = new isPesce();
        for (Animale e : l) {
            if (e.accept(v_b))
                ret++;
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        Animale a1 = new Animale();
        Animale a2 = new Animale();

        Pesce p1 = new Pesce();
        Pesce p2 = new Pesce();

        List<Animale> list = new ArrayList<>();

        list.add(a1);
        list.add(a2);
        list.add(p1);
        list.add(a2);

        System.out.println(contaNuota(list));
    }
}
