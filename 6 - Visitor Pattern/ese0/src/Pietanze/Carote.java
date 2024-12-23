package Pietanze;

import Visitor.Visitor;

public class Carote extends Pietanze {

    public Carote(int c) {
        super(c);
    }

    // IMPORTANTE: override del metodo accept nelle classi figlie
    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

    public void configuraPrezzemolo(Boolean prezzemolo) {
        // ...//
    }

}
