package Visitor;

import Mobili.*;

public interface Visitor<T> {
    public T visit(Mobile o);

    public T visit(Armadio o);

    public T visit(Tavolo o);
}
