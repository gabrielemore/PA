
public abstract class Pietanza implements Visitable, Comparable<Pietanza> {

    protected int calorie;

    @Override
    public int compareTo(Pietanza o) {
        return this.calorie - o.calorie;
    }

    public int getCalorie() {
        return calorie;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append(calorie);
        return s.toString();
    }

}
