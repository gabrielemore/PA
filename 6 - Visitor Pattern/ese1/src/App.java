/*  TE 04/2023
    ES.6 VISITOR PATTERN  
*/

import java.util.ArrayList;
import java.util.List;

import Animale.Animale;
import Animale.Pesce;
import Visitor.Visitor;
import Visitor.contaPesce;
import Visitor.getNuota;

public class App {
    public static void main(String[] args) throws Exception {

        Animale a1 = new Animale(true);
        Animale a2 = new Animale(false);

        Pesce p1 = new Pesce();
        Pesce p2 = new Pesce();

        Visitor<String> v_s = new getNuota();

        System.out.println(a1.accept(v_s));
        System.out.println(a2.accept(v_s));
        System.out.println(p1.accept(v_s));
        System.out.println(p2.accept(v_s));

        List<Animale> list = new ArrayList<>();

        list.add(a1);
        list.add(a2);
        list.add(p1);
        list.add(p2);
        
        System.out.println(contaPesciLista(list));

    }

    public static int contaPesciLista(List<Animale> l)
    {
        Visitor<Integer> v_i = new contaPesce();
        int ret = 0;
        for( Animale e: l)
        {
            ret += e.accept(v_i);
        }
        return ret;
    }
}
