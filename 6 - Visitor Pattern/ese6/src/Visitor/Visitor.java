package Visitor;

import Edilizia.Riparazione;
import Edilizia.Ristrutturazione;

public interface Visitor<T> {

    public T visit(Riparazione o);

    public T visit(Ristrutturazione o);

}
