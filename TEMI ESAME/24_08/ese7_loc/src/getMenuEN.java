
public class getMenuEN implements Visitor<String> {

    @Override
    public String visit(Agnello o) {
        return "Lamb";
    }

    @Override
    public String visit(Carote o) {
        return "Carrot";
    }

}
