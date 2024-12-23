// ESERCIZIO 6: Overriding + Overloading

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class Persona {
    String cf;

    public Persona(String s) {
        cf = s;
    }

    public boolean equals(Persona p2) {
        return cf.equals(p2.cf);
    }

    @Override //del metodo equals della classe Object
    public boolean equals(Object p2) {
        if (this == p2)
            return true;
        if (p2 instanceof Persona) {
            return equals((Persona) p2);
        }
        return false;
    }

    @Override
    public int hashCode() {
        return cf.hashCode();
    }

    public static void main(String[] args) {
        Persona p1 = new Persona("GRG");
        Persona p2 = new Persona("ABB");
        //Questo utilizza direttamente l'equals della classe persona
        System.out.println(p1.equals(p2));
        List<Persona> cl = new ArrayList<>();
        cl.add(p1);
        cl.add(p2);
        Persona o2 = new Persona("ABB");
        //cl è un arrayList
        //(STATICO) il metodo contains di arrayList utilizza equals(object)
        //(DINAMICO) in run-time equals(Object) viene cercata a partire da Persona
        //Facendo l'override di equals(Object) nella classe Persona 
        //sono in grado di confrontare il codice fiscale con gli
        //elementi presenti in arrayList 
        System.out.println(cl.contains(o2));
        //anche qui concetto simile a sopra
        //"personalizzo" il metodo hashCode per la classe Persona
        //dato che questa viene utilizzata da HashSet
        HashSet<Persona> set = new HashSet<>();
        set.add(p1);
        set.add(p2);
        System.out.println(set.contains(o2));
    }
}