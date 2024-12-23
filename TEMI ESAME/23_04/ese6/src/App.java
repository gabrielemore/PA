import Persone.Studente;

public class App {
    public static void main(String[] args) throws Exception {
        Dizionario<Integer, String> diz = new Dizionario<>();
        diz.add(1, "a");
        diz.add(1, "b");
        diz.add(2, "a");
        diz.add(3, "c");

        System.out.println(diz.get(2));

        // se Dizionario è dichiarato così
        // -> public class Dizionario<T extends Comparable<T>, E>
        // non posso farlo

        // se invece è dichiarato cosi' si
        // ->public class Dizionario<T extends Comparable<? super T>, E>
        Dizionario<Studente, Integer> dizStud = new Dizionario<>();

        Studente s1 = new Studente("paolo");
        Studente s2 = new Studente("pippo");
        Studente s3 = new Studente("cassi");

        dizStud.add(s1, 30);
        dizStud.add(s2, 22);
        dizStud.add(s3, 24);

        System.out.println(dizStud.get(s2));

    }
}
