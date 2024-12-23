
public class Carote extends Pietanza {

    private Boolean prezzemolo;

    public Carote(int c) {
        calorie = c;
        prezzemolo = false;
    }

    public void configuraPrezzemolo(Boolean pre) {
        prezzemolo = pre;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);
    }

}
