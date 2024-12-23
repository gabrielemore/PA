package Animale;

import Visitor.Visitor;

public class Animale {

    private Boolean nuota;

    public Animale(Boolean nuota) {
        this.nuota = nuota;
    }

    public Boolean getNuota() {
        return this.nuota;
    }

    public <T> T accept(Visitor<T> v)
    {
        return v.visit(this);
    }

}
