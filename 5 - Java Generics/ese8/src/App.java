/*  TE 02/2021
    ES.5 JAVA GENERICS  
*/

import Algoritmi.Algoritmi;
import Collezione.ListaComputer;
import Computer.Computer;
import Computer.Notebook;

public class App {
    public static void main(String[] args) throws Exception {
        ListaComputer<Computer> l_c = new ListaComputer<>();
        ListaComputer<Notebook> l_n = new ListaComputer<>();

        // giustamente NON posso usare classi che non siano sottoclassi di Computer
        // ListaComputer<String> l_s = new ListaComputer<>(); // ERRORE
        // ListaComputer<Object> l_o = new ListaComputer<>(); // ERRORE

        Computer c1 = new Computer(1);
        Computer c2 = new Computer(2);
        Computer c3 = new Computer(3);

        Notebook n1 = new Notebook(11);
        Notebook n2 = new Notebook(12);
        Notebook n3 = new Notebook(13);

        l_c.add(c1);
        l_c.add(c2);
        l_c.add(c3);

        System.out.println(Algoritmi.getFirst(l_c));

        // OK posso farlo
        l_c.add(n1);
        l_c.add(n2);
        l_c.add(n3);

        // l_n.add(c1); // ERRORE
        l_n.add(n3);
        l_n.add(n2);
        l_n.add(n1);

        System.out.println(Algoritmi.getFirst(l_n));

    }
}
