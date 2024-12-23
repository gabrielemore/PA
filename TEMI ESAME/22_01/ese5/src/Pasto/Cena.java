package Pasto;

import Visitor.Visitor;

public class Cena extends Pasto {

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
