package Mobile;

import Visitor.Visitable;
import Visitor.Visitor;

public class Mobile implements Comparable<Mobile>, Visitable {

    private String nome;

    public Mobile(String n) {
        nome = n;
    }

    @Override
    public int compareTo(Mobile o) {
        return nome.compareTo(o.nome);
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

    @Override
    public String toString() {
        return nome;
    }

}
