package Visitor;

import Pasto.Cena;
import Pasto.Pranzo;

public class getCosto implements Visitor<Integer> {

    @Override
    public Integer visit(Cena t) {
        return 20;
    }

    @Override
    public Integer visit(Pranzo t) {
        return 10;
    }

}
