package Animali;

import Visitor.Visitor;

public class Pesce extends Animale {

    public Pesce() {
        super(true);
        // TODO Auto-generated constructor stub
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
}
