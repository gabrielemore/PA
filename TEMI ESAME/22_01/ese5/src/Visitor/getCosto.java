package Visitor;

import Pasto.Cena;
import Pasto.Pasto;
import Pasto.Pranzo;

public class getCosto implements Visitor<Integer> {

    @Override
    public Integer visit(Pranzo o) {
        return 10;
    }

    @Override
    public Integer visit(Cena o) {
        return 20;
    }

    @Override
    public Integer visit(Pasto o) {
        if (o instanceof Pranzo)
            return visit((Pranzo) o);
        else
            return visit((Cena) o);

    }

}
