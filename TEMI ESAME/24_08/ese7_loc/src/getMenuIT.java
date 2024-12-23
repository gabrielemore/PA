
public class getMenuIT implements Visitor<String> {

    @Override
    public String visit(Agnello o) {
        return "Agnello";
    }

    @Override
    public String visit(Carote o) {
        return "Carote";
    }

}
