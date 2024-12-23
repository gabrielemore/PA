package Cibo;

import Visitor.Visitable;

public abstract class Pietanze implements Visitable, Comparable<Pietanze> {

    int calorie;

    public int getCalorie() {
        return calorie;
    }

    @Override
    public int compareTo(Pietanze o) {
        return calorie - o.calorie;
    }
}
