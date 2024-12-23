package Visitor;

import Animale.Animale;
import Animale.Pesce;

public abstract class Visitor<T> {

    public abstract T visit(Animale m);

    public abstract T visit(Pesce m);
}
