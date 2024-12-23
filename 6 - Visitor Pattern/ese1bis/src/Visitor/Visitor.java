package Visitor;

import Animali.Animale;
import Animali.Pesce;

//Utilizziamo le interfacce e non le classi astratte
//Come prima cosa scriviamo Visitor e Visitable

//Visitor contiene i metodi VISIT generici per le classi di oggetti che andremo ad usare 

public interface Visitor<T> {

    public T visit(Animale e);

    public T visit(Pesce e);

}