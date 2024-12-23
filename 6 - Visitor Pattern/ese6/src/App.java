/*  TE 11/2020
    ES.6 VISITOR PATTERN  
*/

import java.util.ArrayList;
import java.util.List;

import Edilizia.*;
import Visitor.*;

public class App {

    public static int sommaCosto(List<InterventoEdilizio> l, Visitor<Integer> v) {
        int ret = 0;
        for (InterventoEdilizio e : l) {
            ret += e.accept(v);
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        Visitor<Integer> v = new getCosto();

        InterventoEdilizio rip1 = new Riparazione(); // 100
        InterventoEdilizio rip2 = new Riparazione(); // 100

        List<InterventoEdilizio> l_r1 = new ArrayList<>(); // 200 (con sommaCosto e l_r1 non ho commissione del 15%. Ho
                                                           // due interventi singoli da 100)
        l_r1.add(rip1);
        l_r1.add(rip2);

        InterventoEdilizio ris1 = new Ristrutturazione(l_r1); // 230 (i due interventi sono diventati una
                                                              // ristrutturazione. Ho commisione del 15% sulla loro
                                                              // somma)

        List<InterventoEdilizio> l_r2 = new ArrayList<>(); // 430 (ho una ristrutturazione con due interventi = 230 e
                                                           // due interventi singoli = 100 + 100)
        l_r2.add(ris1);
        l_r2.add(rip1);
        l_r2.add(rip2);

        InterventoEdilizio ris2 = new Ristrutturazione(l_r2); // 460 (ho una ristrutturazione e due interventi che
                                                              // diventato un unica ristrutturazione. NB: Non calcolo
                                                              // doppia commisione sulla ristrutturazione)

        System.out.println(rip1.accept(v)); // 100

        System.out.println(ris1.accept(v)); // 230

        System.out.println(sommaCosto(l_r1, v)); // 200

        System.out.println(ris2.accept(v)); // 460

        System.out.println(sommaCosto(l_r2, v)); // 430

    }
}
