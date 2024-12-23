package Visitor;

import java.util.List;

import Edilizia.InterventoEdilizio;
import Edilizia.Riparazione;
import Edilizia.Ristrutturazione;

public class getCosto implements Visitor<Integer> {

    @Override
    public Integer visit(Riparazione o) {
        return 100;
    }

    @Override
    public Integer visit(Ristrutturazione o) {
        int sum = 0;
        List<InterventoEdilizio> l = o.getListaInterventi();
        for (InterventoEdilizio i : l) {
            if (i instanceof Riparazione)
                sum += Math.ceil(100 * 1.15);
            else
                sum += visit((Ristrutturazione) i);
        }

        return sum;

    }

}
