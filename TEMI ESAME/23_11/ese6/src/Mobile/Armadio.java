package Mobile;

import Visitor.Visitor;

public class Armadio extends Mobile {

    public Armadio(String n) {
        super(n);
        // TODO Auto-generated constructor stub
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
}
