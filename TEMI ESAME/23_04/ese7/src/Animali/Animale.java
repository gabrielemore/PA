package Animali;

import Visitor.Visitable;
import Visitor.Visitor;

public class Animale implements Visitable {

    private Boolean nuota;

    public Animale(Boolean n) {
        nuota = n;
    }

    public Boolean getNuota() {
        return nuota;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
