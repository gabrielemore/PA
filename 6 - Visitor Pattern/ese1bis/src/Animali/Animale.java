package Animali;

import Visitor.Visitable;
import Visitor.Visitor;

//La classe padre implementerà l'interfaccia visitable

//questa classe o ogni sua sottoclasse dovrà fare override del metodo accept di Visitable

public class Animale implements Visitable {

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
