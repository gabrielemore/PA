package Visitor;

import Treni.*;

public interface Visitor<T> {

    public T visit(AltaVelocita t);

    public T visit(Interegionali t);

    public T visit(Locali t);

}
