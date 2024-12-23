package Mobile;

import Visitor.Visitable;
import Visitor.Visitor;

//NB: se ho due implements da fare le separo con una virgola!!!
public class Mobile implements Visitable, Comparable<Mobile> {

    private String nome;

    public Mobile(String m) {
        this.nome = m;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

    @Override
    public int compareTo(Mobile o) {
        return this.nome.compareTo(o.nome);
    }

    @Override
    public String toString()
    {
        return this.nome;
    }

}
