package Treni;

import java.util.ArrayList;

import Visitor.Visitor;

public class Locali extends Interegionali {

    public Locali(String p, String d, int n_p, ArrayList<String> f_m) {
        super(p, d, n_p, f_m);
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
