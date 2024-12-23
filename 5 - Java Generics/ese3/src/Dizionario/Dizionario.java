package Dizionario;

import java.util.ArrayList;

// ATTENZIONE al fatto che T debba estendere comparable e che anche comparable
// deve essere parametrizzato con T!!!

// NB: con Comparable<T> -> T deve essere comparable e implementare quindi compareTo.
// NON basta che una sua classe superiore sia comparable (es. Studente e
// Persona). Per fare in modo che basti che una sua classe qualunque superiore 
// sia comparable allora devo usare Comparable<? super T>. Significa che ad
// essere comparable deve essere T o qualunque suo super tipo (classe
// superiore). Il contrario di super è extends. <? extends T> significava T o
// una qualunque sottoclasse di T deve implementare comparable.

public class Dizionario<T extends Comparable<? super T>, S> {

    private ArrayList<T> chiave;
    private ArrayList<S> valore;

    public Dizionario() {
        this.chiave = new ArrayList<>();
        this.valore = new ArrayList<>();
    }

    public Dizionario(T c, S v) {
        this.chiave = new ArrayList<>();
        this.valore = new ArrayList<>();

        this.chiave.add(c);
        this.valore.add(v);
    }

    public void aggiungi(T c, S v) {
        // due casi
        // chiave gia presente allora aggiorno solo il valore
        if (this.chiave.contains(c)) {
            // per settare un valore in un arraylist ad un certo indice
            this.valore.set(this.chiave.indexOf((c)), v);
        }
        // chiave non presente aggiugno chiave e valore
        else {
            this.chiave.add(c);
            this.valore.add(v);
        }
    }

    public S restituisci(T c) {
        S ret = null;
        if (this.chiave.contains(c)) {
            // per settare un valore in un arraylist ad un certo indice
            ret = this.valore.get(this.chiave.indexOf((c)));
        }
        return ret;
    }
}
