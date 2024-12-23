package Mobili;

import Visitor.Visitor;

public class Armadio extends Mobile {

    public Armadio(String n) {
        super(n);
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
