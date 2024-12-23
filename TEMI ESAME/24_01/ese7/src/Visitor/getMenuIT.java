package Visitor;

import Cibo.Agnello;
import Cibo.Carote;

public class getMenuIT implements Visitor<String> {

    @Override
    public String visit(Agnello o) {
        return "AGNELLO";
    }

    @Override
    public String visit(Carote o) {
        return "CAROTE";
    }

}
