package Persone;

public class Studente extends Persona {

    private int votoPa;

    public Studente(String nome, String cognome, String CF, int votoPa) {
        // ATTENZIONE: per richimare il costruttore della classe "sopra" usiamo
        // super(campi costruttore)
        super(nome, cognome, CF);
        this.votoPa = votoPa;
    }

    public int getVotoPA() {
        return this.votoPa;
    }

}
