package Visitor;

import Treni.AltaVelocita;
import Treni.Interegionali;
import Treni.Locali;

public class getFermate implements Visitor<String> {

    @Override
    public String visit(AltaVelocita t) {
        StringBuilder s = new StringBuilder();
        s.append("AV - ").append(t.getPartenza()).append("\n").append("AV - ").append(t.getDestinazione());
        return s.toString();
    }

    @Override
    public String visit(Interegionali t) {
        StringBuilder s = new StringBuilder();
        s.append("I - ").append(t.getPartenza()).append("\n");
        for (String str : t.getFermateIntermedie()) {
            s.append("I - ").append(str).append("\t");
        }
        s.append("\nI - ").append(t.getDestinazione());
        return s.toString();
    }

    @Override
    public String visit(Locali t) {
        StringBuilder s = new StringBuilder();
        s.append("L - ").append(t.getPartenza()).append("\n");
        for (String str : t.getFermateIntermedie()) {
            s.append("L - ").append(str).append("\t");
        }
        s.append("\nL - ").append(t.getDestinazione());
        return s.toString();
    }

}
