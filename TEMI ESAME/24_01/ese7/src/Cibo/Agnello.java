package Cibo;

import Visitor.Visitor;

public class Agnello extends Pietanze {

    private int peso;
    private String cottura;

    public Agnello(int c, int p) {
        peso = p;
        calorie = c;
    }

    public void configuraCottura(String c) {
        cottura = c;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
    @Override
    public String toString()
    {
        return "AG: " + calorie;
    }

}
