package Visitor;

import Pietanze.Agnello;
import Pietanze.Carote;
import Pietanze.Pietanze;

//questa classe deve ESTENDERE la classe astratta VISITOR creata precedentemente
public class getCalorie extends Visitor<Integer> {

    // dobbiamo implementare tutti i metodi scritti nella classe astratta
    // (possibile eseguire il quick fix per far scrivere in automatico la base di
    // quanto segue)

    @Override
    public Integer visit(Pietanze m) {
        // All'interno di ogni metodo implemento il codice necessario per eseguire
        // quanto richiesto. In questo caso getCalorie

        return m.getCalorie();

        // NB: il campo calorie dell'oggetto è private. Devo quindi all'interno della
        // classe avere un metodo get per ottenere quel campo
    }

    @Override
    public Integer visit(Agnello m) {
        return m.getCalorie();
    }

    @Override
    public Integer visit(Carote m) {
        return m.getCalorie();
    }

}
