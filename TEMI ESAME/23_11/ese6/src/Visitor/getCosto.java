package Visitor;

import Mobile.Armadio;
import Mobile.Mobile;
import Mobile.Tavolo;

public class getCosto implements Visitor<Integer> {

    @Override
    public Integer visit(Mobile o) {
        return 100;
    }

    @Override
    public Integer visit(Tavolo o) {
        return 200;
    }

    @Override
    public Integer visit(Armadio o) {
        return 300;
    }

}
