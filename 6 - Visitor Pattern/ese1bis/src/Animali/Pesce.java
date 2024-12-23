package Animali;

import Visitor.Visitor;

public class Pesce extends Animale {
    
    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
}
