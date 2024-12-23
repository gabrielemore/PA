package Visitor;

import Pasto.*;

public interface Visitor<T> {
    public T visit(Pranzo o);

    public T visit(Cena o);

    public T visit(Pasto o);
}
