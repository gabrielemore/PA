package Visitor;

import Pietanze.Agnello;
import Pietanze.Carote;
import Pietanze.Pietanze;

public class getMenuIT extends Visitor<String> {

    // qui si nota meglio l'utilità del pattern visitor. in getCalorie infatti
    // richimavo semplicemente un metodo che avevo gia implementato nella classe
    // pietanze. Se avessi voluto modificare il codice avrei dovuto modificare il
    // metodo nella classe Pietanze. Qui invece non tocco piu la classe ma modifico
    // getMenuIT

    @Override
    public String visit(Pietanze m) {
        return "Pietanze";
    }

    @Override
    public String visit(Agnello m) {
        return "Agnello";
    }

    @Override
    public String visit(Carote m) {
        return "Carote";
    }

}
