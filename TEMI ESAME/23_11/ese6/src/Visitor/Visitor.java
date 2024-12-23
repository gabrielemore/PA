package Visitor;

import Mobile.*;

public interface Visitor<T> {
    public T visit(Mobile o);

    public T visit(Tavolo o);

    public T visit(Armadio o);

}
