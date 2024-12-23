package Edilizia;

import java.util.ArrayList;
import java.util.List;

import Visitor.Visitor;

public class Ristrutturazione extends InterventoEdilizio {

    private List<InterventoEdilizio> l;

    public Ristrutturazione(List<InterventoEdilizio> l) {
        this.l = new ArrayList<>();
        for (InterventoEdilizio e : l) {
            this.l.add(e);
        }
    }

    public List<InterventoEdilizio> getListaInterventi() {
        return this.l;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
