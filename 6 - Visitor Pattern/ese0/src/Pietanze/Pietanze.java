package Pietanze;

import Visitor.Visitor;

public class Pietanze implements Comparable<Pietanze> {

    private int calorie;

    public Pietanze(int c) {
        calorie = c;
    }

    public int getCalorie() {
        return this.calorie;
    }

    // IMPORTANTE: utilizzando i visitor sulle pietanze deve essere presente un
    // metodo che ACCETTI il visitor
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }
    // NB: questo metodo qui sopra NECESSITA di essere OVERRIDE nella classi
    // figlie!!

    @Override
    public int compareTo(Pietanze o) {
        return this.calorie - o.calorie;
    }

    @Override
    public String toString()
    {
        StringBuilder s = new StringBuilder();
        s.append("cal: ").append(calorie).append(" ");
        return s.toString();
    }

}
