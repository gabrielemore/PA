/*  TE 25/01/2024
    ES.6 VISITOR PATTERN  
*/

import java.util.ArrayList;
import java.util.Collections;

import Treni.AltaVelocita;
import Treni.Interegionali;
import Treni.Locali;
import Visitor.Visitor;
import Visitor.getFermate;
import Visitor.getMaxPasseggeri;

// Si poteva fare in modo diverso (probabilmente piu coerente con la consegna)
// Si crea l'oggetto Corsa e si assegna una particolare corsa ad un Treno
// All'interno di Corsa, oltre alle fermate, è presente anche il numeroTotalePersoneCorsa
// Non è da fare sali scendi dalle fermate

// Altra cosa interessante da fare: Si poteva creare la classe Treno ASTRATTA ed estendere questa
// per AV L e I

// Non è comunque del tutto sbagliato. AL posto di inviare una Corsa a Treno per costruire l'oggetto
// mando i singoli campi che costituirebbero l'oggetto Corsa

public class App {
    public static void main(String[] args) throws Exception {
        AltaVelocita a1 = new AltaVelocita("BERGAMO", "ROMA", 78);
        AltaVelocita a2 = new AltaVelocita("MILANO", "NAPOLI", 45);
        AltaVelocita a3 = new AltaVelocita("TORINO", "FIRENZE", 89);

        ArrayList<String> sta_int_i = new ArrayList<>();
        sta_int_i.add("STEZZANO");
        sta_int_i.add("DALMINE");
        sta_int_i.add("ZINGONIA");
        sta_int_i.add("GORGONZOLA");
        sta_int_i.add("CINISELLO");

        Interegionali i1 = new Interegionali("BERGAMO", "MILANO", 34, sta_int_i);

        ArrayList<String> sta_int_l = new ArrayList<>();
        sta_int_l.add("STEZZANO");
        sta_int_l.add("DALMINE");
        sta_int_l.add("ZINGONIA");

        Locali l1 = new Locali("BERGAMO", "TREVIGLIO", 10, sta_int_l);

        Visitor<String> v_s = new getFermate();
        Visitor<Integer> v_i = new getMaxPasseggeri();

        // STAMPA FERMATE
        System.out.println(a1.accept(v_s));
        System.out.println(a3.accept(v_s));

        System.out.println(i1.accept(v_s));

        System.out.println(l1.accept(v_s));

        // STAMPA MAX PASSEGGERI

        System.out.println(a2.accept(v_i));
        System.out.println(i1.accept(v_i));
        System.out.println(l1.accept(v_i));

        // SECONDA PARTE
        ArrayList<AltaVelocita> l_t = new ArrayList<>();

        l_t.add(a1);
        l_t.add(a2);
        l_t.add(a3);
        l_t.add(i1);
        l_t.add(l1);

        System.out.println(l_t);

        Collections.sort(l_t);

        System.out.println(l_t);

        // TERZA PARTE

        ArrayList<Interegionali> l_i = new ArrayList<>();

        // ERRORE IN ENTRAMBI I CASI. NON C'E' COVARIANZA
        // l_t = l_i;
        // l_i = l_t;
        // NONOSTANTE Interegionali sia sottotipo di AltaVelocita
        // List<Interegionali> NON E' sottotipo di List<AltaVelocita>

    }
}
