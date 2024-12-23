package Visitor;

import Cibo.Agnello;
import Cibo.Carote;

public class getMenuEN implements Visitor<String> {

    @Override
    public String visit(Agnello o) {
        return "LAMB";
    }

    @Override
    public String visit(Carote o) {
        return "CARROT";
    }

}
