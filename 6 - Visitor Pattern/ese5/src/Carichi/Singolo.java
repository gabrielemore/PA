package Carichi;

import Visitor.Visitor;

public class Singolo<E extends Comparable<E>> extends Carico<E> {

    private E val;

    public Singolo(E v) {
        this.val = v;
    }

    public E getVal()
    {
        return this.val;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
