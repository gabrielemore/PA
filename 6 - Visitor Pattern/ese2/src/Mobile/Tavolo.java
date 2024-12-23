package Mobile;

import Visitor.Visitor;

public class Tavolo extends Mobile {

    public Tavolo(String m) {
        super(m);
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
    
}
