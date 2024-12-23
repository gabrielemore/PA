package Visitor;

import Cibo.*;

public interface Visitor<T> {

    public T visit(Agnello o);

    public T visit(Carote o);

}
