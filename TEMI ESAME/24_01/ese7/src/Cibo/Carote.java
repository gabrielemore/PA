package Cibo;

import Visitor.Visitor;

public class Carote extends Pietanze {

    boolean prezzemolo;

    public Carote(int c) {
        calorie = c;
    }

    public void configuraPrezzemolo(boolean p) {
        prezzemolo = p;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
    @Override
    public String toString()
    {
        return "CA: " + calorie;
    }

}
