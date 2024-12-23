import Animali.Animale;
import Animali.Pesce;
import Visitor.Visitor;
import Visitor.nuota;

public class App {
    public static void main(String[] args) throws Exception {
        Animale a1 = new Animale(false);
        Animale a2 = new Pesce();
        Animale a3 = new Animale(true);

        Visitor<String> v = new nuota();

        System.out.println(a1.accept(v));
        System.out.println(a2.accept(v));
        System.out.println(a3.accept(v));

    }
}
