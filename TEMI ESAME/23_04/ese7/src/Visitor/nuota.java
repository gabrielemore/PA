package Visitor;

import Animali.Animale;
import Animali.Pesce;

public class nuota implements Visitor<String> {

    @Override
    public String visit(Animale o) {
        if (o.getNuota())
            return "NUOTA";
        else
            return "NON NUOTA";
    }

    @Override
    public String visit(Pesce o) {
        return "NUOTA";
    }

}
