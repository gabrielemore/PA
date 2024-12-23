package Visitor;

import Carichi.*;

public interface Visitor<T> {

    public <E extends Comparable<E>> T visit(Singolo<E> o);

    public <E extends Comparable<E>> T visit(Doppio<E> o);

    public <E extends Comparable<E>> T visit(DieciCarichi<E> o);

}
