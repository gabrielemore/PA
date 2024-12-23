/*  TE 25/01/2024
    ES.6 VISITOR PATTERN  
*/

import java.util.ArrayList;
import java.util.List;

import Pietanze.Agnello;
import Pietanze.Carote;
import Pietanze.Pietanze;
import Visitor.Visitor;
import Visitor.getCalorie;
import Visitor.getMenuIT;

public class App {
    public static void main(String[] args) throws Exception {

        Carote c1 = new Carote(2);

        Pietanze p1 = new Pietanze(10);

        Agnello a1 = new Agnello(8, 3);

        // Per usare i vistor devo creare l'oggetto Visitor
        // Per usare un metodo in particolare inizializzo l'oggetto Visitor alla classe
        // (che estende visitor) che implementa il metodo

        // esempio: se voglio utilizzare getCalorie
        Visitor<Integer> v_cal = new getCalorie();

        // ogni oggetto che implementa visitor possiede il metodo Accept (VISITOR).
        // Allora mandiamo l'oggetto creato sopra a questo metodo di ogni oggetto creato
        // sopra

        // quindi c1 Accetta il Visitor getCalorie
        System.out.println(c1.accept(v_cal));
        System.out.println(p1.accept(v_cal));
        System.out.println(a1.accept(v_cal));

        // per il metodo GetMenuIT basta creare un altro oggetto Visitor inizializzato a
        // newCalorieIT e ripetere quanto fatto sopra con Accept etc..

        Visitor<String> v_men = new getMenuIT();

        System.out.println(c1.accept(v_men));
        System.out.println(p1.accept(v_men));
        System.out.println(a1.accept(v_men));

        // simile per getMenuEN

        // ...

        // SECONDA PARTE
        List<Pietanze> l = new ArrayList<>();
        l.add(a1);
        l.add(c1);
        l.add(p1);

        System.out.println(l.toString());

        l.sort(null);
        // oppure
        // Collections.sort(l);

        System.out.println(l.toString());

        List<Agnello> l_a = new ArrayList<>();
        l_a.add(a1);

        // l_a.add(c1); ERRORE
        // l_a.add(p1); ERRORE

        // l_a = l; ERRORE
        // l = l_a; ERRORE: non c'è covarianza

        // Anche se Agnello è sottotipo di Pietanze
        // List<Agnello> non è sottotipo di List<Pietanze>
        // perchè non c'è covarianza
    }
}
