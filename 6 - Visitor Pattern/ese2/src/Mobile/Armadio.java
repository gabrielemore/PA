package Mobile;

import Visitor.Visitor;

public class Armadio extends Mobile {

    public Armadio(String m) {
        super(m);
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
