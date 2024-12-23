/*  TE 5/04/2023
    ES.5 JAVA GENERICS  
*/

import Dizionario.Dizionario;
import Persone.Studente;

public class App {
    public static void main(String[] args) throws Exception {
        Dizionario<Integer, Character> d = new Dizionario<>();
        d.aggiungi(1, 'a');
        d.aggiungi(1, 'a');
        d.aggiungi(1, 'b');
        d.aggiungi(2, 'a');
        d.aggiungi(3, 'c');

        System.out.println(d.restituisci(1));
        System.out.println(d.restituisci(2));
        System.out.println(d.restituisci(3));

        Dizionario<Studente, Integer> diz = new Dizionario<>();

        Studente s = new Studente("gab", "mor", "345", 25);
        Studente s2 = new Studente("pao", "oll", "245", 30);

        diz.aggiungi(s, s.getVotoPA());
        diz.aggiungi(s2, s2.getVotoPA());

        System.out.println(diz.restituisci(s));
        System.out.println(diz.restituisci(s2));
    }
}

// Puoi creare un Dizionario<Studente, Integer> anche se Studente non ha un
// suo metodo compareTo, perché eredita il metodo compareTo dalla classe
// Persona. Questo soddisfa i requisiti del tipo T nella classe Dizionario,
// permettendoti di usare Studente come chiave nel dizionario. Solo se in
// Dizionario implementiamo in modo corretto Comparable, ovvero con <? super T>.
// Senza questo non avrebbe funzionato!!
