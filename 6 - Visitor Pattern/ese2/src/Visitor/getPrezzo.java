package Visitor;

import Mobile.Armadio;
import Mobile.Mobile;
import Mobile.Tavolo;

public class getPrezzo implements Visitor<Integer>{

    @Override
    public Integer visit(Mobile m) {
        return 100;
    }

    @Override
    public Integer visit(Tavolo m) {
       return 200;
    }

    @Override
    public Integer visit(Armadio m) {
        return 300;
    }
    
}
