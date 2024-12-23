package Animale;

import Visitor.Visitor;

public class Pesce extends Animale{

    public Pesce()
    {
        super(true);
    }

    // Nelle classi figlie devo fare override del metodo accept
    @Override
    public <T> T accept(Visitor<T> v)
    {
        return v.visit(this);
    }

    
    
}
