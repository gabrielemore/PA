package Visitor;

import Pietanze.Agnello;
import Pietanze.Carote;
import Pietanze.Pietanze;

public class getMenuEN extends Visitor<String> {

    @Override
    public String visit(Pietanze m) {
        return "Food";
    }

    @Override
    public String visit(Agnello m) {
        return "Lamb";
    }

    @Override
    public String visit(Carote m) {
        return "Carrots";
    }
    
}
