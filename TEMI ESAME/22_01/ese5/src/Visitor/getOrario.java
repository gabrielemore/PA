package Visitor;

import Pasto.Cena;
import Pasto.Pasto;
import Pasto.Pranzo;

public class getOrario implements Visitor<String> {

    @Override
    public String visit(Pranzo o) {
        return "Ore:\t12.00";
    }

    @Override
    public String visit(Cena o) {
        return "Ore\t20.00";
    }

    @Override
    public String visit(Pasto o) {
        return "";
    }

}
