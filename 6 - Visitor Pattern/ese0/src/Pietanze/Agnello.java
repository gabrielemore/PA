package Pietanze;

import Visitor.Visitor;

public class Agnello extends Pietanze {

    private int peso;

    public Agnello(int c, int p) {
        super(c);
        peso = p;
    }

    // IMPORTANTE: override del metodo accept nelle classi figlie
    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

    public void configuraCottura(String cotturaSelezionata) {
        // ...//
    }

}
