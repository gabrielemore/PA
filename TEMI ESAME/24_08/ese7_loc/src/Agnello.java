
public class Agnello extends Pietanza {

    private int peso;
    private String cottura;

    public Agnello(int c, int p) {
        calorie = c;
        peso = p;
        cottura = "NON SELEZIONATA";
    }

    public void configuraCottura(String cotturaSelezionata) {
        cottura = cotturaSelezionata;
    }

    @Override
    public <T> T accept(Visitor<T> v) {
        return v.visit(this);

    }

}
