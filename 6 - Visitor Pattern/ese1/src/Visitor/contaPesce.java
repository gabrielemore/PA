package Visitor;

import Animale.Animale;
import Animale.Pesce;

public class contaPesce extends Visitor<Integer>{

    @Override
    public Integer visit(Animale m) {
        return 0;
    }

    @Override
    public Integer visit(Pesce m) {
        return 1;
    }
    
}
