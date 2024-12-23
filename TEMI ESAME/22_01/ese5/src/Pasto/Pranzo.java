package Pasto;

import Visitor.Visitor;

public class Pranzo extends Pasto {

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
