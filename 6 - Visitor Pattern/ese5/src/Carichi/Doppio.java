package Carichi;

import Visitor.Visitor;

public class Doppio<E extends Comparable<E>> extends Carico<E> {

    private E val1;
    private E val2;

    public Doppio(E v1, E v2) {
        this.val1 = v1;
        this.val2 = v2;
    }

    public E getVal1()
    {
        return this.val1;
    }

    public E getVal2()
    {
        return this.val2;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
}
