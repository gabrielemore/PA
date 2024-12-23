package Persone;

public class Persona implements Comparable<Persona> {

    private String nome;

    public Persona(String n) {
        nome = n;
    }

    @Override
    public int compareTo(Persona o) {
        return nome.compareTo(o.nome);
    }

}
