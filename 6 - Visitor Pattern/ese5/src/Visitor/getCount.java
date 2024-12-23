package Visitor;

import Carichi.*;

public class getCount implements Visitor<Integer> {

    @Override
    public <E extends Comparable<E>> Integer visit(Singolo<E> o) {
        return 1;
    }

    @Override
    public <E extends Comparable<E>> Integer visit(Doppio<E> o) {
        return 2;
    }

    @Override
    public <E extends Comparable<E>> Integer visit(DieciCarichi<E> o) {
        int count = 0;
        for (Carico<E> e : o.getList()) {
            if (e instanceof Singolo)
                count++;
            else if (e instanceof Doppio)
                count += 2;
        }
        return count;
    }

}
