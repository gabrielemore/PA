package Visitor;

import Animale.Animale;
import Animale.Pesce;

//Qui al posto di T inserisco il tipo ritornato dal metodo

public class getNuota extends Visitor<String> {

    @Override
    public String visit(Animale m) {
        if (m.getNuota())
            return "NUOTA";
        else
            return "NON NUOTA";
    }

    @Override
    public String visit(Pesce m) {
        if (m.getNuota())
            return "NUOTA";
        else
            return "NON NUOTA";
    }

}
