/*  TE 25/01/2024
    ES.5 JAVA GENERICS  
*/

import Carrozza.Carrozza;
import Passeggero.Animale;
import Passeggero.Passeggero;

public class App {
    public static void main(String[] args) throws Exception {
        Animale a1 = new Animale("muuu", "VA");
        Animale a2 = new Animale("lara", "CA");
        Animale a3 = new Animale("mufasa", "LE");
        Animale a4 = new Animale("spirit", "CA");

        Passeggero p1 = new Passeggero("gabri");
        Passeggero p2 = new Passeggero("paolo");
        Passeggero p3 = new Passeggero("cassi");
        Passeggero p4 = new Passeggero("pippo");

        Animale[] vet_a = { a1, a2, a3 };
        Passeggero[] vet_p = { p1, p2 };

        Carrozza<Animale> c1 = new Carrozza<Animale>(vet_a);

        Carrozza<Passeggero> c2 = new Carrozza<Passeggero>(vet_p);

        System.out.println(c1.toString());
        System.out.println(c2.toString());

        c1.insert(a3);
        System.out.println(c1.toString());
        c1.insert(a4);
        System.out.println(c1.toString());

        // è possibile inserire in una carrozza animali anche dei passeggeri
        c1.insert(p1);
        c1.insert(p2);
        System.out.println(c1.toString());

        // NB: non è possibile inserire in una carrozza passegeri un animale
        // c2.insert(a1);

        // Così come non è possibile assegnare ad una carrozza Passeggeri una carrozza
        // Animali
        // Carrozza<Passeggero> c3 = new Carrozza<Animale>();

        // NB: Nemmeno questo è possibile!!!
        // Carrozza<Animale> c3 = new Carrozza<Passeggero>();

        // c1 = c2; // ERRORE

        // Invarianza dei Generics
        // In Java, i generics non sono covarianti, il che significa che se hai due tipi
        // A e B dove B è un sottotipo di A, non puoi dire che Carrozza<B> è un
        // sottotipo di Carrozza<A>. Anche se Passeggero è un sottotipo di Animale,
        // Carrozza<Passeggero> non è un sottotipo di Carrozza<Animale>.

        // Problema: Potrei voler inserire un animale in c3 ma questo a runtime è di
        // tipo passeggero. Non posso farlo. Java da subito errore in modo da evitare
        // questo problema a runtime


        Carrozza<? super Passeggero> c3 = new Carrozza<Animale>();
        Carrozza<? extends Animale> c4 = new Carrozza<Passeggero>();

        // c3.insert(a1); ERRORE
        // Inserire un Animale in c3 potrebbe essere pericoloso perché
        // Carrozza<? super Passeggero> potrebbe essere assegnata a una
        // Carrozza<Passeggero>. Consentire l'inserimento di un Animale in una
        // Carrozza<Passeggero> sarebbe incoerente. Si torna al problema scritto sopra
        // c2.insert(a1);

        // Posso invece inserire dei passeggeri dato che minimo c3 sarà passeggero. Nel
        // caso c3 sia animali invece abbiamo visto sopra che posso inserire Passeggeri
        // in carrozze Animali
        c3.insert(p1);
        System.out.println(c3.toString());

        // c4.insert(a1); Problema simile a sopra ma non posso inserire nulla in
        // entrambi i casi perchè a priori il compilatore non sa cosa possa essere c4
        // (con c3 sapeva che minimo sarebbe stato Passeggero)

        // questo lo posso fare
        c3 = c1;
        c3 = c2;
        c4 = c1;
        c4 = c2;
    }
}
