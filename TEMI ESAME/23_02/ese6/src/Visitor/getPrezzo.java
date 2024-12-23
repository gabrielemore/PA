package Visitor;

import Mobili.Armadio;
import Mobili.Mobile;
import Mobili.Tavolo;

public class getPrezzo implements Visitor<Integer> {

    @Override
    public Integer visit(Mobile o) {
        return 100;
    }

    @Override
    public Integer visit(Armadio o) {
        return 300;
    }

    @Override
    public Integer visit(Tavolo o) {
        return 200;
    }

}
