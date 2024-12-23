package Visitor;

import Pasto.*;

public interface Visitor<T> {
    public T visit(Cena t);

    public T visit(Pranzo t);
}
