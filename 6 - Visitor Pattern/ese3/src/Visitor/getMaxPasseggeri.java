package Visitor;

import Treni.AltaVelocita;
import Treni.Interegionali;
import Treni.Locali;

public class getMaxPasseggeri implements Visitor<Integer> {

    @Override
    public Integer visit(AltaVelocita t) {
        return 100;
    }

    @Override
    public Integer visit(Interegionali t) {
        return 150;
    }

    @Override
    public Integer visit(Locali t) {
        return 200;
    }

}
