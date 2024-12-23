package Visitor;

import Pietanze.Agnello;
import Pietanze.Carote;
import Pietanze.Pietanze;

// si parte con il definire la classe ASTRATTA Visitor che è generica in T
public abstract class Visitor<T> {

    // si definiscono i metodi (SEMPRE ABSTRACT) di visit per ogni oggetto che deve
    // essere visitato

    public abstract T visit(Pietanze m);

    public abstract T visit(Agnello m);

    public abstract T visit(Carote m);

    // si passa quindi all'implementazione dei metodi
    // creiamo un file.java per ogni "funzione" che dobbiamo eseguire
    // in questo caso abbiamo getCalorie, getMenuIT e getMenuEN
}
