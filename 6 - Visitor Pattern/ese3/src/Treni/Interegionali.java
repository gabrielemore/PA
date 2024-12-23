package Treni;

import java.util.ArrayList;

import Visitor.Visitor;

public class Interegionali extends AltaVelocita {

    private ArrayList<String> fermateIntermedie;

    public Interegionali(String p, String d, int n_p, ArrayList<String> f_m) {
        super(p, d, n_p);
        this.fermateIntermedie = f_m;
    }

    public ArrayList<String> getFermateIntermedie() {
        return this.fermateIntermedie;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
