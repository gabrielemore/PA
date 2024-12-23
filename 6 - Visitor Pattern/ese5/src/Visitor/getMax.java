package Visitor;

import java.util.List;

import Carichi.Carico;
import Carichi.DieciCarichi;
import Carichi.Doppio;
import Carichi.Singolo;

public class getMax<T extends Comparable<T>> implements Visitor<T> {

    @Override
    public <E extends Comparable<E>> T visit(Singolo<E> o) {
        return (T) o.getVal();
    }

    @Override
    public <E extends Comparable<E>> T visit(Doppio<E> o) {
        E t1 = o.getVal1();
        E t2 = o.getVal2();
        if (t1.compareTo(t2) > 0)
            return (T) t1;
        else
            return (T) t2;
    }

    @Override
    public <E extends Comparable<E>> T visit(DieciCarichi<E> o) {
        List<Carico<E>> list = o.getList();
        Singolo<E> appS;
        Doppio<E> appD;
        T max = null, confMax = null;

        if (list.get(0) instanceof Singolo) {
            appS = (Singolo<E>) list.get(0);
            max = visit(appS); // ret Max di un carico singolo
        } else if (list.get(0) instanceof Doppio) {
            appD = (Doppio<E>) list.get(0);
            max = visit(appD); // ret Max di un carico doppio
        }

        for (Carico<E> e : o.getList()) {
            if (e instanceof Singolo) {
                appS = (Singolo<E>) e;
                confMax = visit(appS);
            } else if (e instanceof Doppio) {
                appD = (Doppio<E>) e;
                confMax = visit(appD);
            }

            if (max.compareTo(confMax) < 0)
                max = confMax;
        }

        return max;

    }

}
