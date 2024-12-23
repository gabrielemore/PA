package Visitor;

import Mobile.*;

public interface Visitor<T> {

    public T visit(Mobile m);
    public T visit(Tavolo m);
    public T visit(Armadio m);
} 
