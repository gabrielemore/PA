package Visitor;

import Animali.*;

public interface Visitor<T> {

    public T visit(Animale o);

    public T visit(Pesce o);

}
