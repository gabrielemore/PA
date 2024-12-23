package Passeggero;

public class Animale {

    private String nome;
    private String specie;

    public Animale(String n, String sp)
    {
        this.nome = n;
        this.specie = sp;
    }

    @Override
    public String toString()
    {
        StringBuilder s = new StringBuilder();
        s.append(specie).append("-").append(nome);
        return s.toString();
    }
    
}
