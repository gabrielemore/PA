package Edilizia;

import Visitor.Visitor;

public class Riparazione extends InterventoEdilizio {

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
    
}
