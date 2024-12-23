package Persone;

// ATTENZIONE a come viene effettuato il comparable
public class Persona implements Comparable<Persona> {

    private String nome;
    private String cognome;
    private String CF;

    public Persona(String n, String l, String cf) {
        this.nome = n;
        this.cognome = l;
        this.CF = cf;
    }

    @Override
    // ATTENZIONE ovveride del metodo compareTo dato che si implementa la comparable
    public int compareTo(Persona o) {
        // andiamo ad utilizzare il compareto delle stringhe in questo modo
        return this.CF.compareTo(o.CF);
    }

}
