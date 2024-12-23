package Visitor;

import Cibo.Agnello;
import Cibo.Carote;

public class getCalorie implements Visitor<Integer> {

    @Override
    public Integer visit(Agnello o) {
        return o.getCalorie();
    }

    @Override
    public Integer visit(Carote o) {
        return o.getCalorie();
    }

}
