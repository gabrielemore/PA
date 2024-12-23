package Treni;

import Visitor.Visitable;
import Visitor.Visitor;

public class AltaVelocita implements Visitable, Comparable<AltaVelocita> {

    private String partenza;
    private String destinazione;
    private int numPasseggeriCorsa;

    public AltaVelocita(String p, String d, int n) {
        this.partenza = p;
        this.destinazione = d;
        if (n < 101)
            this.numPasseggeriCorsa = n;
        else
            this.numPasseggeriCorsa = 100;
    }

    public String getPartenza() {
        return partenza;
    }

    public String getDestinazione() {
        return destinazione;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

    @Override
    public int compareTo(AltaVelocita o) {
        return this.numPasseggeriCorsa - o.numPasseggeriCorsa;
    }

    @Override
    public String toString()
    {
        StringBuilder s = new StringBuilder();
        s.append(this.partenza).append("-").append(destinazione).append("\t").append(numPasseggeriCorsa);
        return s.toString();
    }

}
