package Carichi;

import java.util.ArrayList;
import java.util.List;

import Visitor.Visitor;

public class DieciCarichi<E extends Comparable<E>> extends Carico<E> {

    private List<Carico<E>> list10;

    public DieciCarichi(List<Carico<E>> l) {
        int c = 0;
        this.list10 = new ArrayList<Carico<E>>();
        for (Carico<E> e : l) {
            if (c < 10)
                this.list10.add(e);
            c++;
        }
    }

    public List<Carico<E>> getList() {
        return this.list10;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
